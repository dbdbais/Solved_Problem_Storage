#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,T,ans = -1;
int a[1000004];	//과자 봉지

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void solve(int idx,vector<int> v,int weight) {
	if(v.size() == 2){
		ans = max(ans, weight);
		return;
	}
	for (int i = idx + 1; i < N; i++) {
		if (a[i] <= M) {
			v.push_back(i);
			weight += a[i];
			if (weight <= M) {
				solve(i, v, weight);
			}
			weight -= a[i];
			v.pop_back();
		}
	}
	return;
}

void reset() {
	ans = -1;
	memset(a, 0, sizeof(a));
}

int main() {
	fastIO();

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M;
		for (int j = 0; j < N; j++) cin >> a[j];
		vector<int>v;
		solve(-1, v,0);
		cout << "#" << i << " " << ans << '\n';
		reset();

	}

	return 0;
}