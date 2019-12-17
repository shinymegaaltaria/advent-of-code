#include <iostream>
using namespace std;
int main(){
    char thing[39][43];
    for(int i = 0 ; i <39 ; i++ ){
        for(int j = 0 ; j < 43; j++){
            cin >> thing[i][j];
        }
    }
    long long int sum = 0;
    for(int i = 1 ; i < 38 ; i++){
        for(int j = 1 ; j < 42 ; j++){
            if(thing[i-1][j]=='#' && thing[i+1][j]=='#' && thing[i][j]=='#' && thing[i][j-1]=='#' && thing[i][j+1]=='#'){
                sum += i*j;
            }
        }
    }
    cout << sum << endl;
}