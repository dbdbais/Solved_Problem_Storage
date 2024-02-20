#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int T, N, M, R, C, L;

int arr[50][50];
int visited[50][50];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
bool out(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

void BFS(int x,int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (q.size()) {
		vector<pair<int, int>> direc;
		auto cord = q.front(); q.pop();
		x = cord.first;
		y = cord.second;
		int type = arr[x][y];

		if (type == 1) {
			direc.push_back({ 0,-1 });
			direc.push_back({ 0,1 });
			direc.push_back({ -1,0 });
			direc.push_back({ 1,0 });
		}
		else if (type == 2) {
			direc.push_back({ -1,0 });
			direc.push_back({ 1,0 });
		}
		else if (type == 3) {
			direc.push_back({ 0,-1 });
			direc.push_back({ 0,1 });
		}
		else if (type == 4) {
			direc.push_back({ -1,0 });
			direc.push_back({ 0,1 });
		}
		else if (type == 5) {
			direc.push_back({ 0,1 });
			direc.push_back({ 1,0 });
		}
		else if (type == 6) {
			direc.push_back({ 0,-1 });
			direc.push_back({ 1,0 });
		}
		else if (type == 7) {
			direc.push_back({ 0,-1 });
			direc.push_back({ -1,0 });
		}

		for (auto d : direc) {
			int qx = x + d.first;
			int qy = y + d.second;

			if (out(qx, qy) || visited[qx][qy] > 0 || !arr[qx][qy]) continue;	//나가거나 방문되었거나 아무것도 없다면

			if (d.first == 1 && d.second == 0) {	// 아래
				if (arr[qx][qy] == 3 || arr[qx][qy] == 5 || arr[qx][qy] == 6) continue;
			}
			else if (d.first == 0 && d.second == 1) {	// 우
				if (arr[qx][qy] == 2 || arr[qx][qy] == 4 || arr[qx][qy] == 5) continue;
			}
			else if (d.first == -1 && d.second == 0) { // 위
				if (arr[qx][qy] == 3 || arr[qx][qy] == 4 || arr[qx][qy] == 7) continue;
			}
			else if(d.first == 0 && d.second == -1){	// 좌
				if (arr[qx][qy] == 2 || arr[qx][qy] == 6 || arr[qx][qy] == 7) continue;
			}

			visited[qx][qy] = visited[x][y] + 1;
			q.push({ qx,qy });

		}
	}
}

void print() {
	cout << endl;
	For(i, 0, N) {
		For(j, 0, M) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int count() {
	int cnt = 0;
	For(i, 0, N) {
		For(j, 0, M) {
			if (visited[i][j] <= L && visited[i][j] !=0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void reset() {
	fill(&visited[0][0], &visited[0][0] + 50 * 50, false);
}

int main() {
	fastIO();
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C >> L;
		
		For(i, 0, N) {
			For(j, 0, M) {
				cin >> arr[i][j];
			}
		}
		BFS(R, C);
		//print();
		cout << "#" << t << " " << count() << endl;
		reset();



	}

	

	return 0;
}
