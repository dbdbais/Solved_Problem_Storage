//
// Created by newbi on 2023-09-21.
//
#include<iostream>
using namespace std;
int N,dp[10000004];

void go(int idx){
    if(idx == 0) return;
    cout << idx <<" ";
    if(idx % 3 == 0 && dp[idx] == dp[idx/3]+1) go(idx/3);
    else if(idx % 2 ==0 && dp[idx] == dp[idx/2]+1) go(idx/2);
    else if(idx-1 >= 0 && dp[idx] == dp[idx-1]+1) go(idx-1);
    return;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1]+1;  //i를 만드는 방법은 i-1을 만드는 방법에서 +1을 더한 것
        if(i % 2 == 0){
            dp[i] = min (dp[i], dp[i/2]+1); //2로 나뉘는 것과 현재 값을 비교
        }
        if(i % 3 == 0){
            dp[i] = min (dp[i], dp[i/3]+1); //3으로 나뉘는 것과 현재 값을 비교
        }
    }
    //for(int i=1;i<=N;i++) cout << dp[i]<<" ";
    //cout <<endl;
    cout << dp[N]<<'\n';
    go(N);
    return 0;
}