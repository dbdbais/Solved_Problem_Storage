#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V, dist, far_node;

vector<pair<int, int>> adj[100004];   //거리,연결된 정점
bool visited[100004];


void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



void DFS(int cur, int sm) {
    visited[cur] = true;

    if (sm > dist) {
        dist = sm;
        far_node = cur;
    }
    for (auto node : adj[cur]) {
        int distance = node.first;  //거리
        int con = node.second;  //연결된 정점
        if (!visited[con]) {
            DFS(con, sm + distance);
        }

    }
    return;
}



int main() {
    fastIO();

    int parent,child,weight;
    cin >> V;

    for (int i = 0; i < V; i++) {
        cin >> parent;
        while (cin >> child) {
            if (child == -1) break;
            cin >> weight;
            adj[parent].push_back({ weight,child });
        }
    }
    DFS(1, 0);   //루트 노드에서 가장 먼 노드랑 값 찾기

    memset(visited, false, sizeof(visited));  //방문 배열 초기화

    DFS(far_node, 0);    //가장 먼 노드에서 가장 먼 노드 찾으면 그것이 트리의 지름
    //cout << far_node <<endl;
    cout << dist << '\n';   //거리 출력

    return 0;

}