#include <iostream>

using namespace std;

int N;

int dp [1004];

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}



int main() {
	fastIO();
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i-1]%10007 + dp[i-2]%10007;
	}

	cout << dp[N]%10007 << '\n';

	return 0;
}