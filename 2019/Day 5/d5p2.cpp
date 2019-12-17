#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream codein ("day5_in.txt");
ofstream debug ("d5p2_debug.txt");
struct intcode{
    vector <int> program;
    int pointer;
    vector <int> input;
    vector <int> output;
};
int read(vector<int> &code, int pos, int mode){
    if(mode == 0){
        return code[code[pos]];
    }
    else{
        return code[pos];
    }
}
void write(vector<int> &code, int pos, int mode, int value){
    code[code[pos]] = value;
}
void op1(vector<int> &code, int &pos, int instruction){
    int mode_1 = (instruction / 100) % 10;
    int mode_2 = (instruction / 1000) % 10;
    int mode_3 = (instruction / 10000) % 10;
    write(code, pos + 3, mode_3 , read(code, pos + 1 , mode_1) + read(code, pos + 2 , mode_2));
    pos += 4;
}
void op2(vector<int> &code, int &pos, int instruction){
    int mode_1 = (instruction / 100) % 10;
    int mode_2 = (instruction / 1000) % 10;
    int mode_3 = (instruction / 10000) % 10;
    write(code, pos + 3, mode_3 , read(code, pos + 1 , mode_1) * read(code, pos + 2 , mode_2));
    pos += 4;
}
void op3(vector<int> &code, int &pos, int instruction, int input){
    write(code, pos + 1 , 0 , input);
    pos += 2;
}
void op4(vector<int> &code, int &pos, int instruction, vector<int> &output){
    int mode_1 = (instruction / 100) % 10;
    int value = read(code, pos + 1, mode_1);
    output.push_back(value);
    pos += 2;
}
void op5(vector<int> &code, int &pos, int instruction){
    int mode_1 = (instruction / 100) % 10;
    int mode_2 = (instruction / 1000) % 10;
    int first_num = read(code, pos + 1 , mode_1);
    int second_num = read(code, pos + 2 , mode_2);
    if(first_num != 0){
        pos = second_num;
    }
    else{
        pos += 3;
    }
}
void op6(vector<int> &code, int &pos, int instruction){
    int mode_1 = (instruction / 100) % 10;
    int mode_2 = (instruction / 1000) % 10;
    int first_num = read(code, pos + 1 , mode_1);
    int second_num = read(code, pos + 2 , mode_2);
    if(first_num == 0){
        pos = second_num;
    }
    else{
        pos += 3;
    }
}
void op7(vector<int> &code, int &pos, int instruction){
    int mode_1 = (instruction / 100) % 10;
    int mode_2 = (instruction / 1000) % 10;
    int mode_3 = (instruction / 10000) % 10;
    int first_num = read(code, pos + 1 , mode_1);
    int second_num = read(code, pos + 2 , mode_2);
    if(first_num < second_num){
        write(code, pos + 3, mode_3 , 1);
    }
    else{
        write(code, pos + 3, mode_3 , 0);
    }
    pos += 4;
}
void op8(vector<int> &code, int &pos, int instruction){
    int mode_1 = (instruction / 100) % 10;
    int mode_2 = (instruction / 1000) % 10;
    int mode_3 = (instruction / 10000) % 10;
    int first_num = read(code, pos + 1 , mode_1);
    int second_num = read(code, pos + 2 , mode_2);
    if(first_num == second_num){
        write(code, pos + 3, mode_3 , 1);
    }
    else{
        write(code, pos + 3, mode_3 , 0);
    }
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
        else if(a.program[a.pointer] % 100 == 3){
            if(a.input.size() > 0){
                op3(a.program, a.pointer, a.program[a.pointer], a.input[0]);
                a.input.erase(a.input.begin());
            }
            else{
                break;
            }
        }
        else if(a.program[a.pointer] % 100 == 4){
            op4(a.program, a.pointer, a.program[a.pointer], a.output);
        }
        else if(a.program[a.pointer] % 100 == 5){
            op5(a.program, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 6){
            op6(a.program, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 7){
            op7(a.program, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 8){
            op8(a.program, a.pointer, a.program[a.pointer]);
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
    intcode cpu;
    cpu.program = code;
    cpu.pointer = 0;
    cpu.input.push_back(5);
    cout << "Program Loaded\nNow Running...\n";
    intcode pgm = run(cpu);
    int s = pgm.output.size();
    for(int i = 0 ; i < s ; i++) cout << pgm.output[i] << " ";
}