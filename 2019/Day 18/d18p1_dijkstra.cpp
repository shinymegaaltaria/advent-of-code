#include <iostream>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
struct path{
    char from;
    char to;
    int dist;
    string keys;
};
bool operator>(const path &p1, const path &p2){
    if(p1.dist == p2.dist){
        if(p1.keys.size() == p2.keys.size()){
            if(p1.to == p2.to){
                return p1.from < p2.from;
            }
            else{
                return p1.to < p2.to;
            }
        }
        else{
            return p1.keys.size() < p2.keys.size();
        }
    }
    else{
        return p1.dist < p2.dist;
    }
}
int main(){
    ifstream mazein ("day18_in.txt");
    char maze[81][81];
    for(int i = 0 ; i < 81 ; i++){
        for(int j = 0 ; j < 81 ; j++){
            mazein >> maze[i][j];
        }
    }
}