#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("d25.ic");
using namespace std;
int main(){
    long long int tmp;
    while(fin >> tmp){
        cout << tmp << ",";
    }
}