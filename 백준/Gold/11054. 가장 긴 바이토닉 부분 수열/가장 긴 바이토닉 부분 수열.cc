//
// Created by newbi on 2024-03-11.
//
#include <iostream>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int lft[1000];
int rgt[1000];
int input[1000];
int N,ans;

void solve(){
    For(i,0,N){
        int mx =0;
        For(j,0,i){     //0 ~ i-1까지
            if(input[j]<input[i] && mx < lft[j] ) mx = lft[j];
        }
        lft[i] = mx+1;
    }

    for(int i = N-1;i>=0;i--){
        int mx =0;
        for(int j = N-1; j>i;j--){
            if(input[j]<input[i] && mx < rgt[j]) mx = rgt[j];
        }
        rgt[i] = mx+1;
    }
    int sm =0;
    For(i,0,N){
        sm = lft[i]+rgt[i]-1;
        if(sm > ans) ans = sm;  //최대 값 으로 갱신
    }
}


int main(){
    fastIO();
    cin >> N;
    For(i,0,N){
        cin >> input[i];
    }
    solve();

    cout << ans <<endl;

    return 0;
}