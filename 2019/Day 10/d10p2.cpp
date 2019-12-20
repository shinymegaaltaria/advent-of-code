#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b){
    if(a == 0){
        return -1;
    }
    if(b == 0){
        return -2;
    }
    if(a > b){
        if(a % b == 0){
            return b;
        }
        else{
            return gcd (a % b , b);
        }
    }
    else{
        if(b % a == 0){
            return a;
        }
        else{
            return gcd (b % a , a);
        }
    }
}
int main(){
    char tile;
    bool space[33][33];
    vector<pair<int,int> > aestroid;
    for(int i = 0 ; i < 33 ; i++){
        for(int j = 0 ; j < 33 ; j++){
            cin >> tile;
            if(tile == '#'){
                space[i][j] = true;
                aestroid.push_back(make_pair(i,j));
            }
            else{
                space[i][j] = false;
            }
        }
    }
    int best_X = 29, best_Y = 23;
    int rocks = aestroid.size();
    vector<pair<int,int> > to_be_destroyed;
    for(int j = 0 ; j < rocks ; j++){
        pair<int,int> first_rock = make_pair(best_X , best_Y);
        pair<int,int> second_rock = aestroid[j];
        if(first_rock == second_rock) continue;
        int x_diff = second_rock.first - first_rock.first;
        int y_diff = second_rock.second - first_rock.second;
        int step = gcd(abs(x_diff),abs(y_diff));
        if(step == -1){
            bool pass = true;
            if(y_diff < 0){
                for(int k = first_rock.second - 1 ; k > second_rock.second ; k--){
                    if(space[first_rock.first][k]){
                        pass = false;
                    }
                }
            }
            else{
                for(int k = first_rock.second + 1 ; k < second_rock.second ; k++){
                    if(space[first_rock.first][k]){
                        pass = false;
                    }
                }
            }
            if(pass){
                to_be_destroyed.push_back(second_rock);
            }
        }
        else if(step == -2){
            bool pass = true;
            if(x_diff < 0){
                for(int k = first_rock.first - 1 ; k > second_rock.first ; k--){
                    if(space[k][first_rock.second]){
                        pass = false;
                    }
                }
            }
            else{
                for(int k = first_rock.first + 1 ; k < second_rock.first ; k++){
                    if(space[k][first_rock.second]){
                        pass = false;
                    }
                }
            }
            if(pass){
                to_be_destroyed.push_back(second_rock);
            }
        }
        else{
            bool pass = true;
            for(int k = 1; k < step ; k++){
                if(space[first_rock.first + x_diff / step * k][first_rock.second + y_diff / step * k]){
                    pass = false;
                }
            }
            if(pass){
                to_be_destroyed.push_back(second_rock);
            }
        }
    }
    int d_s = to_be_destroyed.size();
    cout << d_s << endl;
    vector <pair <double, int> > seq;
    for(int i = 0; i < d_s; i++){
        cout << to_be_destroyed[i].first << " " << to_be_destroyed[i].second << endl;
    }
}