//
// Created by newbi on 2024-01-14
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N,M,A,B,strt,_end,W;
vector<pair<int,int>> adj[100004];   //인접리스트가 저장
int dist[1004]; //최종 경로가 저장됨
const int INF = 1e8;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//최소 힙

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


void shortest(){
    while(pq.size()){
        int nearest = pq.top().second;  // 가장 가까운 노드
        int nearest_dist = pq.top().first;  //의 거리
        pq.pop();
        if(dist[nearest] != nearest_dist) continue; //최적이 아니라면 SKIP

        for(auto dest : adj[nearest]){
            int dest_node = dest.second;
            int dest_dist = dest.first; //nearest에서 dest까지의 거리
            if(dist[dest_node] > dist[nearest] + dest_dist){
                dist[dest_node] = dist[nearest] + dest_dist;
                pq.push({dist[dest_node],dest_node});
            }
        }
    }
}

int main(){

    fastIO();

    cin >> N >> M;
    fill(dist,dist+1004,INF);  //무한대로 전부 초기화한다.
    for(int i=0;i<M;i++){
        cin >> A >> B >> W;
        adj[A].push_back({W,B});    //단방향
    }
    cin >> strt >> _end;
    pq.push({0,strt});     //시작 정점 넣는다.
    dist[strt] = 0;

    shortest();

    cout <<dist[_end]<<'\n';

    return 0;
}
