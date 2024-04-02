#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N, M, K;
const int INF = 1e9;
int ans = INF;
int dp[1001][1001][11];	//2차원 행렬 + 벽 부술 수 있는 기회
int arr[1001][1001];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

void input() {
	string st;
	For(i, 1, N + 1) {
		cin >> st;
		For(j, 1, M + 1) {
			arr[i][j] = st[j - 1]-'0';
		}
	}
}

bool out(int x, int y) {
	return x < 1 || y < 1 || x > N || y > M;
}

void print(int dimension) {

	cout << "D : " << dimension << endl;

	For(i, 1, N + 1) {
		For(j, 1, M + 1) {
			if (dp[i][j][dimension] == INF) {
				cout << "I ";
			}
			else {
				cout << dp[i][j][dimension]<<" ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void solve() {
	queue<pair<int,pair<int, int>>> q;
	q.push({ K,{ 1,1 } });
	dp[1][1][K] = 1;

	while (q.size()) {
		auto cur = q.front(); q.pop();

		int chance = cur.first;
		int x = cur.second.first;
		int y = cur.second.second;

		For(i, 0, 4) {

			int qx = x + dx[i];
			int qy = y + dy[i];

			if (out(qx, qy)) continue;

			if (arr[qx][qy] == 1 && chance > 0 ) {	//벽이고 부술 기회가 있다면
				if (dp[qx][qy][chance-1] > dp[x][y][chance] + 1) {	//이전보다 작아질 수 있다면
					dp[qx][qy][chance-1] = dp[x][y][chance] + 1;
					q.push({ chance-1,{qx,qy} });	//집어 넣는다.
				}
			}
			else if(arr[qx][qy] != 1) {	//그냥 갈 수 있다면
				if(dp[qx][qy][chance] > dp[x][y][chance] + 1){	//이전보다 작아질 수 있다면
					dp[qx][qy][chance] = dp[x][y][chance] + 1;	
					q.push({ chance,{qx,qy} });	//집어 넣는다.
				}	
			}	
		}
		//print(chance);
	}




}

int main() {
	fastIO();
	fill(&dp[0][0][0], &dp[0][0][0] + 1001 * 1001 * 11, INF);
	cin >> N >> M >> K;

	input();
	solve();

	For(i, 0, K+1) {
		if (ans > dp[N][M][i]) ans = dp[N][M][i];
	}
	if (ans == INF) ans = -1;
	
	cout << ans << endl;

	return 0;
}