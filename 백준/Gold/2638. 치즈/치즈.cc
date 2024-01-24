#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, T;
int arr[104][104];	//디폴트 0, 외부공기 -1, 치즈 1

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0};


void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
bool out(int x, int y) {	//경계 조건
	return x < 0 || x >= N || y <0 || y >= M;
}

void input() {	//입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}
void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


void airCheck(int x,int y) {	//모눈종이의 맨 가장 자리에는 치즈가 놓이지 않음
	queue<pair<int, int>> q;

	q.push({ x,y });
	arr[x][y] = -1;	//외부공기 마킹

	while (q.size()) {
		auto cord = q.front(); q.pop();
		x = cord.first;
		y = cord.second;	
		for (int i = 0; i < 4; i++) {
			int qx = x + dx[i];
			int qy = y + dy[i];
			if (out(qx, qy)|| arr[qx][qy] == 1) continue;	//나가거나 치즈라면 SKIP
			if (arr[qx][qy] == -1) continue;	//외부공기가 이미 지나갔다면
			arr[qx][qy] = -1;	//여기서 방문처리한다.
			q.push({ qx,qy });	//다음을 위해 PUSH
		}
	}
}

void cheeseCheck(int x,int y) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int qx = x + dx[i];
		int qy = y + dy[i];
		if (out(qx, qy)) continue;
		if (arr[qx][qy] == -1) cnt++;	//외부공기와 접촉했다면 증가
		if (cnt >= 2) break;
	}
	if (cnt >= 2) {
		arr[x][y] = 0;
	}

}



bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {	//치즈가 있다면
				return false;
			}
		}

	}
	return true;	//모든 치즈가 사라졌을 떄
}

void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == -1) {	//다음 외부공기 여부를 알기 위해 원복
				arr[i][j] = 0;	
			}
		}

	}
}



void solve() {
	
	while (true) {
	
		//print();
		
		T++;	//시간 증가
		airCheck(0, 0);
		airCheck(0, M-1);
		airCheck(N-1, 0);
		airCheck(N-1, M-1);	//모눈종이의 가장 자리에서 외부공기 유입 확인

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) cheeseCheck(i, j);	//치즈라면 없어질 치즈인지 확인
			}
		}

		if (check()) {	//모든 치즈가 없어졌다면
			break;
		}
		reset();
		
	}
	



}


int main() {
	fastIO();
	cin >> N >> M;
	input();
	solve();
	
	cout << T << '\n';

	return 0;
}