#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin ("d23_in.txt");
int main(){
    int num[9];
    int next[9];
    for(int i = 0 ; i < 9 ; i++){
        fin >> num[i];
        next[i] = (i + 1) % 9;
    }
    
    int cur = 0;
    for(int i = 0 ; i < 100 ; i++){
        
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
                destination_cup = 9;
            }
        }
        //cout << destination_cup << endl;
        
        int destination_index = 0;
        for(int j = 0 ; j < 9 ; j++){
            if(num[j] == destination_cup){
                destination_index = j;
            }
        }
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

    int start = 0;
        for(int i = 0 ; i < 9 ; i++){
            cout << num[start];
            start = next[start];
        }
        cout << endl;
}