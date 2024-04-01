#include <iostream>
#include <queue>
#include <set>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N, M, T, x, d, k;

struct Ord {
	int x;
	int d;
	int k;

	Ord(int x, int d, int k) :x(x), d(d), k(k) {}
};

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

bool out(int x, int y) {
	return x < 1 || y < 0 || x > N || y >= M;
}



deque<int> dq [51];
queue<Ord> order;
void output() {
	For(i, 1, N + 1) {
		For(j, 0, M) {
			cout << dq[i].at(j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int count() {
	int sm = 0;
	For(i, 1, N + 1) {
		For(j, 0, M) {
			if (dq[i].at(j) == 0) continue;
			sm += dq[i].at(j);
		}
	}
	return sm;
}
double avgCount() {
	int sm = 0;
	int dividor = 0;
	For(i, 1, N + 1) {
		For(j, 0, M) {
			if (dq[i].at(j) == 0) continue;
			sm += dq[i].at(j);
			dividor++;
		}
	}
	return (sm*1.0)/dividor;
}

void input() {
	int tmp;
	For(i, 1, N+1) {
		For(j, 0, M) {
			cin >> tmp;
			dq[i].push_back(tmp);
		}
	}
	For(i, 0, T) {
		cin >> x >> d >> k;
		order.push(Ord(x, d, k));
	}
}

void afterService(double c) {
	For(i, 1, N + 1) {
		For(j, 0, M) {
			if (dq[i].at(j) == 0) continue;
			if (dq[i].at(j)>c) {	//j가 
				dq[i].at(j) -= 1;
			}
			else if(dq[i].at(j) < c) {
				dq[i].at(j) += 1;
			}
			
		}
	}
}

bool isNear() {
	bool found = false;
	set<pair<int, int>> deleted;
	For(i, 1, N + 1) {
		For(j, 0, M) {
			
			int cpos = dq[i].at(j);	//현제 덱의 위치의 값
			For(a, 0, 4) {
				int qx = i + dx[a];
				int qy = j + dy[a];
				if (out(qx, qy)) {	//나갔다면
					if (qx < 1) {
						continue;
					}
					else if (qx > N) {
						continue;
					}
					else if (qy < 0) {
						qy = M-1;
					}
					else if (qy >= M) {
						qy = 0;
					}
				}
				if (dq[qx].at(qy) == 0) continue;	//나갔거나 0이라면 SKIP
				if (dq[qx].at(qy) == cpos) {
					found = true;
					deleted.insert({ i,j });
					deleted.insert({ qx,qy });
				}	
			}
		}
	}
	

	for (pair<int,int> cord : deleted) {
		int x = cord.first;
		int y = cord.second;
		dq[x].at(y) = 0;	//날린다.
	}


	return found;

}


void solve() {
	while (order.size()) {
		auto cur = order.front(); order.pop();
		int x = cur.x;
		int d = cur.d;
		int k = cur.k;

		For(i, 1, N + 1) {	//원통 회전
			if (i % x == 0) {	//x로 나뉘어 떨어진다면
				if (d == 0) {	//시계방향으로
					For(j, 0, k) {
						dq[i].push_front(dq[i].back());
						dq[i].pop_back();
					}
				}
				else {	//반시계 방향으로
					For(j, 0, k) {
						dq[i].push_back(dq[i].front());
						dq[i].pop_front();
					}
				}
				
				
			}
		}
		//붙어 있는거 삭제 처리
		
		if (!isNear()) {	//없다면
			double c = avgCount();
			afterService(c);

		}
	
	}
	cout << count() << endl;
}

int main() {
	fastIO();
	cin >> N >> M >> T;

	input();
	solve();

	return 0;
}