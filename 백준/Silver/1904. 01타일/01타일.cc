//
// Created by newbi on 2023-11-06.
//
#include <iostream>
using namespace std;
int N;
const int M = 15746;
int dp[1000004];

void solve(){
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=N;i++){
        dp[i] = (dp[i-1]%M + dp[i-2]%M) %M ;
    }
}
int main(){
    cin >> N;
    solve();
    cout <<dp[N] <<'\n';
    return 0;
}