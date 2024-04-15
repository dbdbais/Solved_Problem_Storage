//
// Created by newbi on 2024-04-15.
//
#include <iostream>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;

int N;
ll dp[91][2];
int main(){
    fastIO();
    cin >> N;
    dp[1][0] = 0;   //전에 0으로 시작
    dp[1][1] = 1;   //1번째 자리 1로 시작
    For(i,2,N+1){
        dp[i][0] = dp[i-1][1]+dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[N][0] + dp[N][1] <<endl;

    return 0;
}