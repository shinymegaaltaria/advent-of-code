#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("d5_in.txt");
int main(){
    bool air[1024];
    for(int i = 0 ; i < 1024 ; i++) air[i] = false;
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
        air[row*8+col] = true;
    }
    for(int i = 0 ; i < 1024 ; i++){
        if(air[i] == false) cout << i << endl;
    }
}