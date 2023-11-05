//
// Created by newbi on 2023-11-05.
//
#include <iostream>

using namespace std;
int stair[304];
int dp[304][3]; // n번째 계단, m번 연속으로 밟은 경우
int n ,ans;

void solve(){
    for(int i=0;i<3;i++){
        dp[0][i] = 0;   //초기 계단 값 설정
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]);  //이번 계단을 0번 밟으려면 전 계단을 밟았어야 한다.
        dp[i][1] = dp[i-1][0]+ stair[i];    //전에 밟지 않았던 거에서 현재 계단 더함
        dp[i][2] = dp[i-1][1] + stair[i];   // 1번 밟았던 dp배열에서 현재 계단 더함
    }
    ans = max(dp[n][1],dp[n][2]);   //0번째(밟지 않은) 케이스 제외 큰 값 답으로 선정
}

int main(){
    cin >> n;
    stair[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> stair[i];
    }
    solve();
    cout << ans <<'\n';
    return 0;
}