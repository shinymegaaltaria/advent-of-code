#include <iostream>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
struct maze_state{
    int x;
    int y;
    int keys;
};
int offset_x[4] = {0,0,-1,1};
int offset_y[4] = {-1,1,0,0};
bool operator<(const maze_state& m1, const maze_state& m2){
    if(m1.x == m2.x){
        if(m1.y == m2.y){
            return m1.keys < m2.keys;
        }
        else{
            return m1.y < m2.y;
        }
    }
    else{
        return m1.x < m2.x;
    }
}
int main(){
    ifstream mazein ("day18_in.txt");
    char maze[81][81];
    int start_X, start_Y;
    for(int i = 0 ; i < 81 ; i++){
        for(int j = 0 ; j < 81 ; j++){
            mazein >> maze[i][j];
            if(maze[i][j] == '@'){
                start_X = i;
                start_Y = j;
                maze[i][j] = '.';
            }
        }
    }
    map <maze_state, int> dist;
    map <maze_state, bool> visited;
    queue <maze_state> bfs;
    maze_state begin;
    begin.x = start_X;
    begin.y = start_Y;
    begin.keys = 0;
    dist[begin] = 0;
    visited[begin] = true;
    bfs.push(begin);
    int key_dist[26];
    int key_reqs[26];
    bool key_found[26];
    for(int i = 0 ; i < 26 ; i++){
        key_found[i] = false;
        key_reqs[i] = -1;
        key_dist[i] = -1;
    }
    int total_key = 0;
    while(!bfs.empty()){
        maze_state cur = bfs.front();
        bfs.pop();
        
        if(total_key == (1<<26) - 1){
            for(int i = 0 ; i < 26 ; i++){
                cout << (char)(i + 'a') << " " << key_dist[i] << " " << key_reqs[i] << endl;
            }
            return 0;
        }

        for(int i = 0 ; i < 4 ; i++){
            maze_state next_state = cur;
            next_state.x += offset_x[i];
            next_state.y += offset_y[i];
            if(maze[next_state.x][next_state.y] != '#'){
                if(maze[next_state.x][next_state.y] == '.' && visited[next_state] == false){
                    dist[next_state] = dist[cur] + 1;
                    visited[next_state] = true;
                    bfs.push(next_state);
                }
                else{
                    if('a' <= maze[next_state.x][next_state.y] && maze[next_state.x][next_state.y] <= 'z'){
                        if(visited[next_state] == false){
                            dist[next_state] = dist[cur] + 1;
                            if(!key_found[maze[next_state.x][next_state.y] - 'a']){
                                key_reqs[maze[next_state.x][next_state.y] - 'a'] = cur.keys;
                                key_dist[maze[next_state.x][next_state.y] - 'a'] = dist[cur] + 1;
                                key_found[maze[next_state.x][next_state.y] - 'a'] = true;
                            }
                            visited[next_state] = true;
                            bfs.push(next_state);
                        }
                    }
                    else{
                        next_state.keys = next_state.keys | 1 << (maze[next_state.x][next_state.y] - 'A');
                        total_key = total_key | 1 << (maze[next_state.x][next_state.y] - 'A');
                        if(visited[next_state] == false){
                            dist[next_state] = dist[cur] + 1;
                            visited[next_state] = true;
                            bfs.push(next_state);
                        }
                    }
                }
            }
        }
    }
}