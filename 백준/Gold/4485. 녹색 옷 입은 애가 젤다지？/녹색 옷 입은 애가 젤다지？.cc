//
// Created by newbi on 2024-02-26.
//
#include <iostream>
#include <queue>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int arr[126][126];
int dist [126][126];
int N;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool out(int x,int y){
    return x <0 || y <0 || x>=N || y >=N;
}
void print(){
    For(i,0,N){
        For(j,0,N){
            cout << dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void dijkstra(int x,int y){
    fill(dist[0],dist[N],1e9);

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

    pq.push({arr[x][y],{x,y}});
    dist[0][0] = arr[0][0]; //현재 경로 넣어줌

    while(pq.size()){
        auto cur = pq.top(); pq.pop();
        x = cur.second.first;
        y = cur.second.second;
        int weight = cur.first;
        if(dist[x][y] != weight) continue;  //가장 최근 갱신된 것만 본다.
        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)) continue;

            int next_weight = arr[qx][qy];
            if(dist[qx][qy] > weight+ next_weight){ //지금 거리보다 작다면
                dist[qx][qy] = weight+ next_weight; //update
                pq.push({dist[qx][qy],{qx,qy}});    //다음 탐색을 위해 업데이트
            }
        }
    }

}

int main(){
    fastIO();
    int num =1;
    while(true){
        cin >> N;
        if(!N) break;   //N이 0이면 break
        For(i,0,N){
            For(j,0,N){
                cin >> arr[i][j];
            }
        }
        dijkstra(0,0);
        cout << "Problem "<<num<<": "<<dist[N-1][N-1]<<endl;
        num++;
    }


    return 0;
}