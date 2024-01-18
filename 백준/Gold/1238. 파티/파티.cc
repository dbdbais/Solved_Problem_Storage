//
// Created by newbi on 2024-01-18.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1004;

int N, M, X, A, B, T ,longest;
vector<pair<int,int>> adj[MAX]; //인접리스트
int dist[MAX];  //거리 저장되는 길이

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dijkstra(int start){
    fill(&dist[0],&dist[0]+MAX,1e8);    //dist 배열 무한대로 초기화
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    dist[start] = 0;

    while(pq.size()){
        auto cur = pq.top();
        int cur_node = cur.second;
        int cur_dist = cur.first;
        pq.pop();
        if(dist[cur_node] != cur_dist) continue;    //가장 최근에 갱신된 것만 본다

        for(auto ad : adj[cur_node]){
            int next_node = ad.second;
            int next_dist = ad.first;

            if(dist[next_node] > dist[cur_node] + next_dist){   //더 최소인 경로 만날 시 UPDATE
                dist[next_node] = dist[cur_node] + next_dist;
                pq.push({dist[next_node],next_node});
            }
        }

    }
}
void solve(){
    for(int i=1;i<=N;i++){
        if(i == X) continue;

        int route_len = 0;
        dijkstra(i);
        route_len += dist[X];   //X까지 최소 경로
        dijkstra(X);
        route_len += dist[i];   //  + i까지 돌아오는 경로

        longest = max(route_len,longest);   //최대로 오래 걸리는 친구 찾는다.
    }
}

int main(){
    fastIO();

    cin >> N >> M >> X;

    for(int i=0;i<M;i++){
        cin >> A >> B >> T;
        adj[A].push_back({T,B});    //인접리스트에 넣는다
    }
    solve();
    cout << longest <<'\n';

    return 0;
}