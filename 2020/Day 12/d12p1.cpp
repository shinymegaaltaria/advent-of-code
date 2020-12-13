#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d12_in.txt");
int main(){
    int cur_dir = 0; //0E, 1S, 2W, 3N
    string directions = "ESWN";
    int cur_X = 0, cur_Y = 0;
    for(int i = 0 ; i < 769 ; i++){
        char direction;
        int param;
        fin >> direction >> param;
        if(direction == 'F'){
            direction = directions[cur_dir];
        }
        if(direction == 'N'){
            cur_Y += param;
        }
        else if(direction == 'S'){
            cur_Y -= param;
        }
        else if(direction == 'W'){
            cur_X -= param;
        }
        else if(direction == 'E'){
            cur_X += param;
        }
        else if(direction == 'L'){
            cur_dir += 3 * (param/90);
            cur_dir %= 4;
        }
        else if(direction == 'R'){
            cur_dir += 1 * (param/90);
            cur_dir %= 4;
        }
        //cout << cur_X << " " << cur_Y << " " << directions[cur_dir] << endl;
    }
    cout << abs(cur_X) + abs(cur_Y) << endl;
}