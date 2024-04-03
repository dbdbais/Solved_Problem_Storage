//
// Created by newbi on 2024-04-03.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

struct Edge{
    int from;
    int to;
    double weight;

    Edge(int from,int to, double weight):from(from),to(to),weight(weight){}

    bool operator < (Edge e){
        return weight < e.weight;
    }
};

struct Star{
    double x;
    double y;

    Star(double x,double y):x(x),y(y){}

};
int N;
vector<Star> stars;
vector<Edge> edgeList;
double a,b;
int temp[2],parents[101];


double getDistance(Star a, Star b){
    double dx = (a.x - b.x) * (a.x - b.x);
    double dy = (a.y - b.y) * (a.y - b.y);
    return sqrt(dx + dy);
}

void combi(int start,int depth){
    if(depth == 2){
        edgeList.push_back(Edge(temp[0],temp[1], getDistance(stars[temp[0]],stars[temp[1]])));
        return;
    }
    for(int i=start+1;i<stars.size();i++){
        temp[depth] = i;
        combi(i,depth+1);
    }
}

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
    if(aRoot == bRoot) return false;
    parents[bRoot] = aRoot;
    return true;
}

int main(){
    fastIO();
    cin >> N;
    For(i,0,N){
        cin >> a >> b;
        stars.push_back(Star(a,b));
    }
    combi(-1,0);

    /*
    for(Edge e : edgeList){
        cout << e.from <<" : " << e.to <<" : " <<setprecision(3) << e.weight << endl;
    }
     */
    sort(edgeList.begin(),edgeList.end());

    makeSet();

    double ans = 0;
    int cnt =0;

    for(Edge e : edgeList){
        if(!uni(e.from,e.to)) continue;
        ans += e.weight;
        if(++cnt == N-1) break;
    }

    cout << setprecision(3) << ans << endl;

    return 0;
}