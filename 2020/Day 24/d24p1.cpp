#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d24_in.txt");
struct coord{
    int x;
    int y;
    int z;
};


bool operator<(const coord& c1, const coord& c2){
    if(c1.x == c2.x){
        if(c1.y == c2.y){
            return c1.z < c2.z;
        }
        else{
            return c1.y < c2.y;
        }
    }
    else{
        return c1.x < c2.x;
    }
}

int main(){
    map<coord,bool> honey_comb;
    int cnt = 0;
    for(int i = 0 ; i < 541 ; i++){
        string instruction;
        fin >> instruction;
        int s = instruction.size();
        int cur_x = 0, cur_y = 0, cur_z = 0;
        for(int j = 0 ; j < s ; j++){
            //cout << cur_x << " " << cur_y << " " << cur_z << endl;
            if(instruction[j] == 'e'){
                cur_x += 1;
                cur_y -= 1;
            }
            else if(instruction[j] == 'w'){
                cur_x -= 1;
                cur_y += 1;
            }
            else{
                if(instruction[j] == 'n'){
                    j++;
                    if(instruction[j] == 'w'){
                        cur_z -= 1;
                        cur_y += 1;
                    }
                    else{
                        cur_z -= 1;
                        cur_x += 1;
                    }
                }
                else{
                    j++;
                    if(instruction[j] == 'w'){
                        cur_x -= 1;
                        cur_z += 1;
                    }
                    else{
                        cur_y -= 1;
                        cur_z += 1;
                    }
                }
            }
        }
        coord cur_coord;
        cur_coord.x = cur_x;
        cur_coord.y = cur_y;
        cur_coord.z = cur_z;
        if(honey_comb[cur_coord]){
            honey_comb[cur_coord] = false;
            cnt--;
            //cout << cur_x << " " << cur_y << " off\n";
        }
        else{
            honey_comb[cur_coord] = true;
            cnt++;
            //cout << cur_x << " " << cur_y << " on\n";
        }
    }
    cout << cnt << endl;
}