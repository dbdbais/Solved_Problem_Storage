#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int T, N;
int arr[24][24];

int dx[] = { 0,0,-1,1,-1,-1,1,1 };
int dy[] = { 1,-1,0,0,-1,1,-1,1 };
bool found;

bool out(int x,int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void input() {
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			if (tmp[j] == '.') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 1;
			}
		}
	}
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void DFS(int x,int y,int dir,int sm) {
	if (sm >= 5) {
		found = true;
		return;
	}
	int qx = x + dx[dir];
	int qy = y + dy[dir];

	if (out(qx,qy) || arr[qx][qy] == 0) return;	//나갔거나, .이거나
	if (arr[qx][qy] == 1) {
		DFS(qx, qy, dir, sm + 1);
	}
	return;
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 8; k++) {
				if (found) break;
				if (arr[i][j] == 1) {
					DFS(i, j, k, 1);
				}
			}
			if (found) break;
		}
		if (found) break;
	}
}
void reset() {
	found = false;
	memset(arr, 0, sizeof(arr));
	N = 0;
}

int main() {

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		input();
		//print();
		solve();
		cout << "#" << i << " ";
		if (found) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		reset();

	}
	return 0;
}
