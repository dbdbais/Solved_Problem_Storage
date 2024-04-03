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

typedef unsigned long long ll;

struct Edge{
    int from;
    int to;
    ll weight;

    Edge(int from,int to, ll weight):from(from),to(to),weight(weight){}

    bool operator<(Edge e){
        return weight < e.weight;
    }

};

vector<Edge> edgeList;

int N, M ;
ll ans,totalCost, A, B, C;
int parents[100004];
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

    For(m,0,M){
        cin >> A >> B >> C;
        totalCost += C;
        edgeList.push_back(Edge(A,B,C));
    }

    makeSet();

    sort(edgeList.begin(),edgeList.end());
    bool isOk =false;
    int edgeCnt =0;
    for(Edge e : edgeList){
        if(!uni(e.from,e.to)) continue;
        ans += e.weight;

        if(++edgeCnt == N-1){
            isOk = true;
            break;
        }
    }
    if(isOk){
        cout << totalCost - ans << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}