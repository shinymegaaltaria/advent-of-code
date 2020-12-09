#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d9_in.txt");
int main(){
    long long int xmas[1001];
    long long int rolling[25];
    long long int ps[1001];
    for(int i = 0 ; i < 1001 ; i++){
        ps[i] = 0;
    }
    for(int i = 1 ; i <= 1000 ; i++){
        fin >> xmas[i];
        ps[i] = ps[i - 1] + xmas[i];
    }
    for(int i = 1 ; i <= 1000 ; i++){
        for(int j = 1 ; j <= 1000 ; j++){
            if(ps[j] - ps[i - 1] == 177777905){
                cout << "found: " << i << " " << j << endl;
                long long int smallest = 1777779050000, largest = 0;
                for(int k = i ; k < j ; k++){
                    smallest = min(xmas[k],smallest);
                    largest = max(xmas[k],largest);
                }
                cout << smallest + largest << endl;
                return 0;
            }
        }
    }
}