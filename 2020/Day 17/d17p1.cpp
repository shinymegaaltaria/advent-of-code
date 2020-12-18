#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d17_in.txt");
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
    int h = 8, w = 8, t = 6;
    map <coord, bool> conway_cube;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            char tmp;
            fin >> tmp;
            coord tmp_coord;
            tmp_coord.x = i;
            tmp_coord.y = 0;
            tmp_coord.z = j;
            if(tmp == '#'){
                conway_cube[tmp_coord] = true;
            }
            else{
                conway_cube[tmp_coord] = false;
            }
        }
    }
    
    for(int i = 1 ; i <= t ; i++){
        cout << "Cycle #" << i << endl;
        map <coord,bool> tmp_conway_cube;
        for(int j = 0 - i ; j < h + i ; j++){
            for(int k = 0 - i; k <= i ; k++){
                for(int l = 0 - i ; l < w + i; l++){
                    coord cur_coord;
                    cur_coord.x = j;
                    cur_coord.y = k;
                    cur_coord.z = l;
                    int cnt = 0;
                    for(int m = -1 ; m <= 1; m++){
                        for(int n = -1 ; n <= 1 ; n++){
                            for(int o = -1 ; o <= 1 ; o++){
                                if(m == 0 && n == 0 && o == 0){
                                    continue;
                                }
                                else{
                                    coord tmp_coord;
                                    tmp_coord.x = cur_coord.x + m;
                                    tmp_coord.y = cur_coord.y + n;
                                    tmp_coord.z = cur_coord.z + o;
                                    if(conway_cube[tmp_coord]){
                                        cnt++;
                                    }
                                }
                            }
                        }
                    }
                    if(conway_cube[cur_coord]){
                        if(cnt == 2 || cnt == 3){
                            tmp_conway_cube[cur_coord] = true;
                        }
                        else{
                            tmp_conway_cube[cur_coord] = false;
                        }
                    }
                    else{
                        if(cnt == 3){
                            tmp_conway_cube[cur_coord] = true;
                        }
                        else{
                            tmp_conway_cube[cur_coord] = false;
                        }
                    }
                }
            }
        }
        conway_cube = tmp_conway_cube;
        for(int j = 0 - i ; j <= i ; j++){
            for(int k = 0 - i; k < h + i ; k++){
                for(int l = 0 - i ; l < w + i; l++){
                    coord cur_coord;
                    cur_coord.x = k;
                    cur_coord.y = j;
                    cur_coord.z = l;
                    //if(conway_cube[cur_coord]) cout << '#';
                    //else cout << '.';
                }
                //cout << endl;
            }
            //cout << endl;
        }
    }

    int ans = 0;

    for(int i = -t ; i < t + h ; i++){
        for(int j = -t ; j <= t ; j++){
            for(int k = -t ; k < t + w ; k++){
                coord cur_coord;
                cur_coord.x = i;
                cur_coord.y = j;
                cur_coord.z = k;
                if(conway_cube[cur_coord]){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}