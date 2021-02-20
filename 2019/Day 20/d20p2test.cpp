#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
ifstream fin ("d20_test.txt");
struct coord{
    int x;
    int y;
    int z;
};

bool operator<(const coord& m1, const coord& m2){
    if(m1.x == m2.x){
        if(m1.y == m2.y){
            return m1.z < m2.z;
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
    char maze[33][41];
    coord list[13][2];
    map<coord, int> dist;
    map<coord, bool> visited;
    int start_x, start_y, start_z = 0, end_x, end_y, end_z = 0;
    for(int i  = 0 ; i < 33 ; i++){
        for(int j = 0 ; j < 41 ; j++){
            char tmp;
            fin >> tmp;
            if('a' <= tmp && tmp <= 'z'){
                coord new_coord;
                new_coord.x = i;
                new_coord.y = j;
                new_coord.z = -1;
                list[tmp-'a'][0] = new_coord;
            }
            else if('A' <= tmp && tmp <= 'Z'){
                coord new_coord;
                new_coord.x = i;
                new_coord.y = j;
                new_coord.z = 1;
                list[tmp-'A'][1] = new_coord;
            }
            else if(tmp == '!'){
                end_x = i;
                end_y = j;
                tmp = '.';
            }
            else if(tmp == '@'){
                start_x = i;
                start_y = j;
                tmp = '.';
            }
            maze[i][j] = tmp;
        }
    }
    
    map<coord,coord> bt;

    int offset_x[4] = {0,0,1,-1};
    int offset_y[4] = {-1,1,0,0};
    queue<coord> bfs;
    coord cur;
    cur.x = start_x;
    cur.y = start_y;
    cur.z = start_z;

    coord goal;
    goal.x = end_x;
    goal.y = end_y;
    goal.z = end_z;

    visited[cur] = true;
    dist[cur] = 0;
    bfs.push(cur);
    //int cnt = 10;
    while(!bfs.empty()){
        //cnt--;
        cur = bfs.front();
        bfs.pop();
        //cout << cur.x << " " << cur.y << " " << cur.z << endl;
        if(cur.x == goal.x && cur.y == goal.y && cur.z == goal.z){
            cout << dist[cur] << endl;
            break;
        }
        for(int i = 0 ; i < 4 ; i++){
            coord next = cur;
            next.x += offset_x[i];
            next.y += offset_y[i];
            if((0 <= next.x && next.x <= 32) && (0 <= next.y && next.y <= 40)){
                if(maze[next.x][next.y] != '#'){
                    if(maze[next.x][next.y] == '.'){
                        //cout << "a." << next.x << " " << next.y << " " << next.z << endl;
                        if(!visited[next]){
                            dist[next] = dist[cur] + 1;
                            visited[next] = true;
                            bt[next] = cur;
                            bfs.push(next);
                            //cout << "a.push " << next.x << " " << next.y << " " << next.z << endl;
                        }
                    }
                    else{
                        
                        if(!visited[next]){
                            //cout << cur.x << " " << cur.y << " " << cur.z << " b. " << next.x << " " << next.y << " " << next.z << endl;
                            dist[next] = dist[cur] + 1;
                            visited[next] = true;
                            bt[next] = cur;

                            char tmp = maze[next.x][next.y];
                            if('a' <= tmp && tmp <= 'z'){
                                if(cur.z > 20){
                                    //do nothing
                                }
                                else{
                                    cur = next;
                                    next = list[tmp-'a'][1];
                                    next.z += cur.z;
                                }
                            }
                            else{
                                if(cur.z == 0){
                                    //do nothing
                                }
                                else{
                                    cur = next;
                                    next = list[tmp-'a'][0];
                                    next.z += cur.z;
                                }
                            }

                            dist[next] = dist[cur] + 1;
                            visited[next] = true;
                            bt[next] = cur;

                            bfs.push(next);
                            //cout << "b.push " << next.x << " " << next.y << " " << next.z << endl;
                        }
                        
                    }
                }
            }
        }
        //cout << endl;
    }
    /*
    pair<int,int> starting_state = make_pair(start_x,start_y);
    pair<int,int> ending_state = make_pair(end_x,end_y);
    pair<int,int> cur_state = ending_state;
    vector <pair<int,int> > route;
    while(bt[cur_state] != starting_state){
        route.push_back(bt[cur_state]);
        cur_state = bt[cur_state];
    }
    route.push_back(starting_state);
    reverse(route.begin(),route.end());
    int s = route.size();
    for(int i = 0 ; i < s ; i++){
        cout << route[i].first << " " << route[i].second << endl;
    }
    */
}