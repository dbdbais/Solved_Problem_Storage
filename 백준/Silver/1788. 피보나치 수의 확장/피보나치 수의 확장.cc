//
// Created by newbi on 2024-05-11.
//
#include <iostream>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ll = long long;
using namespace std;

int N;
const ll mod = 1000000000;
ll dp[1000001];
ll ndp[1000001];

void solve(){
    //양수

    if(N >0 ){
        dp[0] = 0;
        dp[1] = 1;
        For(i,2,N+1){
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
    }
    else{
        int TN = abs(N);
        ndp[0] =0;
        ndp[1] =1;
        For(i,2,TN+1){
            ndp[i] = (ndp[i-2] - ndp[i-1]) % mod;
        }
    }
}

int check(ll num){
    if(num > 0) {
        return 1;
    }
    else if(num < 0){
        return -1;
    }
    else{
        return 0;
    }
}

int main(){
    fastIO();
    cin >> N;
    solve();

    if(N >= 0){
        cout << check(dp[N]) << endl;
        cout << abs(dp[N])<< endl;
    }
    else{
        N = abs(N);
        cout << check(ndp[N]) << endl;
        cout << abs(ndp[N])<< endl;
    }
    return 0;
}