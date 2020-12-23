#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d23_in.txt");
int cup_amt = 1000000;
int main(){
    map<int,int> num;
    map<int,int> next;
    map<int,int> location;
    for(int i = 0 ; i < cup_amt ; i++){
        if(i < 9){
            fin >> num[i];
            location[num[i]] = i;
        }
        else{
            num[i] = i + 1;
            location[num[i]] = i;
        }
        next[i] = (i + 1) % cup_amt;
    }

    int cur = 0;
    for(int i = 0 ; i < cup_amt*10 ; i++){
        int cur_next = next[cur];
        int remove_next = next[next[next[next[cur]]]];
        int cur_cup = num[cur];
        int cup1 = num[next[cur]];
        int cup2 = num[next[next[cur]]];
        int cup3 = num[next[next[next[cur]]]];
        
        //cout << cup1 << " " << cup2 << " " << cup3 << " ";
        
        int destination_cup = cur_cup;
        while(destination_cup == cur_cup || destination_cup == cup1 || destination_cup == cup2 || destination_cup == cup3){
            destination_cup--;
            if(destination_cup == 0){
                destination_cup = cup_amt;
            }
        }
        //cout << destination_cup << endl;
        
        int destination_index = location[destination_cup];
        int destination_next = next[destination_index];
        int cup3_index = next[next[next[cur]]];
        
        /*
        cout << cur_next << " " << remove_next << " " << destination_next << endl;
        cout << destination_index << " " << cur_next << endl;
        cout << cur << " " << remove_next << endl;
        cout << cup3_index << " " << destination_next << endl;
        */
        
        next[destination_index] = cur_next;
        next[cur] = remove_next;
        next[cup3_index] = destination_next;

        cur = next[cur];
        
    }
    int start = location[1];
    cout << num[next[start]] << " " << num[next[next[start]]] << endl;
}
