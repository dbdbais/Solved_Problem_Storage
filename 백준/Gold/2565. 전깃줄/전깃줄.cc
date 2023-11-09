//
// Created by newbi on 2023-11-09.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> vec;
int dp[104];
int N ,ans;

void solve(){
    int lis = 0 ;
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        int mx = 0;
        for(int j=0;j<i;j++){
            if(vec[j].second < vec[i].second && mx < dp[j]) mx = dp[j];  //i보다 왼쪽에 작은 값이 있고, 그 중 최대 값을 찾음
        }
        dp[i] = mx +1;  
        lis = max(lis,dp[i]);   //LIS 값 찾음
    }
    ans = N - lis;  //원래 값에서 LIS값 빼주면 그것이 없애야 할 전기줄이다.
}


int main(){
    int a,b;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a >> b;
        vec.push_back({a,b});
    }
    solve();
    cout << ans <<'\n';
    return 0;
}
