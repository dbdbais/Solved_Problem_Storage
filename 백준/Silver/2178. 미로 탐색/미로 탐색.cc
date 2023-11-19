#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N, M;
int maze[101][101];
int visited[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool out(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void input() {
	string st;
	for (int i = 0; i < N; i++) {
		cin >> st;
		for (int j = 0; j < M; j++) {
			maze[i][j] = st[j]-'0';
		}
	}
}

void BFS(int x,int y) {

	visited[x][y] = 1;

	queue<pair<int, int>> q;
	q.push({ x,y });

	while (q.size()) {
		auto cord = q.front(); q.pop();
		x = cord.first;
		y = cord.second;

		for (int i = 0; i < 4; i++) {
			int qx = x + dx[i];
			int qy = y + dy[i];
			
			if (out(qx, qy)||maze[qx][qy] == 0) continue;
			if (visited[qx][qy]) continue;
			visited[qx][qy] = visited[x][y] + 1;
			q.push({ qx,qy });
		}
	}

}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	
	cin >> N >> M;
	input();
	BFS(0, 0);
	//print();
	cout << visited[N - 1][M - 1] << '\n';

	return 0;
}