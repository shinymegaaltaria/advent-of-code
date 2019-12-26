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
    int w = 15, h = 7;
    int key_amount = 26;
    ifstream mazein ("test.txt");
    char maze[h][w];
    int start_X, start_Y;
    maze_state begin;
    int pt = 0;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            mazein >> maze[i][j];
            if(maze[i][j] == '@'){
                begin.drone[pt].x = i;
                begin.drone[pt].y = j;
                maze[i][j] = '.';
                pt++;
            }
        }
    }
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
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
        if(cur.keys == (1 << key_amount) - 1){
            cout << dist[cur] << endl;
            return 0;
        }
        // x - 1 , y
        if(maze[cur.drone[0].x - 1][cur.drone[0].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[0].x -= 1;
            cout << dist[next_state] << endl;
            if(maze[next_state.drone[0].x][next_state.drone[0].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[0].x][next_state.drone[0].y] && maze[next_state.drone[0].x][next_state.drone[0].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone[0].x + 1][cur.drone[0].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[0].x += 1;
            if(maze[next_state.drone[0].x][next_state.drone[0].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[0].x][next_state.drone[0].y] && maze[next_state.drone[0].x][next_state.drone[0].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone[0].x][cur.drone[0].y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[0].y -= 1;
            if(maze[next_state.drone[0].x][next_state.drone[0].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[0].x][next_state.drone[0].y] && maze[next_state.drone[0].x][next_state.drone[0].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone[0].x][cur.drone[0].y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[0].y += 1;
            if(maze[next_state.drone[0].x][next_state.drone[0].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[0].x][next_state.drone[0].y] && maze[next_state.drone[0].x][next_state.drone[0].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[0].x][next_state.drone[0].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x - 1 , y
        if(maze[cur.drone[1].x - 1][cur.drone[1].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[1].x -= 1;
            if(maze[next_state.drone[1].x][next_state.drone[1].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[1].x][next_state.drone[1].y] && maze[next_state.drone[1].x][next_state.drone[1].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone[1].x + 1][cur.drone[1].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[1].x += 1;
            if(maze[next_state.drone[1].x][next_state.drone[1].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[1].x][next_state.drone[1].y] && maze[next_state.drone[1].x][next_state.drone[1].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone[1].x][cur.drone[1].y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[1].y -= 1;
            if(maze[next_state.drone[1].x][next_state.drone[1].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[1].x][next_state.drone[1].y] && maze[next_state.drone[1].x][next_state.drone[1].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone[1].x][cur.drone[1].y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[1].y += 1;
            if(maze[next_state.drone[1].x][next_state.drone[1].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[1].x][next_state.drone[1].y] && maze[next_state.drone[1].x][next_state.drone[1].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[1].x][next_state.drone[1].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x - 1 , y
        if(maze[cur.drone[2].x - 1][cur.drone[2].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[2].x -= 1;
            if(maze[next_state.drone[2].x][next_state.drone[2].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[2].x][next_state.drone[2].y] && maze[next_state.drone[2].x][next_state.drone[2].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone[2].x + 1][cur.drone[2].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[2].x += 1;
            if(maze[next_state.drone[2].x][next_state.drone[2].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[2].x][next_state.drone[2].y] && maze[next_state.drone[2].x][next_state.drone[2].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone[2].x][cur.drone[2].y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[2].y -= 1;
            if(maze[next_state.drone[2].x][next_state.drone[2].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[2].x][next_state.drone[2].y] && maze[next_state.drone[2].x][next_state.drone[2].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone[2].x][cur.drone[2].y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[2].y += 1;
            if(maze[next_state.drone[2].x][next_state.drone[2].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[2].x][next_state.drone[2].y] && maze[next_state.drone[2].x][next_state.drone[2].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[2].x][next_state.drone[2].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x - 1 , y
        if(maze[cur.drone[3].x - 1][cur.drone[3].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[3].x -= 1;
            if(maze[next_state.drone[3].x][next_state.drone[3].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[3].x][next_state.drone[3].y] && maze[next_state.drone[3].x][next_state.drone[3].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone[3].x + 1][cur.drone[3].y] != '#'){
            maze_state next_state = cur;
            next_state.drone[3].x += 1;
            if(maze[next_state.drone[3].x][next_state.drone[3].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[3].x][next_state.drone[3].y] && maze[next_state.drone[3].x][next_state.drone[3].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone[3].x][cur.drone[3].y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[3].y -= 1;
            if(maze[next_state.drone[3].x][next_state.drone[3].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[3].x][next_state.drone[3].y] && maze[next_state.drone[3].x][next_state.drone[3].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone[3].x][cur.drone[3].y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone[3].y += 1;
            if(maze[next_state.drone[3].x][next_state.drone[3].y] == '.' && dist[next_state] == 0){
                dist[next_state] = dist[cur] + 1;
                
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone[3].x][next_state.drone[3].y] && maze[next_state.drone[3].x][next_state.drone[3].y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'a');
                    if(dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone[3].x][next_state.drone[3].y] - 'A')) && dist[next_state] == 0){
                        dist[next_state] = dist[cur] + 1;
                        
                        bfs.push(next_state);
                    }
                }
            }
        }
    }
}