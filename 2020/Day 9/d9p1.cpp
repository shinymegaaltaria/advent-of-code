#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d9_in.txt");
int main(){
    long long int xmas[1000];
    long long int rolling[25];
    for(int i = 0 ; i < 25 ; i++){
        rolling[i] = 0;
    }
    for(int i = 0 ; i < 1000 ; i++){
        fin >> xmas[i];
        if(i <= 24){
            rolling[i % 25] = xmas[i];
        }
        if(i >= 25){
            bool ok = false;
            for(int j = 0 ; j < 25 ; j++){
                for(int k = 0 ; k < 25 ; k++){
                    if(rolling[j] + rolling[k] == xmas[i]){
                        ok = true;
                    }
                }
            }
            rolling[i % 25] = xmas[i];
            if(ok == false){
                cout << xmas[i] << endl;
                return 0;
            }
        }
    }
}