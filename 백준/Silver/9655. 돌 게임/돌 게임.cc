//
// Created by newbi on 2024-05-10.
//
#include <iostream>

#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int N;

int dp[1001];

void solve(){
    dp[N] = 1;

    for(int i=N;i>=1;i--){
        if(dp[i] == 1){
            if(i-1 > 0){
                dp[i-1] = 2;
            }
            if(i-3 >0){
                dp[i-3] = 2;
            }
        }
        else if(dp[i] == 2){
            if(i-1 > 0){
                dp[i-1] = 1;
            }
            if(i-3 >0){
                dp[i-3] = 1;
            }
        }
    }
}

void output(){
    For(i,1,N+1){
        cout << dp[i] <<" ";
    }
    cout << endl;
}
int main(){
    fastIO();
    cin >> N;
    solve();
    if(dp[1] == 1) {
        cout << "SK" << endl;
    }
    else{
        cout <<"CY" <<endl;
    }
    return 0;
}