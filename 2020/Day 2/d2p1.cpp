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
        int length = pw.size();
        int cur_cnt = 0;
        for(int j = 0 ; j < length ; j++){
            if(pw[j] == to_cnt){
                cur_cnt++;
            }
        }
        if(min <= cur_cnt && cur_cnt <= max) ans++;
    }
    cout << ans << endl;
}