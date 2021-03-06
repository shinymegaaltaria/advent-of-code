#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
ifstream codein ("bsgs.ic");
ofstream debug ("bsgs_debug.txt");
ofstream codedump ("code_dump.txt");
struct intcode{
    map <long long int, long long int> program;
    long long int pointer;
    vector <long long int> input;
    vector <long long int> output;
    bool halt;
    long long int relative_base;
    long long int op_cnt;
};
long long int read(intcode &code, long long int pos, long long int mode){
    if(mode == 0){
        return code.program[code.program[pos]];
    }
    else if (mode == 1){
        return code.program[pos];
    }
    else{
        return code.program[code.relative_base + code.program[pos]];
    }
}
void write(intcode &code, long long int pos, long long int mode, long long int value){
    if(mode == 0){
        code.program[code.program[pos]] = value;
        debug << "," << code.program[pos] << " " << value;
    }
    else{
        code.program[code.relative_base + code.program[pos]] = value;
        debug << "," << code.relative_base + code.program[pos] << " " << value;
    }
}
void op1(intcode &code, long long int &pos, long long int instruction){
    long long int mode_1 = (instruction / 100) % 10;
    long long int mode_2 = (instruction / 1000) % 10;
    long long int mode_3 = (instruction / 10000) % 10;
    write(code, pos + 3, mode_3 , read(code, pos + 1 , mode_1) + read(code, pos + 2 , mode_2));
    pos += 4;
}
void op2(intcode &code, long long int &pos, long long int instruction){
    long long int mode_1 = (instruction / 100) % 10;
    long long int mode_2 = (instruction / 1000) % 10;
    long long int mode_3 = (instruction / 10000) % 10;
    write(code, pos + 3, mode_3 , read(code, pos + 1 , mode_1) * read(code, pos + 2 , mode_2));
    pos += 4;
}
void op3(intcode &code, long long int &pos, long long int instruction, long long int input){
    long long int mode_1 = (instruction / 100) % 10;
    write(code, pos + 1 , mode_1 , input);
    pos += 2;
}
void op4(intcode &code, long long int &pos, long long int instruction, vector<long long int> &output){
    long long int mode_1 = (instruction / 100) % 10;
    long long int value = read(code, pos + 1, mode_1);
    output.push_back(value);
    pos += 2;
}
void op5(intcode &code, long long int &pos, long long int instruction){
    long long int mode_1 = (instruction / 100) % 10;
    long long int mode_2 = (instruction / 1000) % 10;
    long long int first_num = read(code, pos + 1 , mode_1);
    long long int second_num = read(code, pos + 2 , mode_2);
    if(first_num != 0){
        pos = second_num;
    }
    else{
        pos += 3;
    }
}
void op6(intcode &code, long long int &pos, long long int instruction){
    long long int mode_1 = (instruction / 100) % 10;
    long long int mode_2 = (instruction / 1000) % 10;
    long long int first_num = read(code, pos + 1 , mode_1);
    long long int second_num = read(code, pos + 2 , mode_2);
    if(first_num == 0){
        pos = second_num;
    }
    else{
        pos += 3;
    }
}
void op7(intcode &code, long long int &pos, long long int instruction){
    long long int mode_1 = (instruction / 100) % 10;
    long long int mode_2 = (instruction / 1000) % 10;
    long long int mode_3 = (instruction / 10000) % 10;
    long long int first_num = read(code, pos + 1 , mode_1);
    long long int second_num = read(code, pos + 2 , mode_2);
    if(first_num < second_num){
        write(code, pos + 3, mode_3 , 1);
    }
    else{
        write(code, pos + 3, mode_3 , 0);
    }
    pos += 4;
}
void op8(intcode &code, long long int &pos, long long int instruction){
    long long int mode_1 = (instruction / 100) % 10;
    long long int mode_2 = (instruction / 1000) % 10;
    long long int mode_3 = (instruction / 10000) % 10;
    long long int first_num = read(code, pos + 1 , mode_1);
    long long int second_num = read(code, pos + 2 , mode_2);
    if(first_num == second_num){
        write(code, pos + 3, mode_3 , 1);
    }
    else{
        write(code, pos + 3, mode_3 , 0);
    }
    pos += 4;
}
void op9(intcode &code, long long int &pos, long long int instruction){
    long long int mode_1 = (instruction / 100) % 10;
    code.relative_base += read(code, pos + 1, mode_1);
    pos += 2;
}

void op10(intcode &code, long long int &pos, long long int instruction){
    long long int mode_1 = (instruction / 100) % 10;
    long long int value = read(code, pos + 1, mode_1);
    if(value % 10000 == 0){
        cout << value << endl;
    }
    pos += 2;
}
intcode run(intcode a){
    while(a.halt == false){
        a.op_cnt += 1;
        /*
        if(a.op_cnt % 100000 == 0){
            cout << a.op_cnt << endl;
        }*/
        //debug << "op no: " << a.op_cnt << ", pointer: " << a.pointer << ", instruction: ";
        
        if(a.op_cnt == 1 || a.op_cnt == 150915){
            for(int i = 0 ; i < 817 ; i++) codedump << a.program[i] << ",";
            codedump << a.program[817] <<endl;
            for(int i = 0 ; i < 14 ; i++) codedump << a.program[4000 + i] << ",";
            codedump << a.program[4014] << endl;
        }
        
        debug << a.op_cnt << "," << a.pointer << ",";
        if(a.program[a.pointer] % 100 == 1){
            debug << a.program[a.pointer] << " " << a.program[a.pointer + 1] << " " << a.program[a.pointer + 2] << " " << a.program[a.pointer + 3];
            op1(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 2){
            debug << a.program[a.pointer] << " " << a.program[a.pointer + 1] << " " << a.program[a.pointer + 2] << " " << a.program[a.pointer + 3];
            op2(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 3){
            debug << a.program[a.pointer] << " " << a.program[a.pointer + 1];
            if(a.input.size() > 0){
                op3(a, a.pointer, a.program[a.pointer], a.input[0]);
                a.input.erase(a.input.begin());
            }
            else{
                break;
            }
        }
        else if(a.program[a.pointer] % 100 == 4){
            debug << a.program[a.pointer] << " " << a.program[a.pointer + 1];
            op4(a, a.pointer, a.program[a.pointer], a.output);
        }
        else if(a.program[a.pointer] % 100 == 5){
            debug << a.program[a.pointer] << " " << a.program[a.pointer + 1] << " " << a.program[a.pointer + 2];
            op5(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 6){
            debug << a.program[a.pointer] << " " << a.program[a.pointer + 1] << " " << a.program[a.pointer + 2];
            op6(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 7){
            debug << a.program[a.pointer] << " " << a.program[a.pointer + 1] << " " << a.program[a.pointer + 2] << " " << a.program[a.pointer + 3];
            op7(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 8){
            debug << a.program[a.pointer] << " " << a.program[a.pointer + 1] << " " << a.program[a.pointer + 2] << " " << a.program[a.pointer + 3];
            op8(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 9){
            debug << a.program[a.pointer] << " " << a.program[a.pointer + 1];
            op9(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 10){
            op10(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] == 99){
            debug << a.program[a.pointer] << endl;
            a.halt = true;
        }
        //debug << a.program[4006] << " " << a.program[4005] << endl;
        debug << endl;
    }
    return a;
}
int main(){
    map <long long int, long long int> code;
    long long int tmp;
    long long int i = 0;
    while(codein >> tmp){
        code[i] = tmp;
        i++;
    }
    intcode cpu;
    cpu.program = code;
    cpu.pointer = 0;
    cpu.halt = false;
    cpu.relative_base = 0;
    cpu.op_cnt = 0;
    cout << "Program Loaded\nNow Running...\n";

    /*
    //Sample
    cpu.input.push_back(5764801);
    cpu.input.push_back(17807724);
    */

    
    //Real
    cpu.input.push_back(9717666);
    cpu.input.push_back(20089533);
    
    cpu = run(cpu);
    long long int s = cpu.output.size();
    for(int i = 0 ; i < s ; i++){
        cout << cpu.output[i] << endl;
    }
    cout << "Number of operations: " << cpu.op_cnt << endl;
    return 0;
}