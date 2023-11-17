//
// Created by newbi on 2023-11-17.
//
#include <iostream>
using namespace std;
const int cap = 300;
int arr [cap+1][cap+1];
int T,p,q,ans;

void create(){
    int cnt = 1;
    for(int i=1;i<=cap;i++){
        for(int j=0;j<=cap;j++){
            arr[i-j][j+1] = cnt;
            cnt++;
            if(i-j == 1) break;
        }
    }
}
void solve(int x, int y){
    int xx,xy,yx,yy;
    for(int i=1;i<=cap;i++){
        for(int j=1;j<= cap;j++){
            if(arr[i][j] == x){
                xx = i;
                xy = j;
                break;
            }
        }
    }

    for(int i=1;i<=cap;i++){
        for(int j=1;j<= cap;j++){
            if(arr[i][j] == y){
                yx = i;
                yy = j;
                break;
            }
        }
    }
    ans = arr[xx+yx][xy+yy];
}
void reset(){
    ans = 0;
}
int main(){
    create();
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> p >> q;
        solve(p,q);
        cout <<"#"<<i<<" "<<ans<<'\n';
        reset();
    }

    return 0;
}