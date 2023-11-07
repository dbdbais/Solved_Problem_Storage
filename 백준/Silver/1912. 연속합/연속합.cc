//
// Created by newbi on 2023-11-07.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, ans;
vector<int> vec(100004,0);
vector<int> dp(100004,0);
void solve(){
    int mx = *max_element(vec.begin()+1,vec.begin()+N+1);   //입력받은 배열에 최대값
    if(mx <0){  // 음수라면
        ans = mx;
    }
    else{   // 양수라면 최대 누적합을 찾는다.
        for(int i=1;i<=N;i++){
            dp[i] = max(dp[i-1]+vec[i],0);
        }
        ans = *max_element(dp.begin()+1,dp.begin()+N+1);    //dp 배열중 최대 값을 찾는다.
    }

}

int main(){

    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> vec[i];
    }
    solve();

    cout << ans <<'\n';
    return 0;
}
