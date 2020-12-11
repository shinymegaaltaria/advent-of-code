#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin ("d10_challenge.txt");
map <long long int,long long int> dp;
map <long long int, bool> test;
map <long long int, bool> done;
int main(){
    vector<long long int> arr;
    long long int tmp;
    while(fin >> tmp){
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    vector<long long int> adapt;
    adapt.push_back(0);
    long long int arr_s = arr.size();
    for(long long int i = 0 ; i < arr_s ; i++){
        adapt.push_back(arr[i]);
    }
    adapt.push_back(arr[arr_s - 1] + 3);
    long long int adapt_s = adapt.size();
    for(long long int i = 0 ; i < adapt_s ; i++){
        test[adapt[i]] = true;
    }
    for(int i = 0 ; i <= adapt[adapt_s - 1]; i++){
        if(i == 0){
            dp[i] = 1;
        }
        if(test[i + 1]){
            dp[i + 1] += dp[i];
            dp[i + 1] %= 10000000000;
        }
        if(test[i + 2]){
            dp[i + 2] += dp[i];
            dp[i + 2] %= 10000000000;
        }
        if(test[i + 3]){
            dp[i + 3] += dp[i];
            dp[i + 3] %= 10000000000;
        }
    }
    cout << dp[adapt[adapt_s - 1]] << endl;
}