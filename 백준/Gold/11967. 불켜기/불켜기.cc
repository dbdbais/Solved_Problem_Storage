#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

int N, M;

bool visited[103][103];	//방문한 방
bool lvisited[103][103];	//불을 켠 좌표 방문 여부
bool light[103][103];	//불 켜진 방
vector<pair<int, int>> cord[103][103];	//불을 켤 수 있는 좌표가 들어있음

bool out(int x, int y) {	//장외 처리
	return x<1 || y <1 || x > N || y > N;
}

void print() {
	cout << "VISITED " << endl;
	For(i, 1, N + 1) {
		For(j, 1, N + 1) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "Light" << endl;
	For(i, 1, N + 1) {
		For(j, 1, N + 1) {
			cout << light[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void BFS() {
	queue<pair<int, int>> q;
	light[1][1] = true;
	visited[1][1] = true;
	q.push({ 1,1 });
	while (q.size()) {
		auto cur = q.front(); q.pop();
		int x = cur.first;
		int y = cur.second;
		//cout <<"x : "<< x <<"y : " << y << endl;
		
		if (cord[x][y].size() && !lvisited[x][y]) {	//불을 켤 수 있는 자리가 있다면
			lvisited[x][y] = true;	//방문 처리

			for (auto elem : cord[x][y]) {
				
				light[elem.first][elem.second] = true;	//불을 켠다.
			}
			memset(visited, false, sizeof(visited));
			//방문 초기화하고
			visited[x][y] = true;
			//현재위치는 방문 했다고 함
		}
		//print();

		For(i, 0, 4) {
			int qx = x + dx[i];
			int qy = y + dy[i];

			if (out(qx, qy) || visited[qx][qy] || !light[qx][qy]) continue;
			//나갔거나, 방문했거나, 불이 켜져있지 않다면 SKIP

			visited[qx][qy] = true;	//방문 처리
			q.push({ qx,qy });	//다음탐색을 위해 큐에 넣는다.
		}

		//print();

	}
}

void input() {
	int x, y, a, b;
	For(i, 0, M) {
		cin >> x >> y >> a >> b;
		cord[x][y].push_back({ a,b });	//킬수 있는 곳을 전부 넣는다.
	}
}

int count() {
	int cnt = 0;
	For(i, 1, N + 1) {
		For(j, 1, N + 1) {
			if (light[i][j]) cnt++;
		}
	}
	return cnt;
}



int main() {
	fastIO();
	cin >> N >> M;
	input();
	BFS();
	cout << count() << endl;

	return 0;
}