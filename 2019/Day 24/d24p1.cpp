#include <iostream>
#include <map>
#include <fstream>
using namespace std;
bool planet[7][7] = {false};
ofstream debug ("debug.txt");
int bio(){
    int score = 0;
    for(int i = 0 ; i < 25 ; i++){
        score += planet[i / 5 + 1][i % 5 + 1] * (1<<i);
    }
    return score;
}
void update(){
    bool planet_copy[7][7] = {false};
    for(int i = 1 ; i <= 5 ; i++){
        for(int j = 1 ; j <= 5 ; j++){
            int adj_bug = planet[i - 1][j] + planet[i + 1][j] + planet[i][j - 1] + planet[i][j + 1];
            if(planet[i][j]){
                if(adj_bug == 1){
                    planet_copy[i][j] = true;
                }
                else{
                    planet_copy[i][j] = false;
                }
            }
            else{
                if(adj_bug == 1 || adj_bug == 2){
                    planet_copy[i][j] = true;
                }
                else{
                    planet_copy[i][j] = false;
                }
            }
        }
    }
    for(int i = 0 ; i < 7 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            planet[i][j] = planet_copy[i][j];
        }
    }
}
void print(){
    for(int i = 1 ; i <= 5 ; i++){
        for(int j = 1 ; j <= 5 ; j++){
            if(planet[i][j]) debug << '#';
            else debug << '.';
        }
        debug << endl;
    }
    debug << endl << endl << endl; 
}
int main(){
    map<int,bool> appear;
    for(int i = 1 ; i <= 5 ; i++){
        for(int j = 1 ; j <= 5 ; j++){
            char bug;
            cin >> bug;
            planet[i][j] = (bug == '#');
        }
    }
    int planet_score = bio();
    appear[planet_score] = true;
    while(true){
        update();
        print();
        planet_score = bio();
        if(appear[planet_score]){
            cout << planet_score << endl;
            return 0;
        }
        else{
            appear[planet_score] = true;
        }
    }
}
