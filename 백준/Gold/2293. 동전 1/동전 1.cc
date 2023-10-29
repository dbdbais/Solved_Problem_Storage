//
// Created by newbi on 2023-09-22.
//
#include<iostream>
using namespace std;
int N,K,dp[10004];
int main(){
    cin >> N >> K;
    int temp;
    dp[0]=1;    //0을 만드는 경우의 수는 1이다.
    for(int i=1;i<=N;i++){
        cin >> temp;    //동전의 가치
        for(int j=temp;j<=K;j++){   //무한대 사용하므로 좌로부터 더해나간다
            dp[j] += dp[j-temp];    //temp원으로 K원을 만들 수 있는 경우의 수 구하기
        }
        /*
        for(int a=0;a<=K;a++)
            cout << dp[a]<<" ";
        cout<<endl;
         */
    }
    cout << dp[K]<<'\n';
    return 0;
}
