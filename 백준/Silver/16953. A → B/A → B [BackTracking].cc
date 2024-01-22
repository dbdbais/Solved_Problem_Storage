#include <iostream>

using namespace std;

typedef long long ll;	//입력이 10^9 가 들어옴에 유의

ll A, B,ans=-1;
void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void solve(ll n, ll cnt) {
	//cout << "n : " << n << " count : " << cnt << endl;
	if (n == B) {
		if (ans < cnt) ans = cnt;
		return;
	}

	if (n*2 <= B) {
		cnt++;
		solve(n * 2, cnt);
		cnt--;
	}
	if (n * 10 + 1 <= B) {
		cnt++;
		solve(n * 10 + 1, cnt);
		cnt--;
	}
	return;

}



int main() {
	fastIO();
	cin >> A >> B;
	solve(A, 1);
	if (A == B) {	//A와 B가 같은 반례
		cout << 0 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}
