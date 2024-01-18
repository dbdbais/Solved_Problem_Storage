#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
int N, M, A, B, fs,fe;
ll weight;
const int INF = 1e8;

vector<pair<ll, int>> adj[1004];   //노드간 연결 경로 인접리스트
int route[1004];    //최단거리로 갱신 시킨 배열
ll dist[1004]; //최종 거리가 저장 될 배열

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dijkstra(int start) {

    priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;    //최소 힙
    
    pq.push({ 0,start });
    dist[start] = 0;    //첫 시작점 초기화

    while (pq.size()) {
        auto cur= pq.top(); //제일 최소 경로를 가지는 앞의 노드 가져온다.
        pq.pop();
        int cur_node = cur.second;  //현재 노드 
        ll cur_dist = cur.first;   //현재 노드 거리

        if (dist[cur_node] != cur_dist) continue;   //만약 가장 최근 갱신된 노드가 아니라면 SKIP

        for (auto ad : adj[cur_node]) {   //현재 노드와 인접한 모든 노드 가져옴
            int next_node = ad.second;    //인접 노드
            ll next_dist = ad.first;     //인접 노드 거리

            if (dist[next_node] > dist[cur_node] + next_dist) { //최소거리 갱신
                dist[next_node] = dist[cur_node] + next_dist;
                route[next_node] = cur_node; //경로 추적을 위해 거리가 갱신된 이전 경로를 저장
                pq.push({ dist[next_node],next_node });
            }
        }
    }
}


int main() {
    fastIO();

    fill(&dist[0], &dist[0] + 1004, INF); //거리 배열 무한대로 초기화

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> weight;
        adj[A].push_back({ weight,B }); //간선 인접리스트에 PUSH
    }
    cin >> fs >> fe;

    dijkstra(fs);

    cout << dist[fe] << '\n';

    vector<int> ans;
    ans.push_back(fe);  //도착 노드 넣기
    int tmp = route[fe];    //맨 마지막 루트 넣기

    while (tmp) {
        ans.push_back(tmp);
        tmp = route[tmp];
    }

    cout << ans.size() << '\n';

    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;

}