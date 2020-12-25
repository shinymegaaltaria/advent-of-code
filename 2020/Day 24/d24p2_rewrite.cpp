#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d24_test.txt");
int main(){
    map<pair<int,int>,bool> honey_comb;
    int cnt = 0;

    int max_x = -2147483647;
    int max_y = -2147483647;
    int min_x = 2147483647;
    int min_y = 2147483647;

    for(int i = 0 ; i < 20 ; i++){
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
        min_x = min(min_x, cur_x);
        min_y = min(min_y, cur_y);
        max_x = max(max_x, cur_x);
        max_y = max(max_y, cur_y);

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
    
    cout << "Cycle #0: ";
    cnt = 0;
    for(int cur_x = min_x; cur_x <= max_x; cur_x++){
        for(int cur_y = min_y; cur_y <= max_y; cur_y++){
            if(honey_comb[make_pair(cur_x,cur_y)]){
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    for(int i = 1 ; i <= 10 ; i++){
        cout << "Cycle #" << i << ": \n";
        map<pair<int,int>,bool> tmp_honey_comb;
        for(int cur_x = min_x - i - 1 ; cur_x <= max_x + i + 1 ; cur_x++){
            for(int cur_y = min_y - i - 1 ; cur_y <= max_y + i + 1; cur_y++){
                int neighbour_cnt = 0;

                int tmp_x, tmp_y;
                
                tmp_x = cur_x;
                tmp_y = cur_y;
                tmp_x += 1;
                if(honey_comb[make_pair(tmp_x,tmp_y)]){
                    neighbour_cnt++;
                }

                tmp_x = cur_x;
                tmp_y = cur_y;
                tmp_x -= 1;
                if(honey_comb[make_pair(tmp_x,tmp_y)]){
                    neighbour_cnt++;
                }

                tmp_x = cur_x;
                tmp_y = cur_y;
                if(abs(tmp_y) % 2 == 1)tmp_x -= 1;
                tmp_y -= 1;
                if(honey_comb[make_pair(tmp_x,tmp_y)]){
                    neighbour_cnt++;
                }

                tmp_x = cur_x;
                tmp_y = cur_y;
                if(abs(tmp_y) % 2 == 0)tmp_x += 1;
                tmp_y -= 1;
                if(honey_comb[make_pair(tmp_x,tmp_y)]){
                    neighbour_cnt++;
                }

                tmp_x = cur_x;
                tmp_y = cur_y;
                if(abs(tmp_y) % 2 == 1)tmp_x -= 1;
                tmp_y += 1;
                if(honey_comb[make_pair(tmp_x,tmp_y)]){
                    neighbour_cnt++;
                }

                tmp_x = cur_x;
                tmp_y = cur_y;
                if(abs(tmp_y) % 2 == 0)tmp_x += 1;
                tmp_y += 1;
                if(honey_comb[make_pair(tmp_x,tmp_y)]){
                    neighbour_cnt++;
                }

                if(honey_comb[make_pair(cur_x,cur_y)]){
                    if(neighbour_cnt == 2 || neighbour_cnt == 3){
                        tmp_honey_comb[make_pair(cur_x,cur_y)] = true;
                    }
                    else{
                        tmp_honey_comb[make_pair(cur_x,cur_y)] = false;
                    }
                }
                else{
                    if(neighbour_cnt == 2){
                        tmp_honey_comb[make_pair(cur_x,cur_y)] = true;
                    }
                    else{
                        tmp_honey_comb[make_pair(cur_x,cur_y)] = false;
                    }
                }
            }
        }
        honey_comb = tmp_honey_comb;
        
        cnt = 0;
        for(int cur_x = min_x - i - 2; cur_x <= max_x + i + 2 ; cur_x++){
            for(int cur_y = min_y - i - 2 ; cur_y <= max_y + i + 2; cur_y++){
                if(honey_comb[make_pair(cur_x,cur_y)]){
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

}