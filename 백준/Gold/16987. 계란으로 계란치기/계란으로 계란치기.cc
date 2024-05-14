//
// Created by newbi on 2024-05-14.
//
#include <iostream>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, ans;

int durability[10];
int weight[10];

void print(){
    For(i,0,N){
        cout << durability[i] <<" ";
    }
    cout << endl;
}

void DFS(int idx, int cnt){
    if(idx == N){
        if(cnt > ans) ans = cnt;
        return;
    }
    if(durability[idx] <=0 || cnt == N-1){
        DFS(idx+1,cnt);
        return;
    }
    int tCnt = cnt;
    for(int i = 0;i<N;i++){
        if( i == idx) continue;

        if(durability[i] <= 0) continue;

        durability[idx] -= weight[i];
        durability[i] -= weight[idx];

        if(durability[idx] <=0) cnt++;
        if(durability[i] <= 0) cnt++;

        DFS(idx+1,cnt);

        durability[idx] += weight[i];
        durability[i] += weight[idx];
        cnt = tCnt;
    }

}


int main(){
    fastIO();
    cin >> N;
    For(i,0,N){
        cin >> durability[i] >> weight[i];
    }
    DFS(0,0);
    cout << ans << endl;
    return 0;
}