//
// Created by newbi on 2024-04-19.
//
#include <iostream>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

typedef long long ll;
ll N,mx;
ll mod = 1000000009;
ll dp[10000004];
queue<int> q;
int main(){
    fastIO();
    cin >> N;
    ll tmp;
    For(i,0,N){
        cin >> tmp;
        mx = max(tmp,mx);
        q.push(tmp);
    }


    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;


    For(i,4,mx+1){
        dp[i] = (dp[i-1] %mod + dp[i-2] %mod + dp[i-3] %mod)%mod;
    }

    while(q.size()){
        cout << dp[q.front()] << endl;
        q.pop();
    }

    return 0;
}