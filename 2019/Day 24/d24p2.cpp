#include <iostream>
#include <map>
#include <fstream>
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
    int h = 5, w = 5, t = 200;
    map <coord,bool> planet;
    coord tmp_coord;
    tmp_coord.z = 0;
    for(tmp_coord.x = 0 ; tmp_coord.x < h ; tmp_coord.x++){
        for(tmp_coord.y = 0 ; tmp_coord.y < w ; tmp_coord.y++){
            char tmp;
            fin >> tmp;
            if(tmp == '#') planet[tmp_coord] = true;
            else planet[tmp_coord] = false;
        }
    }

    for(int cycle_no = 1 ; cycle_no <= t ; cycle_no++){
        cout << "Cycle no. " << cycle_no << ": ";
        int cnt = 0;
        map <coord, bool> tmp_planet;
        coord cur_coord;
        for(cur_coord.z = 0 - cycle_no; cur_coord.z <= 0 + cycle_no; cur_coord.z++){
            for(cur_coord.x = 0 ; cur_coord.x < h ; cur_coord.x++){
                for(cur_coord.y = 0 ; cur_coord.y < w ; cur_coord.y++){
                    if(cur_coord.x == 2 && cur_coord.y == 2) continue;
                    int neighbor_cnt = 0;
                    int offset_x[4] = {-1,0,1,0};
                    int offset_y[4] = {0,-1,0,1};
                    //cout << cur_coord.x << " " << cur_coord.y << " " << cur_coord.z << endl;
                    for(int i = 0 ; i < 4 ; i++){
                        coord tmp_coord = cur_coord;
                        tmp_coord.x = cur_coord.x + offset_x[i];
                        tmp_coord.y = cur_coord.y + offset_y[i];
                        if(tmp_coord.x == -1 || tmp_coord.x == 5 || tmp_coord.y == -1 || tmp_coord.y == 5){
                            tmp_coord.x = 2 + offset_x[i];
                            tmp_coord.y = 2 + offset_y[i];
                            tmp_coord.z = cur_coord.z - 1;
                            if(planet[tmp_coord]) neighbor_cnt++;
                        }
                        else if(tmp_coord.x == 2 && tmp_coord.y == 2){
                            if(i == 0){
                                tmp_coord.x = 4;
                                tmp_coord.z = cur_coord.z + 1;
                                for(tmp_coord.y = 0 ; tmp_coord.y < 5 ; tmp_coord.y++){
                                    if(planet[tmp_coord]) neighbor_cnt++;
                                }
                            }
                            else if(i == 1){
                                tmp_coord.y = 4;
                                tmp_coord.z = cur_coord.z + 1;
                                for(tmp_coord.x = 0 ; tmp_coord.x < 5 ; tmp_coord.x++){
                                    if(planet[tmp_coord]) neighbor_cnt++;
                                }
                            }
                            else if(i == 2){
                                tmp_coord.x = 0;
                                tmp_coord.z = cur_coord.z + 1;
                                for(tmp_coord.y = 0 ; tmp_coord.y < 5 ; tmp_coord.y++){
                                    if(planet[tmp_coord]) neighbor_cnt++;
                                }
                            }
                            else if(i == 3){
                                tmp_coord.y = 0;
                                tmp_coord.z = cur_coord.z + 1;
                                for(tmp_coord.x = 0 ; tmp_coord.x < 5 ; tmp_coord.x++){
                                    if(planet[tmp_coord]) neighbor_cnt++;
                                }
                            }
                        }
                        else{
                            if(planet[tmp_coord]) neighbor_cnt++;
                        }
                    }

                    if(planet[cur_coord]){
                        if(neighbor_cnt == 1){
                            tmp_planet[cur_coord] = true;
                            cnt++;
                            //cout << "alive " << cur_coord.x << " " << cur_coord.y << " " << cur_coord.z << endl;
                        }
                        else{
                            tmp_planet[cur_coord] = false;
                            //cout << "dead " << cur_coord.x << " " << cur_coord.y << " " << cur_coord.z << endl;
                        }
                    }
                    else{
                        if(neighbor_cnt == 1 || neighbor_cnt == 2){
                            tmp_planet[cur_coord] = true;
                            cnt++;
                            //cout << "alive " << cur_coord.x << " " << cur_coord.y << " " << cur_coord.z << endl;
                        }
                        else{
                            tmp_planet[cur_coord] = false;
                            //cout << "dead " << cur_coord.x << " " << cur_coord.y << " " << cur_coord.z << endl;
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
        planet = tmp_planet;
    }

    /*
    int rc = 0;
    coord print_coord;
    for(print_coord.z = -t ; print_coord.z <= t ; print_coord.z++){
        cout << print_coord.z << endl;
        for(print_coord.x = 0 ; print_coord.x < 5 ; print_coord.x++){
            for(print_coord.y = 0 ; print_coord.y < 5 ; print_coord.y++){
                cout << (char)(planet[print_coord] + '0');
                rc += planet[print_coord];
            }
            cout << endl;
        }
        cout << endl << endl << endl;
    }
    cout << rc << endl;
    */
}