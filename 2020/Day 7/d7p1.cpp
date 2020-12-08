#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
map<string, vector<pair<int,string> > > orders;
map <string, bool> used;
ifstream fin ("processed_d7.txt");
int cnt(string target){
    map<string, vector<pair<int,string> > >::iterator it;
    int ans = 0;
    for(it = orders.begin(); it != orders.end(); it++){
        bool containing = false;
        vector<pair<int,string> > tmp = it->second;
        int size = tmp.size();
        for(int i = 0 ; i < size ; i++){
            if(tmp[i].second == target){
                containing = true;
            }
        }
        if(containing && !used[it->first]){
            used[it->first] = true;
            ans += 1;
            ans += cnt(it -> first);
        }
    }
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