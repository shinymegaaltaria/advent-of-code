#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("d1_in.txt");
int main(){
    string building;
    fin >> building;
    int s = building.size();
    int cur_floor = 0;
    for(int i = 0 ; i < s ; i++){
        if(building[i]=='(') cur_floor++;
        else cur_floor--;
    }
    cout << cur_floor << endl;
}