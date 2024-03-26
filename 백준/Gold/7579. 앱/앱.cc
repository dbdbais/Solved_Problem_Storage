//
// Created by newbi on 2024-03-26.
//
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
const int mx = 10001;
int N,M,sm;
int dp[10004];
int cost[101];
int off[101];

void print(){
    for(int i=0;i<=sm;i++){
        cout << dp[i]<<" ";
    }
    cout <<endl;
}

int main(){
    fastIO();
    cin >> N >> M;

    For(i,1,N+1){
        cin >> cost[i];

    }

    For(i,1,N+1){
        cin >> off[i];
        sm += off[i];  //합 더함
    }

    for(int i = 1;i<=N;i++) {
        for (int j = sm; j>= off[i]; j--) {
            dp[j] = max(dp[j],dp[j-off[i]]+cost[i]);
        }
        //print();
    }
    int ans =0;
    For(i,0,sm+1){
        if(dp[i]>= M){
            ans = i;
            break;
        }
    }
    cout << ans <<endl;
    return 0;
}