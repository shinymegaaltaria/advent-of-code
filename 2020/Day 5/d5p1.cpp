#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("d5_in.txt");
int main(){
    int best = -1;
    string tmp;
    while(fin>>tmp){
        int row = 0;
        for(int j = 0 ; j < 7; j++){
            if(tmp[j] == 'B'){
                row += (1<<(6-j));
            }
        }
        int col = 0;
        for(int j = 0 ; j < 3; j++){
            if(tmp[7+j] == 'R'){
                col += (1<<(2-j));
            }
        }
        if(row*8+col > best){
            best = row*8 + col;
            //cout << row << " " << col<< endl;
        }
    }
    cout << best << endl;
}