#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream codein ("day2_in.txt");
ofstream debug ("d2p1_debug.txt");
struct intcode{
    vector <int> program;
    int pointer;
};
int read(vector<int> &code, int mode, int pos){
    return code[code[pos]];
}
void write(vector<int> &code, int pos, int mode, int value){
    code[code[pos]] = value;
}
void op1(vector<int> &code, int &pos, int instruction){
    write(code, pos + 3, 0, read(code, 0, pos + 1) + read(code, 0 , pos + 2));
    pos += 4;
}
void op2(vector<int> &code, int &pos, int instruction){
    write(code, pos + 3, 0, read(code, 0, pos + 1) * read(code, 0 , pos + 2));
    pos += 4;
}
intcode run(intcode a){
    while(true){
        debug << "cur pt: " << a.pointer << ", code[pointer]: " << a.program[a.pointer] << endl;
        if(a.program[a.pointer] % 100 == 1){
            op1(a.program, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 2){
            op2(a.program, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] == 99){
            break;
        }
    }
    return a;
}
int main(){
    vector <int> code;
    int tmp;
    while(codein >> tmp){
        code.push_back(tmp);
    }
    code[1] = 12;
    code[2] = 2;
    intcode cpu;
    cpu.program = code;
    cpu.pointer = 0;
    cout << "Program Loaded\nNow Running...\n";
    intcode pgm = run(cpu);
    cout << pgm.program[0] << endl;
}