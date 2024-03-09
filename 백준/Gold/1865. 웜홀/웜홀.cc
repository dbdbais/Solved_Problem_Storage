//
// Created by newbi on 2024-03-09.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF = 1e9;
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int TC,N,M,W,S,E,T;

vector<pair<int,int>> adj[501];
int dist[501][501];
void print(){
    For(i,1,N+1){
        For(j,1,N+1){
            if(dist[i][j] == INF){
                cout <<"I ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;
}


void floyd(){

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            if(k == i) continue;
            for(int j=1;j<=N;j++){
                if(k == j) continue;
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);   //모든 정점 최소거리로 갱신
                //cout << i<<", "<<j<<", "<<k <<endl;
                //print();
            }
        }
    }
}

bool findNeg(){
    For(i,1,N+1){
        if(dist[i][i] < 0) return true;
    }
    return false;
}

int main(){

    fastIO();
    cin >> TC;
    For(t,1,TC+1){
        cin >> N >> M >> W;
        fill(&dist[0][0],&dist[0][0]+501*501,INF);
        For(i,0,M){
            cin >> S >> E >> T;
            dist[S][E] = min(T,dist[S][E]);
            dist[E][S] = min(T,dist[E][S]);
        }
        For(i,0,W){
            cin >> S >> E >> T;
            dist[S][E] = min(-T,dist[S][E]);
        }
        floyd();

        if(findNeg()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}