#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("d1_in.txt");
int main(){
    int arr[200];
    for(int i = 0 ; i < 200 ; i++){
        fin >> arr[i];
    }
    for(int i = 0 ; i < 200 ; i++){
        for(int j = i ; j < 200 ; j++){
            if(arr[i] + arr[j] == 2020){
                cout << arr[i] * arr[j] << endl;
            }
        }
    }
}