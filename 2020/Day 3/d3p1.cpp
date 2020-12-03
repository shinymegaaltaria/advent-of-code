#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("d3_in.txt");
int main(){
    char forest[323][31];
    for(int i = 0 ; i < 323; i++){
        for(int j = 0 ; j < 31; j++){
            fin >> forest[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1 ; i < 323 ; i++){
        if(forest[i][3*i%31] == '#') cnt++;
    }
    cout << cnt << endl;
}