#include <iostream>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
struct maze_state{
    int drone0_x;
    int drone0_y;
    int drone1_x;
    int drone1_y;
    int drone2_x;
    int drone2_y;
    int drone3_x;
    int drone3_y;
    int keys;
};
bool operator<(const maze_state& m1, const maze_state& m2){
    if(m1.drone0_x == m2.drone0_x){
        if(m1.drone0_y == m2.drone0_y){
            if(m1.drone1_x == m2.drone1_x){
                if(m1.drone1_y == m2.drone1_y){
                    if(m1.drone2_x == m2.drone2_x){
                        if(m1.drone2_y == m2.drone2_y){
                            if(m1.drone3_x == m2.drone3_x){
                                if(m1.drone3_y == m2.drone3_y){
                                    return m1.keys < m2.keys;
                                }
                                else{
                                    return m1.drone3_y < m2.drone3_y;
                                }
                            }
                            else{
                                return m1.drone3_x < m2.drone3_x;
                            }
                        }
                        else{
                            return m1.drone2_y < m2.drone2_y;
                        }
                    }
                    else{
                        return m1.drone2_x < m2.drone2_x;
                    }
                }
                else{
                    return m1.drone1_y < m2.drone1_y;
                }
            }
            else{
                return m1.drone1_x < m2.drone1_x;
            }
        }
        else{
            return m1.drone0_y < m2.drone0_y;
        }
    }
    else{
        return m1.drone0_x < m2.drone0_x;
    }
}
int main(){
    int w = 81, h = 81;
    int key_amount = 26;
    ifstream mazein ("day_18_in_2.txt");
    char maze[h][w];
    int start_X[4], start_Y[4];
    maze_state begin;
    int pt = 0;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            mazein >> maze[i][j];
            if(maze[i][j] == '@'){
                start_X[pt] = i;
                start_Y[pt] = j;
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
    begin.drone0_x = start_X[0];
    begin.drone1_x = start_X[1];
    begin.drone2_x = start_X[2];
    begin.drone3_x = start_X[3];
    begin.drone0_y = start_Y[0];
    begin.drone1_y = start_Y[1];
    begin.drone2_y = start_Y[2];
    begin.drone3_y = start_Y[3];
    dist[begin] = 0;
    visited[begin] = true;
    bfs.push(begin);
    while(!bfs.empty()){
        maze_state cur = bfs.front();
        bfs.pop();
        cout << cur.drone0_x << " " << cur.drone0_y << " " << cur.drone1_x << " " << cur.drone1_y << " ";
        cout << cur.drone2_x << " " << cur.drone2_y << " " << cur.drone3_x << " " << cur.drone3_y << " ";
        cout << cur.keys << endl;
        if(cur.keys == (1 << key_amount) - 1){
            cout << dist[cur] << endl;
            return 0;
        }
        // x - 1 , y
        if(maze[cur.drone0_x - 1][cur.drone0_y] != '#'){
            maze_state next_state = cur;
            next_state.drone0_x -= 1;
            if(maze[next_state.drone0_x][next_state.drone0_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone0_x][next_state.drone0_y] && maze[next_state.drone0_x][next_state.drone0_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone0_x][next_state.drone0_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone0_x][next_state.drone0_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone0_x + 1][cur.drone0_y] != '#'){
            maze_state next_state = cur;
            next_state.drone0_x += 1;
            if(maze[next_state.drone0_x][next_state.drone0_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone0_x][next_state.drone0_y] && maze[next_state.drone0_x][next_state.drone0_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone0_x][next_state.drone0_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone0_x][next_state.drone0_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone0_x][cur.drone0_y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone0_y -= 1;
            if(maze[next_state.drone0_x][next_state.drone0_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone0_x][next_state.drone0_y] && maze[next_state.drone0_x][next_state.drone0_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone0_x][next_state.drone0_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone0_x][next_state.drone0_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone0_x][cur.drone0_y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone0_y += 1;
            if(maze[next_state.drone0_x][next_state.drone0_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone0_x][next_state.drone0_y] && maze[next_state.drone0_x][next_state.drone0_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone0_x][next_state.drone0_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone0_x][next_state.drone0_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x - 1 , y
        if(maze[cur.drone1_x - 1][cur.drone1_y] != '#'){
            maze_state next_state = cur;
            next_state.drone1_x -= 1;
            if(maze[next_state.drone1_x][next_state.drone1_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone1_x][next_state.drone1_y] && maze[next_state.drone1_x][next_state.drone1_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone1_x][next_state.drone1_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone1_x][next_state.drone1_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone1_x + 1][cur.drone1_y] != '#'){
            maze_state next_state = cur;
            next_state.drone1_x += 1;
            if(maze[next_state.drone1_x][next_state.drone1_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone1_x][next_state.drone1_y] && maze[next_state.drone1_x][next_state.drone1_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone1_x][next_state.drone1_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone1_x][next_state.drone1_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone1_x][cur.drone1_y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone1_y -= 1;
            if(maze[next_state.drone1_x][next_state.drone1_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone1_x][next_state.drone1_y] && maze[next_state.drone1_x][next_state.drone1_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone1_x][next_state.drone1_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone1_x][next_state.drone1_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone1_x][cur.drone1_y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone1_y += 1;
            if(maze[next_state.drone1_x][next_state.drone1_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone1_x][next_state.drone1_y] && maze[next_state.drone1_x][next_state.drone1_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone1_x][next_state.drone1_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone1_x][next_state.drone1_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x - 1 , y
        if(maze[cur.drone2_x - 1][cur.drone2_y] != '#'){
            maze_state next_state = cur;
            next_state.drone2_x -= 1;
            if(maze[next_state.drone2_x][next_state.drone2_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone2_x][next_state.drone2_y] && maze[next_state.drone2_x][next_state.drone2_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone2_x][next_state.drone2_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone2_x][next_state.drone2_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone2_x + 1][cur.drone2_y] != '#'){
            maze_state next_state = cur;
            next_state.drone2_x += 1;
            if(maze[next_state.drone2_x][next_state.drone2_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone2_x][next_state.drone2_y] && maze[next_state.drone2_x][next_state.drone2_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone2_x][next_state.drone2_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone2_x][next_state.drone2_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone2_x][cur.drone2_y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone2_y -= 1;
            if(maze[next_state.drone2_x][next_state.drone2_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone2_x][next_state.drone2_y] && maze[next_state.drone2_x][next_state.drone2_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone2_x][next_state.drone2_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone2_x][next_state.drone2_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone2_x][cur.drone2_y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone2_y += 1;
            if(maze[next_state.drone2_x][next_state.drone2_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone2_x][next_state.drone2_y] && maze[next_state.drone2_x][next_state.drone2_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone2_x][next_state.drone2_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone2_x][next_state.drone2_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x - 1 , y
        if(maze[cur.drone3_x - 1][cur.drone3_y] != '#'){
            maze_state next_state = cur;
            next_state.drone3_x -= 1;
            if(maze[next_state.drone3_x][next_state.drone3_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone3_x][next_state.drone3_y] && maze[next_state.drone3_x][next_state.drone3_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone3_x][next_state.drone3_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone3_x][next_state.drone3_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x + 1 , y
        if(maze[cur.drone3_x + 1][cur.drone3_y] != '#'){
            maze_state next_state = cur;
            next_state.drone3_x += 1;
            if(maze[next_state.drone3_x][next_state.drone3_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone3_x][next_state.drone3_y] && maze[next_state.drone3_x][next_state.drone3_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone3_x][next_state.drone3_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone3_x][next_state.drone3_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y - 1
        if(maze[cur.drone3_x][cur.drone3_y - 1] != '#'){
            maze_state next_state = cur;
            next_state.drone3_y -= 1;
            if(maze[next_state.drone3_x][next_state.drone3_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone3_x][next_state.drone3_y] && maze[next_state.drone3_x][next_state.drone3_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone3_x][next_state.drone3_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone3_x][next_state.drone3_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
        // x , y + 1
        if(maze[cur.drone3_x][cur.drone3_y + 1] != '#'){
            maze_state next_state = cur;
            next_state.drone3_y += 1;
            if(maze[next_state.drone3_x][next_state.drone3_y] == '.' && visited[next_state] == false){
                dist[next_state] = dist[cur] + 1;
                visited[next_state] = true;
                bfs.push(next_state);
            }
            else{
                if('a' <= maze[next_state.drone3_x][next_state.drone3_y] && maze[next_state.drone3_x][next_state.drone3_y] <= 'z'){
                    next_state.keys = next_state.keys | 1 << (maze[next_state.drone3_x][next_state.drone3_y] - 'a');
                    if(visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
                else{
                    if((next_state.keys & 1 << (maze[next_state.drone3_x][next_state.drone3_y] - 'A')) && visited[next_state] == false){
                        dist[next_state] = dist[cur] + 1;
                        visited[next_state] = true;
                        bfs.push(next_state);
                    }
                }
            }
        }
    }
}