#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
ifstream fin ("d20_in.txt");
int main(){
    char maze[121][125];
    vector<pair<int,int> > list[27];
    map<pair<int,int>, int> dist;
    map<pair<int,int>, bool> visited;
    int start_x, start_y, end_x, end_y;
    for(int i  = 0 ; i < 121 ; i++){
        for(int j = 0 ; j < 125 ; j++){
            char tmp;
            fin >> tmp;
            if('a' <= tmp && tmp <= 'z'){
                list[tmp-'a'].push_back(make_pair(i,j));
            }
            else if(tmp == '0'){
                list[26].push_back(make_pair(i,j));
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
    
    map<pair<int,int>, pair<int,int> > portal;
    map<pair<int,int>, pair<int,int> > bt;

    for(int i = 0 ; i < 27 ; i++){
        portal[list[i][0]] = list[i][1];
        portal[list[i][1]] = list[i][0];
    }

    int offset_x[4] = {0,0,1,-1};
    int offset_y[4] = {-1,1,0,0};
    queue<pair<int,int> > bfs;
    pair<int,int> cur = make_pair(start_x,start_y);
    visited[cur] = true;
    dist[cur] = 0;
    bfs.push(cur);
    //int cnt = 10;
    while(!bfs.empty()){
        //cnt--;
        cur = bfs.front();
        bfs.pop();
        //cout << cur.first << " " << cur.second << endl;
        if(cur.first == end_x && cur.second == end_y){
            cout << dist[cur] << endl;
            break;
        }
        for(int i = 0 ; i < 4 ; i++){
            pair<int,int> next = cur;
            next.first += offset_x[i];
            next.second += offset_y[i];
            if((0 <= next.first && next.first <= 120) && (0 <= next.second && next.second <= 124)){
                if(maze[next.first][next.second] != '#'){
                    if(maze[next.first][next.second] == '.'){
                        //cout << "a." << next.first << " " << next.second << endl;
                        if(!visited[next]){
                            dist[next] = dist[cur] + 1;
                            visited[next] = true;
                            //cout << "a.push " << next.first << " " << next.second << endl;
                            bt[next] = cur;
                            bfs.push(next);
                        }
                    }
                    else{
                        //cout << "b." << next.first << " " << next.second << endl;
                        if(!visited[next]){
                            dist[next] = dist[cur] + 1;
                            visited[next] = true;
                            bt[next] = cur;
                            cur = next;
                            next = portal[next];
                            dist[next] = dist[cur] + 1;
                            visited[next] = true;
                            bt[next] = cur;
                            //cout << "b.push " << next.first << " " << next.second << endl;
                            bfs.push(next);
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