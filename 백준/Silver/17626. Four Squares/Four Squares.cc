//
// Created by newbi on 2023-08-11.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> dp(n+1,2147483647);
    dp[0]=0;
    for(int i=1;i<= sqrt(n);i++){
        dp[i*i] = 1;
    }
    for(int i=1; i<=n;i++){
        for(int j =1;j<= sqrt(i);j++){
            int temp = dp[j*j] + dp[i-j*j];    // ex) dp[8] = dp[1] + dp[7], dp[4]+ dp[4]
            dp[i] = min(temp,dp[i]);
        }
    }
    cout << dp[n];
    return 0;
}