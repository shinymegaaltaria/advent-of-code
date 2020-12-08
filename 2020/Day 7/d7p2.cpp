#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
map<string, vector<pair<int,string> > > orders;
map <string, bool> used;
map <string, long long int> dp;
ifstream fin ("processed_d7.txt");
long long int cnt(string target){
    map<string, vector<pair<int,string> > >::iterator it;
    long long int ans = 0;
    for(it = orders.begin(); it != orders.end(); it++){
        bool containing = false;
        vector<pair<int,string> > tmp = it->second;
        if(it->first == target){
            int size = tmp.size();
            for(int i = 0 ; i < size ; i++){
                if(!used[tmp[i].second]){
                    cnt(tmp[i].second);
                    used[tmp[i].second] = true;
                    ans += tmp[i].first + tmp[i].first * dp[tmp[i].second];
                }
                else{
                    ans += tmp[i].first + tmp[i].first * dp[tmp[i].second];
                }
            }
        }
    }
    dp[target] = ans;
    return ans;
}
int main(){
    for(int i = 0 ; i < 594 ; i++){
        int size;
        cin >> size;
        string outer_bag;
        cin >> outer_bag;
        vector<pair<int,string> > tmp;
        for(int j = 0 ; j < size ; j++){
            int amt;
            string inner_bag;
            cin >> amt >> inner_bag;
            orders[outer_bag].push_back(make_pair(amt,inner_bag));
        }
        
    }
    cout << "Input processed" << endl;
    cout << cnt("shinygold") << endl;
}