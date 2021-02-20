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
    int max_x = -2147483647;
    int min_x = 2147483647;
    int max_y = -2147483647;
    int min_y = 2147483647;
    int max_z = -2147483647;
    int min_z = 2147483647;
    int p1_cnt = 0;
    int pic_need = 0;
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
                p1_cnt += 1;
            }
            else if(instruction[j] == 'w'){
                cur_x -= 1;
                cur_y += 1;
                p1_cnt += 1;
            }
            else{
                if(instruction[j] == 'n'){
                    j++;
                    if(instruction[j] == 'w'){
                        cur_z -= 1;
                        cur_y += 1;
                        p1_cnt += 1;
                    }
                    else{
                        cur_z -= 1;
                        cur_x += 1;
                        p1_cnt += 1;
                    }
                }
                else{
                    j++;
                    if(instruction[j] == 'w'){
                        cur_x -= 1;
                        cur_z += 1;
                        p1_cnt += 1;
                    }
                    else{
                        cur_y -= 1;
                        cur_z += 1;
                        p1_cnt += 1;
                    }
                }
            }
        }
        coord cur_coord;
        cur_coord.x = cur_x;
        cur_coord.y = cur_y;
        cur_coord.z = cur_z;

        max_x = max(cur_x,max_x);
        max_y = max(cur_y,max_y);
        max_z = max(cur_z,max_z);
        min_x = min(cur_x,min_x);
        min_y = min(cur_y,min_y);
        min_z = min(cur_z,min_z);

        if(honey_comb[cur_coord]){
            honey_comb[cur_coord] = false;
            cnt--;
        }
        else{
            honey_comb[cur_coord] = true;
            cnt++;
        }
    }
    cout << "p1_cnt: " << p1_cnt << endl;

    cout << "Ranges:\n";
    cout << min_x << " " << max_x << endl;
    cout << min_y << " " << max_y << endl;
    cout << min_z << " " << max_z << endl;

    cout << "Cycle #0: " << cnt << endl;
    
    for(int i = 1 ; i <= 100 ; i++){
        cout << "Cycle #" << i << ": ";
        cnt = 0;
        coord cur_coord;
        map <coord,bool> tmp_honey_comb = honey_comb;
        for(cur_coord.x = min_x - i ; cur_coord.x <= max_x + i ; cur_coord.x++){
            for(cur_coord.y = min_y - i ; cur_coord.y <= max_y + i ; cur_coord.y++){
                cur_coord.z = 0 - cur_coord.x - cur_coord.y;
                int neighbour_cnt = 0;

                coord tmp_coord = cur_coord;
                tmp_coord.x--;
                tmp_coord.y++;
                if(honey_comb[tmp_coord]) neighbour_cnt++;

                tmp_coord = cur_coord;
                tmp_coord.x--;
                tmp_coord.z++;
                if(honey_comb[tmp_coord]) neighbour_cnt++;

                tmp_coord = cur_coord;
                tmp_coord.y--;
                tmp_coord.z++;
                if(honey_comb[tmp_coord]) neighbour_cnt++;

                tmp_coord = cur_coord;
                tmp_coord.x++;
                tmp_coord.y--;
                if(honey_comb[tmp_coord]) neighbour_cnt++;

                tmp_coord = cur_coord;
                tmp_coord.x++;
                tmp_coord.z--;
                if(honey_comb[tmp_coord]) neighbour_cnt++;

                tmp_coord = cur_coord;
                tmp_coord.y++;
                tmp_coord.z--;
                if(honey_comb[tmp_coord]) neighbour_cnt++;

                if(honey_comb[cur_coord]){
                    if(neighbour_cnt == 1 || neighbour_cnt == 2){
                        tmp_honey_comb[cur_coord] = true;
                        cnt++;
                    }
                    else{
                        tmp_honey_comb[cur_coord] = false;
                    }
                }
                else{
                    if(neighbour_cnt == 2){
                        tmp_honey_comb[cur_coord] = true;
                        cnt++;
                    }
                    else{
                        tmp_honey_comb[cur_coord] = false;
                    }
                }
            }
        }
        cout << cnt << endl;
        pic_need += cnt;
        honey_comb = tmp_honey_comb;
    }

    cout << "pic need: " << pic_need << endl;
    /*
    cnt = 0;

    coord cur_coord;
    for(cur_coord.x = min_x - 100 ; cur_coord.x <= max_x + 100 ; cur_coord.x++){
        for(cur_coord.y = min_y - 100 ; cur_coord.y <= max_y + 100 ; cur_coord.y++){
            cur_coord.z = 0 - cur_coord.x - cur_coord.y;
            if(honey_comb[cur_coord]) cnt++;
        }
    }

    cout << cnt << endl;
    */
}

//https://www.redblobgames.com/grids/hexagons/