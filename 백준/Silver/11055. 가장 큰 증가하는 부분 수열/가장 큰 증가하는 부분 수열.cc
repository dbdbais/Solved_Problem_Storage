//
// Created by newbi on 2024-04-15.
//
#include <iostream>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,ans;

int dp[1004];
int dpSum[1004];
int arr[1004];
int main(){
    fastIO();
    cin >> N;
    For(i,0,N){
        cin >> arr[i];
        dpSum[i] = arr[i];
    }

    for(int i=0;i<N;i++){
        int mx =0;
        int sm = 0;
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] &&  sm < dpSum[j]){
                mx = dp[j]; //최대 값 갱신
                sm = dpSum[j];
            }
        }
        dp[i] = mx +1;
        dpSum[i] = sm + dpSum[i];
        ans = max(ans,dpSum[i]);

    }

/*
   for (int i = 0; i < N; i++) {
       cout << dp[i] << " ";
   }
   cout << endl;
    for (int i = 0; i < N; i++) {
        cout << dpSum[i] << " ";
    }
    cout << endl;
*/

cout << ans << endl;
    return 0;
}