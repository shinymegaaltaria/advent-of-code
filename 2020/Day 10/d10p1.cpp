#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin ("d10_in.txt");
int main(){
    vector<int> arr;
    map <int, bool> test;
    int tmp;
    while(fin >> tmp){
        arr.push_back(tmp);
        test[tmp] = true;
    }
    sort(arr.begin(),arr.end());
    vector<int> adapt;
    adapt.push_back(0);
    int s = arr.size();
    for(int i = 0 ; i < s ; i++){
        adapt.push_back(arr[i]);
    }
    adapt.push_back(arr[s - 1] + 3);
    int cnt1 = 0, cnt3 = 0;
    for(int i = 0 ; i < s + 1 ; i++){
        int diff = adapt[i + 1] - adapt[i];
        if(diff == 1) cnt1++;
        if(diff == 3) cnt3++;
    }
    cout << cnt1 * cnt3 << endl;
}