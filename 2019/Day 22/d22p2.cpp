#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream commandin ("day22_in.txt");
    vector<long long int> cards;
    long long int card_amount = 119315717514047;
    for(long long int i = 0 ; i < card_amount ; i++){
        cards.push_back(i);
    }
    string instruction;
    while(commandin >> instruction){
        if(instruction == "ds"){
            reverse(cards.begin(),cards.end());
        }
        else if(instruction == "cut"){
            long long int tmp;
            commandin >> tmp;
            if(tmp < 0){
                tmp = card_amount + tmp;
            }
            vector<long long int> stack_1 = vector<long long int>(cards.begin(), cards.begin() + tmp);
            vector<long long int> stack_2 = vector<long long int>(cards.begin() + tmp, cards.end());
            stack_2.insert(stack_2.end(), stack_1.begin(), stack_1.end());
            cards = stack_2;
        }
        else{
            long long int tmp;
            commandin >> tmp;
            vector <long long int> new_cards = cards;
            for(long long int i = 0 ; i < card_amount ; i++){
                new_cards[(tmp*i) % card_amount] = cards[i];
            }
            cards = new_cards;
        }
    }
    map <long long int,long long int> bt;
    for(long long int i = 0 ; i < card_amount ; i++){
        bt[cards[i]] = i;
    }
}