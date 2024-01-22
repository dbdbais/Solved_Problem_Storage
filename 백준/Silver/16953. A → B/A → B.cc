#include <iostream>

using namespace std;

int A, B,cnt;

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {	//그리디 알고리즘 풀이
	fastIO();

	cin >> A >> B;
	while (A < B) {
		if (B % 2 == 0) {	//짝수로 나누어 떨어진다면
			B = B / 2;	//2로 나움
		}
		else if (B % 10 == 1) {	//1의 자리 수가 1이라면
			B = B / 10;
		}
		else {
			break;
		}
		cnt++;
	}	//1의 자리 수가 1이라면 짝수로 나누어 떨어질 수 없고, 짝수라면 일의자리 수가 1일 수 없다.

	if (A == B) {
		cout << cnt + 1 << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}