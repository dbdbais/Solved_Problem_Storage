//
// Created by newbi on 2024-06-20.
//
#include <iostream>
#include <algorithm>
#include <queue>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl'\n'

using namespace std;

int N,LR,RR,LB,RB,ans;
string st;

void solve(){
    bool isRed = false;
    bool isBlue = false;
    //LR 시작
    For(i,0,st.size()){
        char cur = st[i];
        if(cur =='R' && isBlue){
            LR++;
        }
        else if(cur =='B' && !isBlue ) isBlue = true;
    }
    //LB 시작
    For(i,0,st.size()){
        char cur = st[i];
        if(cur =='B' && isRed){
            LB++;
        }
        else if(cur =='R' && !isRed ) isRed = true;
    }
    isRed = false;
    isBlue = false;

    for(int i=st.size()-1;i>=0;i--){
        char cur = st[i];
        if(cur =='R' && isBlue){
            RR++;
        }
        else if(cur =='B' && !isBlue ) isBlue = true;
    }

    for(int i=st.size()-1;i>=0;i--){
        char cur = st[i];
        if(cur =='B' && isRed){
            RB++;
        }
        else if(cur =='R' && !isRed ) isRed = true;
    }
    //cout << LR <<" "<< LB <<" "<< RR <<" "<< RB <<" " << endl;
    ans = min({LR,RB,RR,LB});

}

int main(){
    fastIO();
    cin >> N >> st;
    solve();
    cout << ans << endl;
    return 0;
}