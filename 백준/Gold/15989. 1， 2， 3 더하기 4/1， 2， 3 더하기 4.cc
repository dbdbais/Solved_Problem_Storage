//
// Created by newbi on 2023-09-19.
//
#include <iostream>
using namespace std;
int T, N,dp[10001];
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    dp[0] = 1;  //초기 작업
    for(int i=1;i<=3;i++){  //1,2,3 으로 숫자를 만듦
        for(int j=1;j<=10000;j++){
            if(dp[j-i]>=0) dp[j] += dp[j-i];    //전에 구해놨던 경우의 수에다 현재 i로 j를 만들 수 있는 경우의 수 더한다
        }
    }
    int input;
    for(int i= 0; i< T;i++){
        cin >> input;
        cout <<dp[input]<<'\n';
    }

    return 0;
}