//
// Created by newbi on 2024-04-16.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int parents[500004];
int N,M;
vector<int>adjList[500004];
struct edge {
    int from;
    int to;
    int no;
    edge(int from,int to,int no):from(from),to(to),no(no){}

    bool operator<(edge e) {
        return no < e.no;
    }
    void printInfo() {
        cout << from << ", " << to << "  no : " << no << endl;
    }
};


vector<edge>edgeList;



void makeSet() {
    For(i, 0, N + 1) {
        parents[i] = i;
    }
}

int pFind(int a) {
    if (a == parents[a]) return a;
    return parents[a] = pFind(parents[a]);
}

bool uni(int a, int b) {
    int aRoot = pFind(a);
    int bRoot = pFind(b);

    if (aRoot == bRoot) {
        return false;
    }
    else {
        parents[bRoot] = aRoot;
        return true;
    }

}

int main() {

    fastIO();
    cin >> N >> M;

    int a =0, b=0 ,no=1;
    For(i, 0, M) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        edgeList.push_back(edge(a, b,no++));
    }
    int rec = 0;

    sort(edgeList.begin(), edgeList.end());

    makeSet();

    for (auto elem : edgeList) {
        if(!uni(elem.to,elem.from)){    //부모가 같다면
            rec = elem.no;
            break;
        }
    }

    cout << rec << endl;

    return 0;
}