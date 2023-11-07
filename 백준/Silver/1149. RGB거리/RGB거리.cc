//
// Created by newbi on 2023-11-07.
//
#include <iostream>
#include <algorithm>
using namespace std;
int RGB[1004][3];   //R : 0, G : 1, B : 2 값
int dp[1004][3];
int N,ans;

void solve(){
    for(int i=0;i<3;i++)
        dp[1][i] = RGB[1][i];

    for(int i=2;i<=N;i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + RGB[i][0];  //i번째 집을 R로 칠하는 경우, 이전의 G B 중 작은 값 선택
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + RGB[i][1];  //G로 칠하는 경우
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + RGB[i][2];  //B로 칠하는 경우
    }
    ans = min({dp[N][0],dp[N][1],dp[N][2]});    //셋 중에 가장 최소 값을 ans에 집어넣는다.
}
void debug(){
    cout <<endl;
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++)
            cout << dp[i][j]<<" ";
        cout <<endl;
    }
}

int main(){
    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            cin >> RGB[i][j];
        }
    }
    solve();

    //debug();
    
    cout << ans <<'\n';

    return 0;
}