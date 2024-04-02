//
// Created by newbi on 2024-04-02.
//
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N;
const int INF = 1e9;
int arr[1001][3];
int dp[1001][3];
int ans = INF;

void print(){
    For(i,1,N+1){
        For(j,0,3){
            cout << dp[i][j] <<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}

void solve(){
    For(i,0,3){
        For(j,0,3){
            if( i == j){
                dp[1][j] = arr[1][j];
            }
            else{
                dp[1][j] = INF;
            }
        }
        For(j,2,N+1){

            dp[j][0] = min(dp[j-1][1],dp[j-1][2]) +arr[j][0];
            dp[j][1] = min(dp[j-1][0],dp[j-1][2]) +arr[j][1];
            dp[j][2] = min(dp[j-1][1],dp[j-1][0]) +arr[j][2];
        }
        //print();

        For(k,0,3){
            if(i == k) continue;
            ans = min(ans,dp[N][k]);
        }

    }
}



int main(){
    fastIO();
    
    cin >> N;
    For(i,1,N+1){
        For(j,0,3){
            cin >> arr[i][j];
        }
    }
    solve();

    cout << ans << endl;

    return 0;
}