#include <iostream>
#include <queue>
#include <map>
using namespace std;
struct maze_state{
    int x;
    int y;
    string keys;
};

bool operator<(const maze_state& m1, const maze_state& m2){
    return m1.x + m1.y < m2.x + m2.y;
}

int main(){
    char maze[81][81];
    int pos_X, pos_Y;
    for(int i = 0 ; i < 81 ; i++){
        for(int j = 0 ; j < 81 ; j++){
            cin >> maze[i][j];
            if(maze[i][j] == '@'){
                pos_X = i;
                pos_Y = j;
                maze[i][j] = '.';
            }
        }
    }
    map <maze_state,int> dist;
    map <maze_state,bool> visited;
    queue <maze_state> bfs;
    maze_state begin;
    begin.x = pos_X;
    begin.y = pos_Y;
    begin.keys = "                          ";
    dist[begin] = 0;
    visited[begin] = true;
    
    bfs.push(begin);
    while(!bfs.empty()){
        maze_state cur = bfs.front();
        bfs.pop();
        
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
                    if(cur.keys[maze[next_state.x][next_state.y] - 'a'] == ' '){
                        next_state.keys[maze[next_state.x][next_state.y] - 'a'] = maze[next_state.x][next_state.y];
                    }
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if(cur.keys[maze[next_state.x][next_state.y] - 'A'] != ' '){
                        if(visited[next_state] == false){
                            dist[next_state] = dist[cur] + 1;
                            visited[next_state] = true;
                            bfs.push(next_state);
                        }
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
                    if(cur.keys[maze[next_state.x][next_state.y] - 'a'] == ' '){
                        next_state.keys[maze[next_state.x][next_state.y] - 'a'] = maze[next_state.x][next_state.y];
                    }
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if(cur.keys[maze[next_state.x][next_state.y] - 'A'] != ' '){
                        if(visited[next_state] == false){
                            dist[next_state] = dist[cur] + 1;
                            visited[next_state] = true;
                            bfs.push(next_state);
                        }
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
                    if(cur.keys[maze[next_state.x][next_state.y] - 'a'] == ' '){
                        next_state.keys[maze[next_state.x][next_state.y] - 'a'] = maze[next_state.x][next_state.y];
                    }
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if(cur.keys[maze[next_state.x][next_state.y] - 'A'] != ' '){
                        if(visited[next_state] == false){
                            dist[next_state] = dist[cur] + 1;
                            visited[next_state] = true;
                            bfs.push(next_state);
                        }
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
                    if(cur.keys[maze[next_state.x][next_state.y] - 'a'] == ' '){
                        next_state.keys[maze[next_state.x][next_state.y] - 'a'] = maze[next_state.x][next_state.y];
                    }
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if(cur.keys[maze[next_state.x][next_state.y] - 'A'] != ' '){
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
    int min_dist = 2147483647;
    for(int i = 0 ; i < 81 ; i++){
        for(int j = 0 ; j < 81 ; j++){
            maze_state tmp;
            tmp.x = i;
            tmp.y = j;
            tmp.keys = "abcdefghijklmnopqrstuvwxyz";
            if(dist[tmp] == 0){
                continue;
            }
            cout << dist[tmp] << endl;
            min_dist = min(dist[tmp],min_dist);
        }
    }
    cout << min_dist << endl;
    
}