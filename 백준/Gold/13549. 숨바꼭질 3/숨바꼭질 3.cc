#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, K;

const int dy[] = { -1,1 };

int dp[200000];	//2를 곱해서 내려오는 경우도 생각해서 2배
bool visited[200000];
int ans = 1e9;	//가장 최대 값 넣어둔다.

bool out(int qx) {
	return qx < 0 || qx >= 200000;
}

void print() {
	For(i, 0, 30) {
		if (dp[i] == 1e9) {
			cout << "I ";
		}
		else {
			cout << dp[i] << " ";
		}
	
	}
	cout << endl;
}

void BFS(int cur) {

	deque<int> dq;
	dp[cur] = 0;
	visited[cur] = true;
	dq.push_back(cur);


	while(dq.size()) {
		int now = dq.front(); dq.pop_front();

		//cout << now << endl;
		//print();
		
		for (int _next : {now * 2, now + 1, now - 1}) {	//현재
			
			if (_next >100001 || out(_next)) continue;	//다음 간선이 나가거나 범위를 초과해버리면
			
			if (_next == now * 2 ) {	//순간이동이라면
				if (dp[_next] > dp[now]) {
					dp[_next] = dp[now];
					dq.push_front(_next);
				}
			}
			else {		//순간이동이 아니라면
				if (dp[_next] > dp[now]+1) {
					dp[_next] = dp[now]+1;
					dq.push_back(_next);
				}
			}

		}

	}



	
}



int main() {
	fastIO();
	cin >> N >> K;
	fill(&dp[0], &dp[0] + 200000, 1e9);
	BFS(N);
	cout << dp[K] << endl;
	return 0;
}