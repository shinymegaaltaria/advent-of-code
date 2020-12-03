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
    long long int cnt11 = 0, cnt31 = 0, cnt51 = 0, cnt71 = 0, cnt12 = 0;
    for(int i = 1 ; i < 323 ; i++){
        if(forest[i][i%31] == '#') cnt11++;
        if(forest[i][3*i%31] == '#') cnt31++;
        if(forest[i][5*i%31] == '#') cnt51++;
        if(forest[i][7*i%31] == '#') cnt71++;
    }
    for(int i = 1 ; i < 167 ; i++){
        if(forest[2*i][i%31] == '#') cnt12++;
    }
    cout << cnt11*cnt31*cnt51*cnt71*cnt12 << endl;
}