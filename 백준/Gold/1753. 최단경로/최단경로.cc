//
// Created by newbi on 2024-01-04.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int V,E,K,u,v,w;

vector<pair<int,int>> adj[20001];   //인접리스트 i와 인접한 경로들이 저장된다 {가중치,노드}
int dist[20001];    // 최종 거리가 저장 될 배열
const int INF = 987654321;  //무한대 값
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  //최소 힙

int main(){
    cin >> V >> E >> K;
    fill(dist, dist + 20001, INF);
    for(int i=0;i<E;i++){
        cin >> u >> v >> w;
        adj[u].push_back({w,v});    //weight 기준으로 넣는다.
    }
    pq.push({0,K}); //현재 노드에서 현재까지의 거리는 0
    dist[K] = 0;    //현재 거리를 0으로
    while(pq.size()){
        int here = pq.top().second;  //가장 가까운 거리의 노드 뽑아온다.
        int here_dist = pq.top().first; //가장 가까운 거리
        pq.pop();
        if(dist[here] != here_dist) continue;   //가장 최근에 갱신된 지점만 보겠다 (더 긴 길이는 보지 않겠다)

        for(pair<int,int> there : adj[here]){
            int _dist = there.first;    //현재 노드에서 인접한 노드의 거리
            int _there = there.second;  //현재 노드에서 인접한 노드
            if(dist[_there] > dist[here] + _dist){  //현재 distance보다 짧다면
                dist[_there] = dist[here] + _dist;  //갱신
                pq.push(make_pair(dist[_there],_there));    //우선순위 큐에 다시 집어넣어 다음 계산에 사용
            }
        }
    }
    for(int i = 1; i <= V; i++){
        if(dist[i] == INF) cout<<("INF")<<'\n';
        else cout<< dist[i]<<'\n';
    }

    return 0 ;
}