//
// Created by newbi on 2024-06-22.
//
#include<iostream>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int DP[1004];
int P[1004];
int N;

void print(){
    For(i,0,N+1){
        cout << DP[i] <<" ";
    }
    cout << endl;
}

void solve(){
    For(i,1,N+1){
        //i개의 카드를 만드는 데 필요 i번째
        For(a,i,N+1){
            DP[a] = max(P[i]+ DP[a-i],DP[a]);
            //이전 값 다 더해서 MAX면 업데이트
        }
        //print();
    }
}

int main(){
    fastIO();
    cin >> N;
    For(i,1,N+1){
        cin >> P[i];
    }
    solve();
    cout << DP[N] << endl;
    return 0;
}