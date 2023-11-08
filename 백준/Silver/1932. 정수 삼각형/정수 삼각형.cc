//
// Created by newbi on 2023-11-08.
//
#include <iostream>
#include <algorithm>
using namespace std;
int N, ans;
int arr[503][503];
int dp[503][503];

void solve(){
    dp[1][1] = arr[1][1];

    for(int i =2;i<=N;i++){
        for(int j=1;j<=i;j++){
            if(j == 1){     //첫 자리라면 선택의 여지 없이 첫번째꺼 더함
                dp[i][j] = dp[i-1][1] + arr[i][1];
            }
            else if(j == i){    //마지막 자리라면 마지막꺼 더함
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            }
            else{   //가운데라면 이전의 메모제이션 배열중 큰값이랑 더함
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + arr[i][j];
            }
        }
    }
    vector<int> temp;

    for(int i=1;i<=N;i++){
        temp.push_back(dp[N][i]);
    }

    ans = *max_element(temp.begin(),temp.end());
}
void print(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            cout << dp[i][j]<<" ";
        }
        cout <<endl;
    }
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
         cin >> arr[i][j];
        }
    }
    solve();
    //print();  DEBUG
    cout << ans <<'\n';

    return 0;
}