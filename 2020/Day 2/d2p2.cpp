#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("d2_in.txt");
int main(){
    int ans = 0;
    for(int i = 0 ; i < 1000 ; i++){
        int min, max;
        fin >> min >> max;
        char to_cnt;
        fin >> to_cnt;
        string pw;
        fin >> pw;
        if(pw[min - 1] == to_cnt ^ pw[max - 1] == to_cnt) ans++;
    }
    cout << ans << endl;
}