//
// Created by newbi on 2023-09-23.
//
#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> dp(104,0);
vector<int> cost(24,0);
vector<int> happy(24,0);
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> cost[i];
    }
    for(int i=1;i<=N;i++){
        cin >> happy[i];
    }
    for(int i=1;i<=N;i++){      //각각의 사람에게 한번만 말할 수 있으므로 우에서 시작
       for(int k=100;k>cost[i];k--){    //0이 되는 순간 기쁨을 잃음을 참고!
           dp[k] = max(dp[k],dp[k-cost[i]]+happy[i]);
       }
       /*
       for(int a=0;a<=100;a++){
           cout << dp[a]<< " ";
       }
       cout<<endl; DEBUG */
    }
    cout << dp[100];
    return 0;
}