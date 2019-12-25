#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream commandin ("day22_in.txt");
    vector<int> cards;
    int card_amount = 10007;
    for(int i = 0 ; i < card_amount ; i++){
        cards.push_back(i);
    }
    string instruction;
    while(commandin >> instruction){
        if(instruction == "ds"){
            reverse(cards.begin(),cards.end());
        }
        else if(instruction == "cut"){
            int tmp;
            commandin >> tmp;
            if(tmp < 0){
                tmp = card_amount + tmp;
            }
            vector<int> stack_1 = vector<int>(cards.begin(), cards.begin() + tmp);
            vector<int> stack_2 = vector<int>(cards.begin() + tmp, cards.end());
            stack_2.insert(stack_2.end(), stack_1.begin(), stack_1.end());
            cards = stack_2;
        }
        else{
            int tmp;
            commandin >> tmp;
            vector <int> new_cards = cards;
            for(int i = 0 ; i < card_amount ; i++){
                new_cards[(tmp*i) % card_amount] = cards[i];
            }
            cards = new_cards;
        }
    }
    for(int i = 0 ; i < card_amount ; i++){
        if(cards[i] == 2019) cout << i << endl;
    }
}