#include <iostream>
#include <queue>
using namespace std;
int main(){
    char maze[41][41];
    bool visited[41][41];
    int dist[41][41];
    int cur_X = 0, cur_Y = 0;
    int target_X = 0, target_Y = 0;
    for(int i = 0 ; i < 41; i++){
        for(int j = 0 ; j < 41 ; j++){
            visited[i][j] = false;
            dist[i][j] = -1;
            cin >> maze[i][j];
            if(maze[i][j] == '*'){
                cur_X = i;
                cur_Y = j;
            }
            if(maze[i][j] == '!'){
                target_X = i;
                target_Y = j;
            }
        }
    }
    queue <pair<int,int> > bfs;
    visited[cur_X][cur_Y] = true;
    dist[cur_X][cur_Y] = 0;
    bfs.push(make_pair(cur_X,cur_Y));
    while(!bfs.empty()){
        cur_X = bfs.front().first;
        cur_Y = bfs.front().second;
        cout << cur_X << " " << cur_Y << endl;
        bfs.pop();
        if(maze[cur_X - 1][cur_Y] != '#' && !visited[cur_X - 1][cur_Y]){
            dist[cur_X - 1][cur_Y] = dist[cur_X][cur_Y] + 1;
            visited[cur_X - 1][cur_Y] = true;
            bfs.push(make_pair(cur_X - 1, cur_Y));
        }
        if(maze[cur_X + 1][cur_Y] != '#' && !visited[cur_X + 1][cur_Y]){
            dist[cur_X + 1][cur_Y] = dist[cur_X][cur_Y] + 1;
            visited[cur_X + 1][cur_Y] = true;
            bfs.push(make_pair(cur_X + 1, cur_Y));
        }
        if(maze[cur_X][cur_Y - 1] != '#' && !visited[cur_X][cur_Y - 1]){
            dist[cur_X][cur_Y - 1] = dist[cur_X][cur_Y] + 1;
            visited[cur_X][cur_Y - 1] = true;
            bfs.push(make_pair(cur_X, cur_Y - 1));
        }
        if(maze[cur_X][cur_Y + 1] != '#' && !visited[cur_X][cur_Y + 1]){
            dist[cur_X][cur_Y + 1] = dist[cur_X][cur_Y] + 1;
            visited[cur_X][cur_Y + 1] = true;
            bfs.push(make_pair(cur_X, cur_Y + 1));
        }
    }
    cout << dist[target_X][target_Y] << endl;
}