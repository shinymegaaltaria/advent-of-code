#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
ifstream fin ("d8_in.txt");
int main(){
    map <int, int> lol;
    vector <pair <string, int> > program;
    for(int i = 0 ; i < 613 ; i++){
        string op;
        int tmp;
        fin >> op >> tmp;
        program.push_back(make_pair(op,tmp));
    }
    int acc = 0;
    int cur_pt = 0;
    while(true){
        if(lol[cur_pt]){
            cout << acc << endl;
            return 0;
        }
        else{
            lol[cur_pt] = true;
            if(program[cur_pt].first == "acc"){
                acc += program[cur_pt].second;
                cur_pt++;
            }
            else if(program[cur_pt].first == "nop"){
                cur_pt++;
            }
            else if(program[cur_pt].first == "jmp"){
                cur_pt += program[cur_pt].second;
            }
            
        }
    }
}