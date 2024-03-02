//
// Created by newbi on 2024-03-02.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int N,M;

struct Edge{
    int from;
    int to;
    int weight;

    Edge(int from,int to,int weight):from(from),to(to),weight(weight){}

    bool operator <(const Edge e){
        return weight < e.weight;
    }
};

vector<Edge> edgeList;
int parents[1001];

void makeSet(){
    For(i,1,N+1){   //부모로 변경
        parents[i] = i;
    }
}
int find(int idx){
    if(parents[idx] == idx) return idx;
    return parents[idx] = find(parents[idx]);   //좌표 압축
}
bool unn(int a,int b){
    int aRoot = find(a);
    int bRoot = find(b);
    if(aRoot == bRoot) return false;
    parents[bRoot] = aRoot;
    return true;
}


int main(){
    fastIO();
    cin >> N >> M;

    int from,to,weight;
    For(i,0,M){
        cin >> from >> to >> weight;
        edgeList.push_back(Edge(from,to,weight));
    }
    sort(edgeList.begin(),edgeList.end());

    makeSet();
    int cnt =0;
    int totalWeight =0;

    for(auto edge : edgeList){
        if(!unn(edge.from,edge.to)) continue;
        totalWeight += edge.weight;
        cnt ++;
        if(cnt == N-1) break;
    }

    cout << totalWeight <<endl;
    
    return 0;
}