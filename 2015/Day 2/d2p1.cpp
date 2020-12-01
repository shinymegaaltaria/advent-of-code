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
        int face_1 = presents[i].l * presents[i].w;
        int face_2 = presents[i].l * presents[i].h;
        int face_3 = presents[i].w * presents[i].h;
        int slack_face = min(face_1 , min(face_2 , face_3));
        ans += face_1 * 2 + face_2 * 2 + face_3 * 2 + slack_face;
    }
    cout << ans << endl;
}