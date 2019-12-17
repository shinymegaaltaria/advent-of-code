#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <queue>
using namespace std;
ifstream codein ("day15_in.txt");
ofstream debug ("intcode_debug.txt");
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
        debug << "cur pt: " << a.pointer << ", code[pointer]: " << a.program[a.pointer] << ", relative_base: " << a.relative_base << endl;
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
    map <pair<long long int,long long int>, bool> visited;
    map <pair<long long int, long long int>, bool> maze;
    long long int cur_X = 0, cur_Y = 0;
    long long int target_X = 0, target_Y = 0;
    visited[make_pair(cur_X,cur_Y)] = true;
    queue < pair< pair<long long int, long long int> , intcode> > bfs;
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
    cout << "Program Loaded\nNow Running...\n";
    bfs.push(make_pair(make_pair(cur_X,cur_Y),cpu));
    while(!bfs.empty()){
        pair< pair<long long int, long long int> , intcode> cur_state = bfs.front();
        bfs.pop();
        long long int cur_X = cur_state.first.first;
        long long int cur_Y = cur_state.first.second;
        intcode cur_pgm = cur_state.second;
        if(!visited[make_pair(cur_X,cur_Y + 1)] && !maze[make_pair(cur_X,cur_Y + 1)]){
            intcode test = cur_pgm;
            test.input.push_back(1);
            test = run(test);
            long long int result = test.output[0];
            test.output.erase(test.output.begin(),test.out.end());
            if(result == 0){
                visited[make_pair(cur_X,cur_Y + 1)] = true;
                maze[make_pair(cur_X,cur_Y + 1)] = false;
            }
            else if(result == 1){
                visited[make_pair(cur_X,cur_Y + 1)] = true;
                bfs.push(make_pair(make_pair(cur_X,cur_Y + 1),test));
            }
            else if(result == 2){
                target_X = cur_X;
                target_Y = cur_Y + 1;
                visited[make_pair(cur_X,cur_Y + 1)] = true;
                bfs.push(make_pair(make_pair(cur_X,cur_Y + 1),test));
            }
        }
        else if(!visited[make_pair(cur_X,cur_Y - 1)] && !maze[make_pair(cur_X,cur_Y - 1)]){
            intcode test = cur_pgm;
            test.input.push_back(2);
            test = run(test);
            long long int result = test.output[0];
            test.output.erase(test.output.begin(),test.out.end());
            if(result == 0){
                visited[make_pair(cur_X,cur_Y - 1)] = true;
                maze[make_pair(cur_X,cur_Y - 1)] = false;
            }
            else if(result == 1){
                visited[make_pair(cur_X,cur_Y - 1)] = true;
                bfs.push(make_pair(make_pair(cur_X,cur_Y - 1),test));
            }
            else if(result == 2){
                target_X = cur_X;
                target_Y = cur_Y - 1;
                visited[make_pair(cur_X,cur_Y - 1)] = true;
                bfs.push(make_pair(make_pair(cur_X,cur_Y - 1),test));
            }
        }
        else if(!visited[make_pair(cur_X - 1,cur_Y)] && !maze[make_pair(cur_X - 1,cur_Y)]){
            intcode test = cur_pgm;
            test.input.push_back(3);
            test = run(test);
            long long int result = test.output[0];
            test.output.erase(test.output.begin(),test.out.end());
            if(result == 0){
                visited[make_pair(cur_X - 1,cur_Y)] = true;
                maze[make_pair(cur_X - 1,cur_Y)] = false;
            }
            else if(result == 1){
                visited[make_pair(cur_X - 1,cur_Y)] = true;
                bfs.push(make_pair(make_pair(cur_X - 1,cur_Y),test));
            }
            else if(result == 2){
                target_X = cur_X - 1;
                target_Y = cur_Y;
                visited[make_pair(cur_X - 1,cur_Y)] = true;
                bfs.push(make_pair(make_pair(cur_X - 1,cur_Y),test));
            }
        }
        else if(!visited[make_pair(cur_X - 1,cur_Y)] && !maze[make_pair(cur_X - 1,cur_Y)]){
            intcode test = cur_pgm;
            test.input.push_back(4);
            test = run(test);
            long long int result = test.output[0];
            test.output.erase(test.output.begin(),test.out.end());
            if(result == 0){
                visited[make_pair(cur_X + 1,cur_Y)] = true;
                maze[make_pair(cur_X + 1,cur_Y)] = false;
            }
            else if(result == 1){
                visited[make_pair(cur_X + 1,cur_Y)] = true;
                bfs.push(make_pair(make_pair(cur_X + 1,cur_Y),test));
            }
            else if(result == 2){
                target_X = cur_X + 1;
                target_Y = cur_Y;
                visited[make_pair(cur_X + 1,cur_Y)] = true;
                bfs.push(make_pair(make_pair(cur_X + 1,cur_Y),test));
            }
        }
    }
    queue <pair<long long int, long long int> > bfs_1;
    bfs_1.push(make_pair(0,0));
    //I actually forgot what I am supposed to do so Im gonna rewrite later
    long long int s = cpu.output.size();
    for(long long int i = 0 ; i < s ; i++) cout << cpu.output[i] << " ";
}