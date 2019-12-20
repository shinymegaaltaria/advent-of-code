#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
map <string,pair<vector<pair<string,long long int> >,long long int> > recipe_tree;
map <string, long long int> leftover;
long long int ore_amount(string to_make, long long int amount){
    //cout << "function call: " << to_make << " " << amount << endl;
    if(to_make == "ORE"){
        return amount;
    }
    else{
        long long int denominator = recipe_tree[to_make].second;
        long long int serve = ceil(double(amount)/double(denominator));
        //cout << "denominator: " << denominator << ", serve: " << serve << endl;
        long long int s = recipe_tree[to_make].first.size();
        long long int cnt = 0;
        for(long long int i = 0 ; i < s ; i++){
            //cout << "Reagent: " << recipe_tree[to_make].first[i].first << ", Required: " << recipe_tree[to_make].first[i].second * serve << ", Leftovers: " << leftover[recipe_tree[to_make].first[i].first] << endl;
            if(leftover[recipe_tree[to_make].first[i].first] >= recipe_tree[to_make].first[i].second * serve){
                leftover[recipe_tree[to_make].first[i].first] -= recipe_tree[to_make].first[i].second * serve;
            }
            else{
                long long int new_amount = recipe_tree[to_make].first[i].second * serve - leftover[recipe_tree[to_make].first[i].first];
                leftover[recipe_tree[to_make].first[i].first] = 0;
                cnt += ore_amount(recipe_tree[to_make].first[i].first , new_amount);
                //cout << "Reagent in " << to_make << ": " << recipe_tree[to_make].first[i].first << ", Leftover: " << leftover[recipe_tree[to_make].first[i].first] << endl;
            }
        }
        leftover[to_make] += serve * denominator - amount;
        //cout << "About to return Reagent: " << to_make << ", Leftover: " << leftover[to_make] << endl;
        return cnt;
    }
}
int main(){
    ifstream recipein ("test_parsed.txt");
    long long int n;
    recipein >> n;
    for(long long int i = 0 ; i < n ; i++){
        long long int items;
        recipein >> items;
        vector<pair<string,long long int> > recipe;
        long long int amount;
        string ingredient;
        for(long long int j = 0 ; j < items ; j++){
            recipein >> amount >> ingredient;
            recipe.push_back(make_pair(ingredient,amount));
        }
        recipein >> amount >> ingredient;
        recipe_tree[ingredient].first = recipe;
        recipe_tree[ingredient].second = amount;
    }
    long long int ub = 1000000000000;
    long long int lb = 0;
    while(ub > lb){
        long long int mid = (ub + lb) / 2;
        if(ore_amount("FUEL",mid) < 1000000000000){
            lb = mid + 1;
        }
        else{
            ub = mid - 1;
        }
    }
    cout << ub << endl;
}
