//
// Created by newbi on 2023-10-31.
//
#include <iostream>
using namespace std;
typedef long long ll;
ll cnt;
ll dp[1004][10];    //i개의 수, 끝나는 자릿 수(0 ~ 9)
int N;
void solve(){
    for(int i=0;i<10;i++){  //1개의 수 초기화
        dp[1][i] = 1;
    }
    for(int i=2;i<=N;i++){  //0으로 끝나는 수 초기화 0, 00, 000, 000...
        dp[i][0] = 1;
    }
    for(int i=2;i<=N;i++){  //점화식 규칙
        for(int j=1;j<10;j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%10007;

        }
    }
    for(int i=0;i<10;i++)   //최종 출력 값
        cnt = (cnt+ dp[N][i])%10007;

}

int main(){
    cin >> N;
    solve();
    cout << cnt <<'\n';
    return 0;
}