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
    while(!bfs.empty()){
        maze_state cur = bfs.front();
        bfs.pop();
        cout << cur.x << " " << cur.y << " " << cur.keys << endl;
        if(cur.keys == (1 << 26) - 1){
            cout << dist[cur] << endl;
            return 0;
        }
        // x - 1 , y
        if(maze[cur.x - 1][cur.y] != '#'){
            maze_state next_state = cur;
            next_state.x -= 1;
            if(maze[next_state.x][next_state.y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.x][next_state.y] && maze[next_state.x][next_state.y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.x][next_state.y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.x][next_state.y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.x + 1][cur.y] != '#'){
            maze_state next_state = cur;
            next_state.x += 1;
            if(maze[next_state.x][next_state.y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.x][next_state.y] && maze[next_state.x][next_state.y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.x][next_state.y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.x][next_state.y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.x][cur.y - 1] != '#'){
            maze_state next_state = cur;
            next_state.y -= 1;
            if(maze[next_state.x][next_state.y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.x][next_state.y] && maze[next_state.x][next_state.y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.x][next_state.y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.x][next_state.y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.x][cur.y + 1] != '#'){
            maze_state next_state = cur;
            next_state.y += 1;
            if(maze[next_state.x][next_state.y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.x][next_state.y] && maze[next_state.x][next_state.y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.x][next_state.y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.x][next_state.y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
    }
    
}