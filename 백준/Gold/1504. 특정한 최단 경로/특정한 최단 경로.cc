//
// Created by newbi on 2024-01-14
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[200004];   //인접리스트가 저장
int dist[804]; //최종 경로가 저장
const int INF = 1e8;
int N,E,a,b,c,v1,v2,ans;
int sv1,sv2,v1v2,v1n,v2n;   //각각의 경로

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


void shortest_path(int start){
    fill(dist,dist+804,INF);  //무한대로 전부 초기화한다.

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  //최소 힙
    pq.push({0,start});     //시작 정점 넣는다.
    dist[start] = 0;
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

    cin >> N >> E;

    for(int i=0;i<E;i++){
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});    //양방향 간선 업데이트
    }
    cin >> v1 >> v2;

    shortest_path(1);
    sv1 = dist[v1];    //s -> v1
    sv2 = dist[v2];    //s -> v2

    shortest_path(v1);
    v1v2 = dist[v2];   //v1 -> v2
    v1n = dist[N];    //v1- > N

    shortest_path(v2);
    v2n = dist[N];    //v2 -> N

    ans = min(sv1+v1v2+v2n,sv2+v1v2+v1n);   //s -> v1 -> v2 -> N 과 s -> v2 -> v1 -> N 중 작은 값 ans대입

    if(v1v2 == INF || ans >= INF) cout << -1 <<'\n';
    else{
        cout << ans <<'\n';
    }
    return 0;
}
