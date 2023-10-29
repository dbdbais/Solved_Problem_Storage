//
// Created by newbi on 2023-09-23.
//
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int N,M,C;
vector<vector<int>> city(51,vector<int>(51,0));
const int mod = 1000007;
int dp[52][52][52][52]; //  x,y,cnt,prev 메모제이션 배열

int DFS(int x, int y, int cnt, int prev){
    if(x> N || y>M) return 0;   //맵을 벗어나면 0을 리턴해 카운트 x
    if( x == N && y == M){  //학원에 도착했다면
        if(cnt == 0 && city[x][y]==0)   {return 1;}     //n,m도착했고 C개의 오락실을 거쳤을 때는 한가지 경우의 수로 친다.
        if(cnt == 1 && city[x][y]> prev) {return 1;}    //마지막 오락실이 n,m에 있을 경우 한가지 경우의 수로 친다.
        return 0;
    }

    auto &ret = dp[x][y][cnt][prev];    //메모제이션
    if(ret != -1) {return ret;}   //초기 값이 아니라면 계산하지 않고 그대로 return
    ret = 0;

    if(city[x][y] == 0 ){   //빈칸으로 지나간다면
        ret = (DFS(x+1,y,cnt,prev)+ DFS(x,y+1,cnt,prev)) % mod;
    }
    else if(city[x][y] > prev){ //이전 게임기 보다는 큰 곳을 방문했다면
        ret = (DFS(x+1,y,cnt-1,city[x][y]) + DFS(x,y+1,cnt-1,city[x][y]))%mod;
    }
    //cout <<"x: "<<x<<", y: "<<y<<" cnt: "<<cnt<<" ret: "<<ret <<endl;
    return ret;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp,-1,sizeof(dp));
    cin >> N >> M >> C; // N*M C개의 오락실
    int x,y;
    for(int i=0;i<C;i++){
        cin >> x >>y;
        city[x][y] = i+1;
    }

    for(int i=0;i<=C;i++){
         cout<< DFS(1,1,i,0)<<" ";
    }


    return 0;
}