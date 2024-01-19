#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M ,T, P, ans;

int truth[54];	//진실을 알고 있는 사람 인덱스 1로, 안들은 사람은 0, 과장된 이야기 -1

vector<int>party[54];

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool check(vector<int> arr, int par) {
	bool ret = true;
	for (auto elem : arr) {
		if (truth[elem] == 0) continue;	//아무것도 모르는 사람은 제외
		if (truth[elem] != par) {	//진실과 과장이 엇갈릴 경우
			ret = false;
			break;
		}
	}

	return ret;
}


void DFS(int idx,int cnt) {

	if (idx == M) {//파티의 MAX값 도달 시
		if (cnt > ans) {
			ans = cnt;
		}
		return;
	}

	if (check(party[idx], -1)) {	//파티에 과장된 사실을 알고 있는 사람만 있는지 확인
		//cout << "idx: " << idx << " check -1" << endl;
		int temp[54];
		copy(truth, truth + 54, temp);	//잠깐 복사해놓는다.
		for (auto elem : party[idx]) {
			truth[elem] = -1;
		}
		cnt++;
		DFS(idx + 1, cnt);
		copy(temp, temp + 54, truth);
		cnt--;
	}

	if (check(party[idx], 1)) {	//파티에 진실된 사실을 알고 있는 사람만 있는지 확인
		//cout << "idx: " << idx << " check 1" << endl;
		int temp[54];
		copy(truth, truth + 54, temp);	//잠깐 복사해놓는다.
		for (auto elem : party[idx]) {
			truth[elem] = 1;
		}
		DFS(idx + 1, cnt);
		copy(temp, temp + 54, truth);
	}
	return;
	
}



int main() {
	fastIO();

	cin >> N >> M >> T ;	//사람의 수, 파티의 수, 진실을 아는 사람의 수
	int input,pt;
	for (int i = 0; i < T; i++) {
		cin >> input;	//진실자 인덱스
		truth[input] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> P;	//파티에 참여한 사람의 수
		for (int j = 0; j < P; j++) {
			cin >> pt;	//파티에 참여하는 사람의 인덱스
			party[i].push_back(pt);		//해당하는 파티에 push
		}
	}

	DFS(0, 0);

	cout << ans << '\n';

	return 0;
}