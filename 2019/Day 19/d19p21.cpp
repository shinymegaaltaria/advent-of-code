#include <iostream>
using namespace std;
int main(){
    bool tractor[10000][10000];
    for(int i = 0 ; i < 10000 ; i++){
        for(int j = 0 ; j < 10000 ; j++){
            tractor[i][j] = false;
        }
    }
    for(int i = 0 ; i < 10000 ; i++){
        for(int j = 0 ; j < 10000 ; j++){
            if(i == 0 && j == 0){
                tractor[i][j] = true;
            }
            else{
                
            }
        }
    }
}