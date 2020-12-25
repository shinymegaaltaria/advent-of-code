#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d24_in.txt");
int main(){
    map<pair<int,int>,bool> honey_comb;
    int cnt = 0;
    for(int i = 0 ; i < 541 ; i++){
        string instruction;
        fin >> instruction;
        int s = instruction.size();
        int cur_x = 0, cur_y = 0;
        for(int j = 0 ; j < s ; j++){
            //cout << cur_x << " " << cur_y << endl;
            if(instruction[j] == 'e'){
                cur_x += 1;
            }
            else if(instruction[j] == 'w'){
                cur_x -= 1;
            }
            else{
                if(instruction[j] == 'n'){
                    j++;
                    if(instruction[j] == 'w'){
                        if(abs(cur_y) % 2 == 1)cur_x -= 1;
                        cur_y -= 1;
                    }
                    else{
                        if(abs(cur_y) % 2 == 0)cur_x += 1;
                        cur_y -= 1;
                    }
                }
                else{
                    j++;
                    if(instruction[j] == 'w'){
                        if(abs(cur_y) % 2 == 1)cur_x -= 1;
                        cur_y += 1;
                    }
                    else{
                        if(abs(cur_y) % 2 == 0)cur_x += 1;
                        cur_y += 1;
                    }
                }
            }
        }
        pair <int,int> cur_coord = make_pair(cur_x,cur_y);
        if(honey_comb[cur_coord]){
            honey_comb[cur_coord] = false;
            cnt--;
            //cout << cur_x << " " << cur_y << " off\n\n";
        }
        else{
            honey_comb[cur_coord] = true;
            cnt++;
            //cout << cur_x << " " << cur_y << " on\n\n";
        }
    }
    cout << cnt << endl;
}