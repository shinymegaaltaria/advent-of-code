#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    ifstream phasein ("day16_part2_in.txt");
    string phase;
    phasein >> phase;
    int skip = 0;
    for(int i = 0 ; i < 7 ; i++){
        skip *= 10;
        skip += phase[i] - 48;
    }
    int multiplier[4] = {0, 1, 0, -1};
    int size = phase.size();
    for(int i = 0 ; i < 100 ; i++){
        string new_phase = phase;
        vector <int> og;
        vector <int> ps;
        og.push_back(0);
        for(int j = 0 ; j < size ; j++){
            og.push_back(phase[i]-48);
        }
        ps = og;
        for(int j = 1 ; j < size + 1 ; j++){
            ps[j] = og[j] + ps[j - 1];
        }
        for(int j = 1 ; j < size + 1; j++){
            cout << j << " ok" << endl;
            int tmp = 0;
            for(int k = 1 ; k <= ((size - 1) / j) + 1 ; k++){
                int r = (k + 1) * j - 1;
                if(size < r){
                    r = size;
                }
                if(k % 4 == 1){
                    tmp += ps[r] - ps[k*j-1];
                }
                else if(k % 4 == 3){
                    tmp -= ps[r] - ps[k*j-1];
                }
            }
            if(tmp < 0){
                tmp = -1 * tmp;
            }
            new_phase[j - 1] = (tmp % 10) + '0';
        }
        phase = new_phase;
    }
    for(int i = skip; i < skip + 8 ; i++) cout << phase[i];
    //to determine ((i+1)%(4*pos))/pos
}