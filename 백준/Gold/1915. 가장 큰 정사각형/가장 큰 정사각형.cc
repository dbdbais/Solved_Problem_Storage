//
// Created by newbi on 2024-06-26.
//
#include <iostream>
#include <algorithm>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
using namespace std;

int N,M,ans;

int arr[1004][1004];
int DP[1004][1004];

void input(){
    string st;
    cin >> N >> M;
    For(i,1,N+1){
        cin >> st;
        For(j,1,M+1){
            arr[i][j] = st[j-1]-'0';
            //정수로 대입
        }
    }
}

void output(){
    For(i,1,N+1){
        For(j,1,M+1){
            cout << DP[i][j] <<" ";
        }
        cout << endl;
    }
}

void solve(){
    For(i,1,N+1){
        For(j,1,M+1){
            if(arr[i][j]){
                DP[i][j] = min({DP[i-1][j-1],DP[i-1][j],DP[i][j-1]}) +1;
                //좌상단쪽 중 최소 값 가져와서 더함 (모든 요소 충족 시) +1 사각형
                int val = DP[i][j] * DP[i][j];
                if(val > ans) ans = val;
            }
        }
    }
}

int main(){
    fastIO();
    input();
    solve();
    //output();
    cout << ans << endl;
    return 0;
}