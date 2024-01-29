//
// Created by newbi on 2024-01-21.
//
#include <iostream>
#include <cstring>
using namespace std;

int T,N,ans;
int sticker[100004][2];
int dp[100004][2];

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    for(int i=0;i<2;i++){
        for(int j=1;j<=N;j++){
            cin >> sticker[j][i];
        }
    }
}
void solve(){
    dp[1][0] = sticker[1][0];
    dp[1][1] = sticker[1][1];
    dp[2][0] = sticker[1][1] + sticker[2][0];   //첫 2번째 까지 대각선의 합이 항상 최대
    dp[2][1] = sticker[1][0] + sticker[2][1];
    for(int i=3;i<=N;i++){
        dp[i][0] = max(dp[i-1][1],dp[i-2][1]) + sticker[i][0];  // 3번째 부터 누적합 중 가장 큰 값을 메모제이션한 후 더해나간다.
        dp[i][1] = max(dp[i-1][0],dp[i-2][0]) + sticker[i][1];
    }

}
void print(){
    for(int i=0;i<=1;i++){
        for(int j=1;j<=N;j++){
            cout <<dp[j][i]<<" ";
        }
        cout <<endl;
    }
}
void reset(){   //dp 배열과 스티커 배열 초기화
    memset(sticker,0,sizeof(sticker));
    memset(dp,0,sizeof(dp));
}

int main(){

    fastIO();
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N;
        input();
        solve();
        //print();
        ans = max(dp[N][0],dp[N][1]);   //메모제이션 누적 값 중 최대 값 구한다.
        cout << ans <<'\n';
        reset();
    }


    return 0;
}