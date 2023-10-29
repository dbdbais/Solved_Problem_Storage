//
// Created by newbi on 2023-09-21.
//
#include <iostream>
using namespace std;
int dp[1000004],N;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1]+1;  //i를 만드는 방법은 i-1을 만드는 방법에서 +1을 더한 것
        if(i % 2 == 0){
            dp[i] = min (dp[i], dp[i/2]+1);
        }
        if(i % 3 == 0){
            dp[i] = min (dp[i], dp[i/3]+1);
        }
    }

    cout << dp[N]<<'\n';

    return 0;
}