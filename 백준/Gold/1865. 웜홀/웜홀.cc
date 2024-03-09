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

vector<pair<int,pair<int,int>>>Edge;    //가중치 x, y

int dist[501];


bool bellmanFord(){

    for(int i=0;i<=N;i++){
        for(auto e : Edge){
            int cur_weight = e.first;
            int cur_s = e.second.first;
            int cur_e = e.second.second;

            //if(dist[cur_s] == INF) continue;    //미탐색인 노드는 스킵
            if(dist[cur_e] > dist[cur_s] + cur_weight) {
                if(i == N){
                    return false;
                }
                else {
                    dist[cur_e] = dist[cur_s] + cur_weight;
                }
            }
        }
    }

    return true;
}



int main(){

    fastIO();
    cin >> TC;
    For(t,1,TC+1){
        cin >> N >> M >> W;
        fill(&dist[0],&dist[0]+501,INF);
        Edge.clear();

        For(i,0,M){
            cin >> S >> E >> T;
            Edge.push_back({T,{S,E}});
            Edge.push_back({T,{E,S}});
        }
        For(i,0,W){
            cin >> S >> E >> T;
            Edge.push_back({-T,{S,E}});
        }



        if(!bellmanFord()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


    }

    return 0;
}