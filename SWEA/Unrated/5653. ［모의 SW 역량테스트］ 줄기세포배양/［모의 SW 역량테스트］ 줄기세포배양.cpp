#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

struct Cell {
	int x;
	int y;
	int state;
	int time;
	Cell(int x,int y,int state,int time):x(x),y(y),state(state),time(time) {
		
	}

	bool operator < (const Cell c) {	//내림차순 정렬
		return state > c.state;
	}
};

vector<Cell> vec;
const int INF = 1e9;
const int c = 250;
int N, M, K, T;

int arr[500][500];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


void print() {
	For(i, 240, 260) {
		For(j, 240, 260) {
			if (arr[i][j] == INF) cout << "D ";
			else cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

void move() {
	queue<Cell> q;
	sort(vec.begin(), vec.end());	//내림차순 정렬
	for (Cell &c : vec) {
		c.time= c.time -1;	//시간하나 감소

		if (c.time == -1) {	//타이머가 다 흘렀다면
			for (int i = 0; i < 4; i++) {
				int qx = c.x + dx[i];
				int qy = c.y + dy[i];

				if (arr[qx][qy] != 0) continue;	// 빈 공간이 아니라면
				arr[qx][qy] = c.state;
				q.push(Cell(qx, qy, c.state,c.state));	//다음에 추가할 셀에 넣어준다

			}


		}
		if (c.time == c.state * -1) {
			arr[c.x][c.y] = INF;
		}
	}
	vec.erase(remove_if(vec.begin(), vec.end(), [&](const Cell& c) {	//시간 다된거 다 지워주고
		return c.time == c.state * -1;
	}), vec.end());

	while (q.size()) {	//추가된 것들 넣어준다.
		vec.push_back(q.front());
		q.pop();
	}
	/*
	for (Cell c : vec) {
		cout << "( " << c.x << ", " << c.y << " ) " << "Time : " << c.time << "  State : " << c.state << endl;

	}
	*/
}


void solve() {
	For(i, 0, K) {
		move();
		//print();
	}

}

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	For(i, 1+c, N+c+1) {
		For(j, 1+c, M+c+1) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) {
				vec.push_back(Cell(i, j, arr[i][j],arr[i][j]));	//세포면 집어넣는다.
			}
		}
	}
}

void reset() {

	vec.clear();
	fill(arr[0], arr[500], 0);
}

int main() {
	fastIO();
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		input();
		solve();
		cout << "#" << t << " " << vec.size() << endl;
		reset();


	}

	return 0;
}