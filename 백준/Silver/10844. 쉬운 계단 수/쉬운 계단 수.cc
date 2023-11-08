//
// Created by newbi on 2023-11-08.
//
#include <iostream>

using namespace std;

typedef long long ll;
const ll M = 1000000000;
ll dp[104][10],N;
ll ans;

void solve(){
    dp[1][0] =0;
    for(int i=1;i<10;i++){
        dp[1][i] = 1;
    }
    for(int i=2;i<=N;i++){
        for(int j= 0;j<10;j++){
            if(j == 0){
                dp[i][j] = dp[i-1][1] % M;  //0의 경우에는 1이어야만 가능
            }
            else if(j== 9){
                dp[i][j] = dp[i-1][8] % M;  //9의 경우에는 8이어야만 가능
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % M; //위에서 계단 수, 찾아서 그만큼 생성가능
            }
        }
    }
    for(int i=0;i<10;i++){
        ans = (ans + dp[N][i]) % M;    //최종 생성할 수 있는 경우의 수 더한다.
    }

}

int main(){
    cin >> N;

    solve();
    cout << ans <<'\n';
    return 0;
}