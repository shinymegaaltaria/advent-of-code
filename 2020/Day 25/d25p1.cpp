#include <iostream>
using namespace std;
long long int bigmod(long long int pow){
    if(pow == 1){
        return 7;
    }
    if(pow == 0){
        return 1;
    }
    else{
            long long int partial = bigmod(pow/2);
        if(pow % 2 == 1){
            return (((partial * partial) % 20201227) * 7) % 20201227;
        }
        else{
            return (partial * partial) % 20201227;
        }
    }
}
int main(){
    long long int target[2];
    cin >> target[0] >> target[1];
    long long int cur_pow = 1;
    long long int pow1 = 0;
    long long int pow2 = 0;
    for(long long int i = 1 ; i <= 20201226 ; i++){
        cur_pow *= 7;
        cur_pow %= 20201227;
        if(cur_pow == target[0]){
            pow1 = i;
        }
        if(cur_pow == target[1]){
            pow2 = i;
        }
        if(pow1 != 0 && pow2 != 0){
            cout << bigmod(pow1 * pow2) << endl;
            return 0;
        }
    }
}