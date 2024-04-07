//
// Created by newbi on 2024-04-07.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int N,M;

int before[1004];
int dist[1004];
vector<pair<int,int>> adjList[1004];    //무게와 to가 저장

void print(){
    For(i,1,N+1){
        cout << dist[i] << " ";
    }

    cout << endl;

    For(i,1,N+1){
        cout << before[i] << " ";
    }
    cout << endl;
}

void dijkstra(int start) {
    fill(&dist[0],&dist[0]+1004,1e9);
    dist[start] =0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,start});

    while(pq.size()){
        auto cur = pq.top(); pq.pop();
        int cur_node = cur.second;
        int cur_dist = cur.first;

        if(dist[cur_node] != cur_dist) continue;    //최근 update된거 아니면 SKIP
         for(auto a : adjList[cur_node]){

            int adj_node = a.second;
            int adj_dist = a.first;

            if(dist[adj_node] > cur_dist + adj_dist){
                dist[adj_node] = cur_dist + adj_dist;   //update
                pq.push({dist[adj_node],adj_node});
                before[adj_node] = cur_node;    //거쳐온 노드 저장
            }
        }
    }
}

void printAns(){
    For(i,2,N+1){
        if(i < before[i]){
            cout << i << " " << before[i] <<endl;
        }
        else{
            cout << before[i] << " " << i <<endl;
        }

    }
}

int main(){
    fastIO();
    cin >> N >> M;
    int a,b,c;
    For(i,0,M){
        cin >> a >> b >> c;
        adjList[a].push_back({c,b});
        adjList[b].push_back({c,a});
    }
    dijkstra(1);
    cout << N-1 << endl;
    printAns();

    return 0;
}