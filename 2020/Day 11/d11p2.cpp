#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d11_in.txt");
ofstream vis ("visp2.txt");
int h = 99, w = 92;
int main(){
    char floor_plan[h + 2][w + 2];
    for(int i = 0 ; i < h + 2 ; i++){
        for(int j = 0 ; j < w + 2 ; j++){
            floor_plan[i][j] = '.';
        }
    }
    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= w ; j++){
            fin >> floor_plan[i][j];
            vis << floor_plan[i][j];
        }
        vis << endl;
    }
    vis << endl;
    char tmp[h + 2][w + 2];
    bool no_change = false;
    while(!no_change){

        for(int i = 1 ; i <= h ; i++){
            for(int j = 1 ; j <= w ; j++){
                tmp[i][j] = floor_plan[i][j];
            }
        }

        no_change = true;
        for(int i = 1 ; i <= h ; i++){
            for(int j = 1 ; j <= w ; j++){
                int cnt = 0;

                bool stop = false;
                for(int k = 1 ; !stop ; k++){
                    if(i - k == 0 || j - k == 0){
                        stop = true;
                    }
                    else{
                        if(floor_plan[i - k][j - k] == 'L'){
                            stop = true;
                        }
                        if(floor_plan[i - k][j - k] == '#'){
                            cnt++;
                            stop = true;
                        }
                    }
                }

                stop = false;
                for(int k = 1 ; !stop ; k++){
                    if(i - k == 0){
                        stop = true;
                    }
                    else{
                        if(floor_plan[i - k][j] == 'L'){
                            stop = true;
                        }
                        if(floor_plan[i - k][j] == '#'){
                            cnt++;
                            stop = true;
                        }
                    }
                }

                stop = false;
                for(int k = 1 ; !stop ; k++){
                    if(i - k == 0 || j + k == w + 1){
                        stop = true;
                    }
                    else{

                        if(floor_plan[i - k][j + k] == 'L'){
                            stop = true;
                        }
                        if(floor_plan[i - k][j + k] == '#'){
                            cnt++;
                            stop = true;
                        }
                    }
                }

                stop = false;
                for(int k = 1 ; !stop ; k++){
                    if(j - k == 0){
                        stop = true;
                    }
                    else{
                        if(floor_plan[i][j - k] == 'L'){
                            stop = true;
                        }
                        if(floor_plan[i][j - k] == '#'){
                            cnt++;
                            stop = true;
                        }
                    }
                }

                stop = false;
                for(int k = 1 ; !stop ; k++){
                    if(j + k == w + 1){
                        stop = true;
                    }
                    else{
                        if(floor_plan[i][j + k] == 'L'){
                            stop = true;
                        }
                        if(floor_plan[i][j + k] == '#'){
                            cnt++;
                            stop = true;
                        }
                    }
                }

                stop = false;
                for(int k = 1 ; !stop ; k++){
                    if(i + k == h + 1 || j - k == 0){
                        stop = true;
                    }
                    else{
                        if(floor_plan[i + k][j - k] == 'L'){
                            stop = true;
                        }
                        if(floor_plan[i + k][j - k] == '#'){
                            cnt++;
                            stop = true;
                        }
                    }
                }
                
                stop = false;
                for(int k = 1 ; !stop ; k++){
                    if(i + k == h + 1){
                        stop = true;
                    }
                    else{
                        if(floor_plan[i + k][j] == 'L'){
                            stop = true;
                        }
                        if(floor_plan[i + k][j] == '#'){
                            cnt++;
                            stop = true;
                        }
                    }
                }

                stop = false;
                for(int k = 1 ; !stop ; k++){
                    if(i + k == h + 1 || j + k == w + 1){
                        stop = true;
                    }
                    else{
                        if(floor_plan[i + k][j + k] == 'L'){
                            stop = true;
                        }
                        if(floor_plan[i + k][j + k] == '#'){
                            cnt++;
                            stop = true;
                        }
                    }
                }

                if(floor_plan[i][j] == 'L' && cnt == 0){
                    tmp[i][j] = '#';
                    no_change = false;
                }

                if(floor_plan[i][j] == '#' && cnt >= 5){
                    tmp[i][j] = 'L';
                    no_change = false;
                }

            }
        }

        for(int i = 1 ; i <= h ; i++){
            for(int j = 1 ; j <= w ; j++){
                floor_plan[i][j] = tmp[i][j];
                vis << floor_plan[i][j];
            }
            vis << endl;
        }
        vis << endl;
    }

    int ans = 0;

    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= w ; j++){
            if(floor_plan[i][j] == '#') ans++;
        }
    }
    cout << ans << endl;
}