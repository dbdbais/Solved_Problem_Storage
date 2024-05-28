//
// Created by newbi on 2024-05-27.
//
#include <iostream>

#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ll = long long;
using namespace std;

ll mod =  1000000;
ll dp[5004];
ll num [5004];
string ipt;
bool error;
void input(){
    cin >> ipt;
    for(int i=1;i<=ipt.size();i++){
        num[i] = ipt[i-1]-'0';
        if(num[1] == 0){
            error = true;
        }
    }
}

void solve(){
    dp[0] = 1;  //두자리 숫자일 경우 고려
    dp[1] = 1;  //첫 문자의 경우의 수는 1이다.

    for(int i=2;i<=ipt.size();i++){
        if(num[i] != 0){
            dp[i] = dp[i-1] % mod;
        }
        int tmp = num[i-1] * 10 + num[i];
        if(tmp < 27 && tmp > 9){
            dp[i] = (dp[i] + dp[i-2]) % mod;
        }
    }
}

int main(){
    fastIO();
    input();
    if(!error){
        solve();
    }
    cout << dp[ipt.size()] << endl;

//    for(int i=0;i<= ipt.size();i++){
//        cout << dp[i] <<" ";
//    }
//    cout << endl;

    return 0;
}