#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("bsgs.ic");
using namespace std;
int main(){
    long long int tmp;
    while(fin >> tmp){
        cout << tmp << ",";
    }
}