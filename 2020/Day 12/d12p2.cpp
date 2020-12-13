#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d12_in.txt");
int main(){
    int cur_dir = 0; //0E, 1S, 2W, 3N
    string directions = "ESWN";
    int ship_X = 0, ship_Y = 0;
    int way_X = 10, way_Y = 1;
    for(int i = 0 ; i < 769 ; i++){
        char direction;
        int param;
        fin >> direction >> param;
        if(direction == 'F'){
            ship_X += param * way_X;
            ship_Y += param * way_Y;
        }
        if(direction == 'N'){
            way_Y += param;
        }
        else if(direction == 'S'){
            way_Y -= param;
        }
        else if(direction == 'W'){
            way_X -= param;
        }
        else if(direction == 'E'){
            way_X += param;
        }
        else if(direction == 'L'){
            if(param == 90){

                int tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;
                
                tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;

                tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;
            }
            else if(param == 180){
                
                int tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;

                tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;
            }
            else if(param == 270){
                int tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;
            }
        }
        else if(direction == 'R'){
            if(param == 90){
                int tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;
            }
            else if(param == 180){

                int tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;

                tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;
            }
            else if(param == 270){
                int tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;
                
                tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;

                tmp = way_X;
                way_X = way_Y;
                way_Y = -1 * tmp;
            }
        }
        //cout << ship_X << " " << ship_Y << " " << way_X << " " << way_Y << endl;
    }
    cout << abs(ship_X) + abs(ship_Y) << endl;
}