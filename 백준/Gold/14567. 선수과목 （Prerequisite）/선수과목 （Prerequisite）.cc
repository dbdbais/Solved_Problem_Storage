#include <iostream>
#include <queue>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int N, M;

int semester[1001];	//정답 배열
vector<int> adjList[1001];	//인접리스트
int cnt[1001];	//차수 카운팅

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	
	cin >> N >> M;

	int a, b;
	For(i, 0, M) {
		cin >> a >> b;
		adjList[a].push_back(b);	//인접 리스트 연결
		cnt[b]++;
	}
	int ct = 0;
	int T = 1;
	while (ct != N) {
		vector<int> temp;
		For(i, 1, N + 1) {
			if (cnt[i] == 0) {
				ct++;
				semester[i] = T;
				cnt[i] = -1;
				for (auto adj : adjList[i]) {	//감소할 놈 저장
					temp.push_back(adj);
				}
			}
		}
		for (auto dec : temp) {	//반복문 이후에 감소
			cnt[dec]--;
		}

		T++;	//시간 증가
	}
	
	For(i, 1, N + 1) {
		cout << semester[i] << " ";
	}
	cout << endl;

	return 0;
}