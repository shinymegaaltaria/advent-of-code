#include <iostream>
using namespace std;
int main(){
    string phase;
    cin >> phase;
    int multiplier[4] = {0, 1, 0, -1};
    int size = phase.size();
    for(int i = 0 ; i < 100 ; i++){
        string new_phase = phase;
        for(int j = 1 ; j < size + 1; j++){
            int tmp = 0;
            for(int k = 1 ; k < size + 1; k++){
                tmp += (new_phase[k - 1] - '0') * multiplier[(k % (4 * j)) / j];
            }
            if(tmp < 0){
                tmp = -1 * tmp;
            }
            new_phase[j - 1] = (tmp % 10) + '0';
        }
        phase = new_phase;
    }
    cout << phase << endl;
    //to determine ((i+1)%(4*pos))/pos
}