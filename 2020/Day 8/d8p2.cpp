#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
ifstream fin ("d8_in.txt");
vector <pair <string, int> > program;
pair <bool, int> run(){
    map <int, int> lol;
    int acc = 0;
    int cur_pt = 0;
    while(cur_pt != 613){
        if(lol[cur_pt]){
            return make_pair(false,acc);
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
    return make_pair(true,acc);
}
int main(){
    for(int i = 0 ; i < 613 ; i++){
        string op;
        int tmp;
        fin >> op >> tmp;
        program.push_back(make_pair(op,tmp));
    }
    for(int i = 0 ; i < 613 ; i++){
        if(program[i].first == "nop"){
            program[i].first = "jmp";
            pair <bool, int> result = run();
            if(result.first){
                cout << result.second << endl;
                return 0;
            }
            program[i].first = "nop";
        }
        else if(program[i].first == "jmp"){
            program[i].first = "nop";
            pair <bool, int> result = run();
            if(result.first){
                cout << result.second << endl;
                return 0;
            }
            program[i].first = "jmp";
        }
    }
}