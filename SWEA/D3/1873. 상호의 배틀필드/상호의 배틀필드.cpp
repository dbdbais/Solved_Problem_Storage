#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int T,H, W, N,dir,curx,cury;
char arr[21][21];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
	// U, R, D, L

bool out(int x,int y) {
	return x < 0 || x >= H || y < 0 || y >= W;
}

void input() {
	string s;
	for (int i = 0; i < H; i++) {
		cin >> s;
		for (int j = 0; j < W; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == '^') {
				curx = i;
				cury = j;
				dir = 0;
			}
			else if (arr[i][j] == '>') {
				curx = i;
				cury = j;
				dir = 1;
			}
			else if (arr[i][j] == 'v') {
				curx = i;
				cury = j;
				dir = 2;
			}
			else if (arr[i][j] == '<') {
				curx = i;
				cury = j;
				dir = 3;
			}
		}
	}
}
void move(char c) {
	if (c == 'U') {
		dir = 0;
		arr[curx][cury] = '^';
	}
	else if (c == 'R') {
		dir = 1;
		arr[curx][cury] = '>';
	}
	else if (c == 'D') {
		dir = 2;
		arr[curx][cury] = 'v';
	}
	else if(c== 'L') {
		dir = 3;
		arr[curx][cury] = '<';
	}
	int qx = curx + dx[dir];
	int qy = cury + dy[dir];
	if (out(qx, qy)|| arr[qx][qy] != '.') return;
	arr[curx][cury] = '.';
	curx = qx;
	cury = qy;
	if (dir == 0) {
		arr[curx][cury] = '^';
	}
	else if (dir == 1) {
		arr[curx][cury] = '>';
	}
	else if (dir == 2) {
		arr[curx][cury] = 'v';
	}
	else if (dir == 3) {
		arr[curx][cury] = '<';
	}

}
void shoot(int x,int y) {
	int qx = x + dx[dir];
	int qy = y + dy[dir];
	if (out(qx, qy)||arr[qx][qy]=='#') return;
	if (arr[qx][qy] == '*') {
		arr[qx][qy] = '.';
		return;
	}
	shoot(qx, qy);
	return;
}
void print() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}
void solve(string cmd) {
	for (int i = 0; i < N; i++) {
		char c = cmd[i];
		if (c == 'S') {
			shoot(curx, cury);
		}
		else {
			move(cmd[i]);
		}
	
	}
}
void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
void reset() {
	memset(arr, ' ', sizeof(arr));
}
int main() {
	string cmd;
	fastIO();
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> H >> W;
		input();	
		cin >> N;
		cin >> cmd;
		solve(cmd);
		cout << "#" << i << " ";
		print();
		reset();
	}
	

	return 0;
}