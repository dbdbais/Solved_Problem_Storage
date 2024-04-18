//
// Created by newbi on 2024-04-18.
//
#include <bits/stdc++.h>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define INF 987654321;
using namespace std;
int N;
int weight[17][17];
int dp[17][1<<16];
int ansBit;

int DFS(int cur,int bit){
    if(bit == ansBit){
        if(weight[cur][1] == 0) {
            return INF; //끝까지 못 돌아온다면
        }
        else{
            return weight[cur][1];  //현재 위치에서 원래 위치로 돌아갈 수 있는 값
        }
    }
    if(dp[cur][bit] != -1){ //바로 갈 수 있다면
        return dp[cur][bit];
    }

    dp[cur][bit] = INF;

    for(int i =1; i<= N ;i++){  //현재 지점으로부터 다른 지점까지
        if(weight[cur][i] == 0) continue;   //거리가 없다면
        if((bit) & (1<<(i-1))) continue;  //방문한 곳 방문 처리

        dp[cur][bit] = min(dp[cur][bit],weight[cur][i] + DFS(i,bit|1<<(i-1)));  //이번 상태 반영해서 넘긴다.
        //최소값을 찾는다.

    }
    return dp[cur][bit];    //가장 최적화 된 것을 리턴
}

void input(){
    For(i,1,N+1){
        For(j,1,N+1){
            cin >> weight[i][j];
        }
    }
    ansBit = (1 << N) - 1;  //모든 경우를 방문한 비트
}

int main(){
    fastIO();
    cin >> N;
    input();
    memset(dp,-1,sizeof(dp));

    cout << DFS(1,1) << endl;

    return 0;
}