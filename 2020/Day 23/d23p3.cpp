#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d23_in.txt");
int cup_amt = 1000000;
int main(){
    int next[cup_amt + 1];
    int starting[9];
    for(int i = 0 ; i < 9 ; i++){
        fin >> starting[i];
    }
    for(int i = 0 ; i < 8 ; i++){
        next[starting[i]] = starting[i+1];
    }
    next[starting[8]] = 10;
    for(int i = 10 ; i <= cup_amt ; i++){
        if(i == cup_amt){
            next[cup_amt] = starting[0];
        }
        else{
            next[i] = i + 1;
        }
    }

    int cur = starting[0];
    for(int i = 0 ; i < 10000000 ; i++){
        int cur_next = next[cur];
        int remove_next = next[next[next[next[cur]]]];
        int cur_cup = cur;
        int cup1 = next[cur];
        int cup2 = next[next[cur]];
        int cup3 = next[next[next[cur]]];
        
        //cout << cup1 << " " << cup2 << " " << cup3 << " ";
        
        int destination_cup = cur_cup;
        while(destination_cup == cur_cup || destination_cup == cup1 || destination_cup == cup2 || destination_cup == cup3){
            destination_cup--;
            if(destination_cup == 0){
                destination_cup = cup_amt;
            }
        }
        //cout << destination_cup << endl;
        
        int destination_index = destination_cup;
        int destination_next = next[destination_index];
        int cup3_index = cup3;
        
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
    int start = 1;
    cout << next[start] << " " << next[next[start]] << endl;
}
