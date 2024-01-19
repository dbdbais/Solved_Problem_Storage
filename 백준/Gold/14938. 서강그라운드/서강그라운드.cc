#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int N, M, R, ans;
int items[104];	//아이템이 들어있는 배열
int dist[104];
const int INF = 1e8;
vector<pair<int, int>> adj[104];

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void dijkstra(int start) {

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;	//최소 힙 선언
	fill(&dist[0], &dist[0] + 104, INF);
	dist[start] = 0;

	pq.push({ 0,start });

	while (pq.size()) {
		auto cord = pq.top();
		int cur_node = cord.second;
		int cur_dist = cord.first;
		pq.pop();

		if (dist[cur_node] != cur_dist) continue;

		for (auto ad : adj[cur_node]) {
			int next_node = ad.second;
			int next_dist = ad.first;

			if (dist[next_node] > dist[cur_node] + next_dist) {
				dist[next_node] = dist[cur_node] + next_dist;
				pq.push({ dist[next_node],next_node });
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		int sm = 0;
		dijkstra(i);	//i번쨰 지점 착륙했을 때
		for (int j = 1; j <= N;j++) {
			if (dist[j] <= M) {
				sm += items[j];	//갈 수 있는 거리의 합을 구한다.
			}
		}
		ans = max(sm, ans);
	}
}


int main() {

	fastIO();

	cin >> N >> M >> R;	//지역의 개수, 수색범위, 길의 개수
	for (int i = 1; i <= N; i++) {	//아이템 입력 받음
		cin >> items[i];
	}
	int a, b, c;

	for (int i = 0; i < R; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });	//양방향 간선
	}

	solve();

	cout << ans << '\n';

	return 0;
}