#include <iostream>
using namespace std;
int main(){
    for(int i = 0 ; i < 512 ; i++){
        string s = "####@";
        for(int j = 0 ; j < 9 ; j++){
            if(i & 1 << j){
                s += "#";
            }
            else{
                s += ".";
            }
        }
        s += "#####";
        if(s.find("....") != string::npos){
            continue;
        }
        else if(s[8] == '.'){
            continue;
        }
        else cout << s << endl;
    }
}