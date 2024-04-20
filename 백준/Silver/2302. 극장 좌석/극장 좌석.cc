//
// Created by newbi on 2024-04-20.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,M;

int dp[41];  //피보나치 수열
vector<int> vec;

void makeDP(int mx){
    dp[0] = 1;  //VIP좌석이 붙어 있는 경우 
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    For(i,4,mx+1){
        dp[i] = dp[i-1] + dp[i-2];
    }

}

int main(){
    fastIO();
    cin >> N >> M;
    int _start = 1;
    int _end;
    For(i,0,M){
        cin >> _end;
        vec.push_back(_end - _start);
        _start = _end+1;
    }
    vec.push_back(N+1 - _start);    //마지막 요소 넣는다.

    auto mx_elem = *max_element(vec.begin(),vec.end());

    makeDP(mx_elem);
    int ans = 1;
    for(auto elem : vec){
        ans *= dp[elem];
    }
    cout << ans << endl;

    return 0;
}