#include <iostream>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
struct coord{
    int x;
    int y;
};
struct maze_state{
    coord drone[4];
    int keys;
};
bool operator<(const maze_state& m1, const maze_state& m2){
    return m1.keys < m2.keys;
}
int main(){
    ifstream mazein ("day_18_in_2.txt");
    char maze[81][81];
    int start_X, start_Y;
    maze_state begin;
    int pt = 0;
    for(int i = 0 ; i < 81 ; i++){
        for(int j = 0 ; j < 81 ; j++){
            mazein >> maze[i][j];
            if(maze[i][j] == '@'){
                begin.drone[pt].x = i;
                begin.drone[pt].y = j;
                maze[i][j] = '.';
                pt++;
            }
            cout << maze[i][j];
        }
        cout << endl;
    }
    map <maze_state, int> dist;
    map <maze_state, bool> visited;
    queue <maze_state> bfs;
    begin.keys = 0;
    dist[begin] = 0;
    visited[begin] = true;
    bfs.push(begin);
    while(!bfs.empty()){
        maze_state cur = bfs.front();
        bfs.pop();
        for(int i = 0 ; i < 4 ; i++) cout << cur.drone[i].x << " " << cur.drone[i].y << " ";
        cout << cur.keys << endl;
        if(cur.keys == (1 << 26) - 1){
            cout << dist[cur] << endl;
            return 0;
        }
        // x - 1 , y
        if(maze[cur.drone[0].x - 1][cur.drone[0].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[0].x -= 1;
            if(maze[next_state.drone[0].x][next_state.drone[0].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[0].x][next_state.drone[0].y] && maze[next_state.drone[0].x][next_state.drone[0].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone[0].x + 1][cur.drone[0].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[0].x += 1;
            if(maze[next_state.drone[0].x][next_state.drone[0].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[0].x][next_state.drone[0].y] && maze[next_state.drone[0].x][next_state.drone[0].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone[0].x][cur.drone[0].y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[0].y -= 1;
            if(maze[next_state.drone[0].x][next_state.drone[0].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[0].x][next_state.drone[0].y] && maze[next_state.drone[0].x][next_state.drone[0].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone[0].x][cur.drone[0].y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[0].y += 1;
            if(maze[next_state.drone[0].x][next_state.drone[0].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[0].x][next_state.drone[0].y] && maze[next_state.drone[0].x][next_state.drone[0].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x - 1 , y
        if(maze[cur.drone[1].x - 1][cur.drone[1].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[1].x -= 1;
            if(maze[next_state.drone[1].x][next_state.drone[1].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[1].x][next_state.drone[1].y] && maze[next_state.drone[1].x][next_state.drone[1].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone[1].x + 1][cur.drone[1].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[1].x += 1;
            if(maze[next_state.drone[1].x][next_state.drone[1].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[1].x][next_state.drone[1].y] && maze[next_state.drone[1].x][next_state.drone[1].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone[1].x][cur.drone[1].y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[1].y -= 1;
            if(maze[next_state.drone[1].x][next_state.drone[1].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[1].x][next_state.drone[1].y] && maze[next_state.drone[1].x][next_state.drone[1].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone[1].x][cur.drone[1].y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[1].y += 1;
            if(maze[next_state.drone[1].x][next_state.drone[1].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[1].x][next_state.drone[1].y] && maze[next_state.drone[1].x][next_state.drone[1].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x - 1 , y
        if(maze[cur.drone[2].x - 1][cur.drone[2].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[2].x -= 1;
            if(maze[next_state.drone[2].x][next_state.drone[2].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[2].x][next_state.drone[2].y] && maze[next_state.drone[2].x][next_state.drone[2].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone[2].x + 1][cur.drone[2].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[2].x += 1;
            if(maze[next_state.drone[2].x][next_state.drone[2].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[2].x][next_state.drone[2].y] && maze[next_state.drone[2].x][next_state.drone[2].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone[2].x][cur.drone[2].y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[2].y -= 1;
            if(maze[next_state.drone[2].x][next_state.drone[2].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[2].x][next_state.drone[2].y] && maze[next_state.drone[2].x][next_state.drone[2].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone[2].x][cur.drone[2].y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[2].y += 1;
            if(maze[next_state.drone[2].x][next_state.drone[2].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[2].x][next_state.drone[2].y] && maze[next_state.drone[2].x][next_state.drone[2].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x - 1 , y
        if(maze[cur.drone[3].x - 1][cur.drone[3].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[3].x -= 1;
            if(maze[next_state.drone[3].x][next_state.drone[3].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[3].x][next_state.drone[3].y] && maze[next_state.drone[3].x][next_state.drone[3].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone[3].x + 1][cur.drone[3].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[3].x += 1;
            if(maze[next_state.drone[3].x][next_state.drone[3].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[3].x][next_state.drone[3].y] && maze[next_state.drone[3].x][next_state.drone[3].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone[3].x][cur.drone[3].y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[3].y -= 1;
            if(maze[next_state.drone[3].x][next_state.drone[3].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[3].x][next_state.drone[3].y] && maze[next_state.drone[3].x][next_state.drone[3].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone[3].x][cur.drone[3].y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[3].y += 1;
            if(maze[next_state.drone[3].x][next_state.drone[3].y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[3].x][next_state.drone[3].y] && maze[next_state.drone[3].x][next_state.drone[3].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
    }
}