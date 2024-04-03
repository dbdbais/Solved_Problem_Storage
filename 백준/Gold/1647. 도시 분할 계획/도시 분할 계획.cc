//
// Created by newbi on 2024-04-03.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int N,M,A,B,C;

struct Edge{
    int from;
    int to;
    int weight;

    Edge(int from,int to, int weight):from(from),to(to),weight(weight){}

    bool operator< (Edge e){
        return weight < e.weight;
    }
};

int parents[100002];
vector<Edge> edgeList;

void makeSet(){
    For(i,1,N+1){
        parents[i] = i;
    }
}

int find(int a){
    if(parents[a] == a) return a;
    return parents[a] = find(parents[a]);
}

bool uni(int a,int b){
    int aRoot = find(a);
    int bRoot = find(b);
    if(aRoot == bRoot){
        return false;
    }
    parents[bRoot] = aRoot;
    return true;
}

int main(){
    fastIO();
    cin >> N >> M;
    For(i,0,M){
        cin >> A >> B >> C;
        edgeList.push_back(Edge(A,B,C));
    }

    sort(edgeList.begin(),edgeList.end());

    makeSet();

    int cnt = 1;    //분리된 마을을 위해 하나 표시
    int ans = 0;
    if(N != 2) {
        for (Edge e: edgeList) {
            if (!uni(e.from, e.to)) continue;
            //cout << e.weight << endl;
            ans += e.weight;

            if (++cnt == N - 1) break;
        }
    }

    cout << ans << endl;
    return 0;
}