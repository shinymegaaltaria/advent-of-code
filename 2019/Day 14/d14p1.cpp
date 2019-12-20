#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
map <string,pair<vector<pair<string,int> >,int> > recipe_tree;
map <string, int> leftover;
int ore_amount(string to_make, int amount){
    cout << "function call: " << to_make << " " << amount << endl;
    if(to_make == "ORE"){
        return amount;
    }
    else{
        int denominator = recipe_tree[to_make].second;
        int serve = ceil(double(amount)/double(denominator));
        cout << "denominator: " << denominator << ", serve: " << serve << endl;
        int s = recipe_tree[to_make].first.size();
        int cnt = 0;
        for(int i = 0 ; i < s ; i++){
            cout << "Reagent: " << recipe_tree[to_make].first[i].first << ", Required: " << recipe_tree[to_make].first[i].second * serve << ", Leftovers: " << leftover[recipe_tree[to_make].first[i].first] << endl;
            if(leftover[recipe_tree[to_make].first[i].first] >= recipe_tree[to_make].first[i].second * serve){
                leftover[recipe_tree[to_make].first[i].first] -= recipe_tree[to_make].first[i].second * serve;
            }
            else{
                int new_amount = recipe_tree[to_make].first[i].second * serve - leftover[recipe_tree[to_make].first[i].first];
                leftover[recipe_tree[to_make].first[i].first] = 0;
                cnt += ore_amount(recipe_tree[to_make].first[i].first , new_amount);
                cout << "Reagent in " << to_make << ": " << recipe_tree[to_make].first[i].first << ", Leftover: " << leftover[recipe_tree[to_make].first[i].first] << endl;
            }
        }
        leftover[to_make] += serve * denominator - amount;
        cout << "About to return Reagent: " << to_make << ", Leftover: " << leftover[to_make] << endl;
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
        recipe_tree[ingredient].first = recipe;
        recipe_tree[ingredient].second = amount;
    }
    cout << ore_amount("FUEL", 1) << endl;
    for (auto const& pair: leftover) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}