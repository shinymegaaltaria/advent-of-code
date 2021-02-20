#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
ifstream codein ("day19_in.txt");
//ofstream debug ("d19p1_debug.txt");
struct intcode{
    map <long long int, long long int> program;
    long long int pointer;
    vector <long long int> input;
    vector <long long int> output;
    bool halt;
    long long int relative_base;
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
    }
    else{
        code.program[code.relative_base + code.program[pos]] = value;
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
intcode run(intcode a){
    while(a.halt == false){
        //debug << "cur pt: " << a.pointer << ", code[pointer]: " << a.program[a.pointer] << ", relative_base: " << a.relative_base << endl;
        if(a.program[a.pointer] % 100 == 1){
            op1(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 2){
            op2(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 3){
            if(a.input.size() > 0){
                op3(a, a.pointer, a.program[a.pointer], a.input[0]);
                a.input.erase(a.input.begin());
            }
            else{
                break;
            }
        }
        else if(a.program[a.pointer] % 100 == 4){
            op4(a, a.pointer, a.program[a.pointer], a.output);
        }
        else if(a.program[a.pointer] % 100 == 5){
            op5(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 6){
            op6(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 7){
            op7(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 8){
            op8(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] % 100 == 9){
            op9(a, a.pointer, a.program[a.pointer]);
        }
        else if(a.program[a.pointer] == 99){
            a.halt = true;
        }
    }
    return a;
}
int main(){
    map <long long int, long long int> code;
    long long int tmp;
    long long int i = 0;
    long long int cnt = 0;
    while(codein >> tmp){
        code[i] = tmp;
        i++;
    }
    
    
    int hi = 10000, lo = 0;
    int mid = 0;
    int offset_x[4] = {0,99,0,99};
    int offset_y[4] = {0,0,-99,-99};
    while(hi > lo){
        cout << hi << " " << lo << endl;
        bool check[4] = {false,false,false,false};
        mid = (hi + lo)/2;
        bool found_start = false;
        int start = mid;
        while(!found_start){
            intcode tmp;
            tmp.program = code;
            tmp.pointer = 0;
            tmp.halt = false;
            tmp.relative_base = 0;
            tmp.input.push_back(start);
            tmp.input.push_back(mid);
            tmp = run(tmp);
            if(tmp.output[0] == 1){
                found_start = true;
            }
            else{
                start++;
            }
        }
        intcode cpu[4];
        for(int i = 0 ; i < 4; i++){
            cpu[i].program = code;
            cpu[i].pointer = 0;
            cpu[i].halt = false;
            cpu[i].relative_base = 0;
            cpu[i].input.push_back(start + offset_x[i]);
            cpu[i].input.push_back(mid + offset_y[i]);
            cpu[i] = run(cpu[i]);
            check[i] = cpu[i].output[0];
        }
        
        if(check[0] && check[1] && check[2] && check[3]){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }

    }
    cout << hi << endl;
    hi = 911;
    int start = hi;
    bool found_start = false;
    while(!found_start){
        intcode tmp;
        tmp.program = code;
        tmp.pointer = 0;
        tmp.halt = false;
        tmp.relative_base = 0;
        tmp.input.push_back(start);
        tmp.input.push_back(hi);
        tmp = run(tmp);
        if(tmp.output[0] == 1){
            found_start = true;
        }
        else{
            start++;
        }
    }
    cout << start*10000 + hi - 99 << endl;
    bool frick = false;
    for(int i = hi - 99  ; i <= hi ; i++){
        for(int j = start ; j <= start+99 ; j++){
            intcode cpu;
            cpu.program = code;
            cpu.pointer = 0;
            cpu.halt = false;
            cpu.relative_base = 0;
            cpu.input.push_back(j);
            cpu.input.push_back(i);
            //cout << "Program Loaded\nNow Running...\nInput: " << i << " " << j << endl;
            cpu = run(cpu);
            if(cpu.output[0] == 0) frick = true;
        }
        //cout << endl;
    }
    if(frick)cout << "fuck";
}