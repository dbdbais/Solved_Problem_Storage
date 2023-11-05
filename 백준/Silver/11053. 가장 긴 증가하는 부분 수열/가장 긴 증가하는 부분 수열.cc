//
// Created by newbi on 2023-10-31.
//
#include <iostream>
using namespace std;
int N, ans;
int arr[1004];
int dp[1004];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    for(int i=0;i<N;i++){
        int mx = 0; //앞에 작은 것이 몇개 있는지 찾을 수
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i] && mx < dp[j]) mx = dp[j];   //i보다 왼쪽에 작은 값이 있고, 그 중 최대 값을 찾음
        }
        dp[i] = mx+1;   //좌측에 있는 가장 큰 값에 하나 추가
        ans = max(ans,dp[i]);   //최대 LIS 답에 저장
    }
    /*  DP배열 확인
    for(int i=0;i<N;i++){
        cout <<dp[i] <<" ";
    }   */
    cout << ans<<'\n';
    return 0;
}
