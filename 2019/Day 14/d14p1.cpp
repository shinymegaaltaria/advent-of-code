#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
map <string,vector<pair<string,int> > > recipe_tree;
map <vector<pair<string,int> >, pair<string,int> > recipe_result;
map <string, int> leftover;
int ore_amount(string to_make, int amount){
    if(to_make == "ORE"){
        return amount;
    }
    else{
        int denominator = recipe_result[recipe_tree[to_make]].second;
        int serve = ceil(double(amount)/double(denominator));
        int s = recipe_tree[to_make].size();
        int cnt = 0;
        for(int i = 0 ; i < s ; i++){
            cout << recipe_tree[to_make][i].first << " " << recipe_tree[to_make][i].second * serve << " " << leftover[recipe_tree[to_make][i].first] << endl;
            if(leftover[recipe_tree[to_make][i].first] >= recipe_tree[to_make][i].second * serve){
                leftover[recipe_tree[to_make][i].first] -= recipe_tree[to_make][i].second * serve;
            }
            else if(leftover[recipe_tree[to_make][i].first] > 0){
                int new_amount = recipe_tree[to_make][i].second * serve - leftover[recipe_tree[to_make][i].first];
                leftover[recipe_tree[to_make][i].first] = 0;
                cnt += ore_amount(recipe_tree[to_make][i].first , new_amount);
                int new_serve = ceil(double(new_amount)/double(recipe_tree[to_make][i].second));
                leftover[recipe_tree[to_make][i].first] += new_serve * recipe_tree[to_make][i].second - new_amount;
            }
            else{
                int new_amount = recipe_tree[to_make][i].second * serve;
                cnt += ore_amount(recipe_tree[to_make][i].first , recipe_tree[to_make][i].second * serve);
                int new_serve = ceil(double(new_amount)/double(recipe_tree[to_make][i].second));
                leftover[recipe_tree[to_make][i].first] += new_serve * recipe_tree[to_make][i].second - new_amount;
            }
        }
        leftover[to_make] = serve * denominator - amount;
        return cnt;
    }
}
int main(){
    ifstream recipein ("test_parsed.txt");
    int n;
    recipein >> n;
    for(int i = 0 ; i < n ; i++){
        int items;
        recipein >> items;
        vector<pair<string,int> > recipe;
        int amount;
        string ingredient;
        for(int j = 0 ; j < items ; j++){
            recipein >> amount >> ingredient;
            recipe.push_back(make_pair(ingredient,amount));
        }
        recipein >> amount >> ingredient;
        recipe_tree[ingredient] = recipe;
        recipe_result[recipe] = make_pair(ingredient,amount);
    }
    cout << ore_amount("FUEL", 1) << endl;
}