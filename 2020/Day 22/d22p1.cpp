#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d22_in.txt");
int main(){
    vector<int> p1;
    vector<int> p2;
    for(int i = 0 ; i < 25; i++){
        int tmp;
        fin >> tmp;
        p1.push_back(tmp);
    }
    for(int i = 0 ; i < 25; i++){
        int tmp;
        fin >> tmp;
        p2.push_back(tmp);
    }
    int cur_ind = 0;
    while(p1.size() > cur_ind && p2.size() > cur_ind){
        if(p1[cur_ind] > p2[cur_ind]){
            p1.push_back(p1[cur_ind]);
            p1.push_back(p2[cur_ind]);
        }
        else{
            p2.push_back(p2[cur_ind]);
            p2.push_back(p1[cur_ind]);
        }
        cur_ind++;
        cout << cur_ind << endl;
    }
    int ans = 0;
    if(p1.size() == cur_ind){
        int s = p2.size();
        for(int i = s - 50; i < s ; i++){
            ans += (s - i) * p2[i];
        }
    }
    else{
        int s = p1.size();
        for(int i = s - 50; i < s ; i++){
            ans += (s - i) * p1[i];
        }
    }
    cout << ans << endl;
}