#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
ifstream codein ("d23_in.txt");
ofstream debug ("intcode_debug.txt");
struct intcode{
    map <long long int, long long int> program;
    long long int pointer;
    vector <long long int> input;
    vector <long long int> output;
    bool halt;
    long long int relative_base;
    long long int id;
    bool req_input;
    bool hv_output;
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
    debug << code.op_cnt << ": id " << code.id << " received input: " << input << endl;
    pos += 2;
}
void op4(intcode &code, long long int &pos, long long int instruction, vector<long long int> &output){
    long long int mode_1 = (instruction / 100) % 10;
    long long int value = read(code, pos + 1, mode_1);
    output.push_back(value);
    debug << code.op_cnt << ": id " << code.id << " outputs: " << value << endl;
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
intcode step(intcode a){
    a.op_cnt += 1;
    /*
    if(a.op_cnt % 100 == 0){
        cout << "id " << a.id << " has reached " << a.op_cnt << " operations!\n";
        //cout << "cur pt: " << a.pointer << ", code[pointer]: " << a.program[a.pointer] << ", relative_base: " << a.relative_base << endl;
    }*/
    if(a.halt == false){
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
                a.req_input = true;
            }
        }
        else if(a.program[a.pointer] % 100 == 4){
            op4(a, a.pointer, a.program[a.pointer], a.output);
            if(a.output.size() == 3){
            	debug << a.op_cnt << ": id " << a.id << " sends X = " << a.output[1] << ", Y = " << a.output[2] << " to id " << a.output[0] << endl;
            	a.hv_output = true;
			}
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
    while(codein >> tmp){
        code[i] = tmp;
        i++;
    }
    intcode network[50];
    
    for(int i = 0 ; i < 50 ; i++){
        network[i].program = code;
        network[i].pointer = 0;
        network[i].halt = false;
        network[i].relative_base = 0;
        network[i].id = i;
        network[i].req_input = false;
        network[i].input.push_back(i);
        network[i].hv_output = false;
        network[i].op_cnt = 0;
    }

    int step_cnt = 0;
    while(true){
        step_cnt += 1;
        if(step_cnt % 100 == 0){
            cout << step_cnt << " operations!\n";
        }
        vector <pair <long long int, pair<long long int, long long int> > > packets; 
        for(int i = 0 ; i < 50 ; i++){
            network[i] = step(network[i]);
            if(network[i].hv_output){
                cout << "id " << i << " sends X = " << network[i].output[1] << ", Y = " << network[i].output[2] << " to id " << network[i].output[0] << endl;
                if(network[i].output[0] == 255){
                    cout << "OVER\n";
                    return 0;
                }
				else{
	                packets.push_back(make_pair(network[i].output[0],make_pair(network[i].output[1],network[i].output[2])));
	                network[i].output.erase(network[i].output.begin(),network[i].output.begin() + 3);
	                network[i].hv_output = false;
				}
            }
            if(network[i].req_input){
                network[i].input.push_back(-1);
                network[i].req_input = false;
            }
        }
        int s = packets.size();
        for(int i = 0 ; i < s ; i++){
            network[packets[i].first].input.push_back(packets[i].second.first);
            network[packets[i].first].input.push_back(packets[i].second.second);
        }
    }
}
