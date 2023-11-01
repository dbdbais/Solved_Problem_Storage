//
// Created by newbi on 2023-11-01.
//
#include <iostream>
#include <cstring>

using namespace std;
int ans[50];
int T,cnt = 0;
string base;


void convert(int idx){
    int tmp = base[idx]-'0';
    for(int i = idx;i<base.size();i++){
        ans[i] = tmp;
    }
}
void solve(){
    for(int i=0;i<base.size();i++){
        if(ans[i] != base[i]-'0'){  //원본과 다르다면
            cnt++;
            convert(i);
        }
    }
}


void reset(){
    memset(ans,0,sizeof(ans));
    cnt = 0;
}
int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> base;
        solve();
        cout <<"#"<<i<<" "<<cnt<<'\n';
        reset();
    }
    return 0;
}