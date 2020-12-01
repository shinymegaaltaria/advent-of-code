#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("d2_in.txt");
struct box{
    int l;
    int w;
    int h;
};
int main(){
    int ans = 0;
    box presents[1000];
    for(int i = 0 ; i < 1000 ; i++){
        fin >> presents[i].l >> presents[i].w >> presents[i].h;
        int min_side = min(presents[i].l, min(presents[i].w , presents[i].h));
        int max_side = max(presents[i].l, max(presents[i].w , presents[i].h));
        int mid_side = presents[i].l + presents[i].w + presents[i].h - min_side - max_side;
        ans += min_side * 2 + mid_side * 2 + min_side * mid_side * max_side;
    }
    cout << ans << endl;
}