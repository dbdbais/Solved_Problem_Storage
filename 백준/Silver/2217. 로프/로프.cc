#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N ,ans;
vector<int> v;


int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int k = 1; k <= N; k++) {
		ans = max(ans, v[N - k] * k);
		//cout << ans << endl;
	}
	cout << ans << endl;

	return 0;
}