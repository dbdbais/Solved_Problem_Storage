//
// Created by newbi on 2024-06-23.
//
#include <iostream>
#include <cstring>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;
int T,N,M;
int DP[10004]; 
int P[21];

void solve(){
    DP[0] = 1;
    For(p,0,N){
        int curP = P[p];
        //현재 가격
        For(i,curP,M+1){
            DP[i] += DP[i-curP];
            //DP[i] (이전 경우의 수) + (현재 코인으로 더해서 만들 수 있는 경우의 수)
        }
    }
    cout << DP[M] << endl;
    memset(DP,0,sizeof(DP));
}

int main(){
    fastIO();
    cin >> T;
    For(t,0,T){
        cin >> N;
        For(i,0,N){
            cin >>P[i];
        }
        cin >> M;
        solve();
    }
    return 0;
}