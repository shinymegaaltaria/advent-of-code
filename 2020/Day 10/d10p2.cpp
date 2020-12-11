#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin ("d10_in.txt");
map <long long int,long long int> dp;
map <long long int, bool> test;
map <long long int, bool> done;
long long int count_the_ways(long long int power){
    if(test[power] == false){
        dp[power] = 0;
        return dp[power];
    }
    if(power < 0){
        return 0;
    }
    if(power == 0){
        dp[0] = 1;
        return dp[0];
    }
    if(done[power]){
        return dp[power];
    }
    count_the_ways(power - 1);
    count_the_ways(power - 2);
    count_the_ways(power - 3);
    dp[power] = dp[power - 1] + dp[power - 2] + dp[power-3];
    done[power] = true;
    return dp[power];
}
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
    cout << count_the_ways(adapt[adapt_s - 1]) << endl;
}