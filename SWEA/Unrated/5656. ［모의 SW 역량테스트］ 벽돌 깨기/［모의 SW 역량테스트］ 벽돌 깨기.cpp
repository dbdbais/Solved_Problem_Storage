//
// Created by newbi on 2024-02-26.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int N, W, H, T;

int arr[17][14];
int copyArr[17][14];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans = 1e9;
bool out(int x, int y) {
	return x < 0 || y < 0 || x >= H || y >= W;
}
void pop(int x, int y, int weight) {	//연쇄 폭탄 터짐 처리
	for (int p = 1; p < weight; p++) {
		for (int i = 0; i < 4; i++) {
			int qx = x + dx[i] * p;
			int qy = y + dy[i] * p;
			if (out(qx, qy)) continue;

			if (arr[qx][qy] > 1) {  //1보다 크다면 연쇄 폭탄
				int tmp = arr[qx][qy];
				arr[qx][qy] = 0;
				pop(qx, qy, tmp);
			}
			else {
				arr[qx][qy] = 0;
			}

		}
	}
}

void scoop() {
	for (int i = 0; i < W; i++) {
		stack<int> stk;
		for (int j = 0; j < H; j++) {
			if (arr[j][i] > 0) {
				stk.push(arr[j][i]);
				arr[j][i] = 0;
			}
		}
		for (int j = H - 1; j >= 0; j--) {
			if (stk.size()) {
				arr[j][i] = stk.top();
				stk.pop();
			}
			else {
				arr[j][i] = 0;
			}
		}

	}
}
bool isBlock(int y) {
	For(i, 0, H) {
		if (arr[i][y]) return true;
	}
	return false;
}

void ballDrop(int y) {
	if (!isBlock(y)) return; //블럭이 없다면
	int x = 0;
	while (true) {
		if (out(x, y)) {
			break;
		}
		if (arr[x][y] > 0) break;
		x++;
	}
	int weight = arr[x][y];
	arr[x][y] = 0;
	pop(x, y, weight);
	scoop();
}

void print() {
	For(i, 0, H) {
		For(j, 0, W) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

int count() {
	int cnt = 0;
	For(i, 0, H) {
		For(j, 0, W) {
			if (arr[i][j] > 0) cnt++;
		}
	}
	return cnt;
}

void solve(int depth,int index) {	//카운트를 넘겨야?

	if (depth == N) {	//N개에 도달 했을 때
		if (ans > count()) {
			ans = count();
		}
		return;
	}

	int tempArr[17][14];	//임시 저장 배열
	copy(&arr[0][0], &arr[0][0] + 17 * 14, &tempArr[0][0]);	//현재 배열 상태 복사
	for (int i = 0; i < W; i++) {
		ballDrop(i);	//드랍하고
		solve(depth+1,i);	//다음으로 패스
		copy(&tempArr[0][0], &tempArr[0][0] + 17 * 14, &arr[0][0]);	//원 상태로 원복
	}
}

void input() {
	For(i, 0, H) {
		For(j, 0, W) {
			cin >> arr[i][j];
		}
	}
}
void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void reset() {
	For(i, 0, H) {
		For(j, 0, W) {
			arr[i][j] = copyArr[i][j];
		}
	}
	ans = 1e9;
}

int main() {
	fastIO();
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> W >> H;
		input();
		
		vector<int>v;
		solve(0,0);

		cout << "#" << t << " " << ans << endl;
		reset();
	}

	return 0;
}