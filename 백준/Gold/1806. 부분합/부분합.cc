#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;

ll S;

ll dp[100004];
ll arr[100004];
int N;
int ans = 1e9;
int fdx, ldx;

void solve() {
	while ( true ) {	//마지막에 도달하면 나온다.

		//cout <<"앞 : "<< fdx << " : " << "뒤 : " << ldx << endl;

		int tmpSm = dp[ldx] - dp[fdx];	//현재 부분합
		//cout << "부분 합 :" << tmpSm << endl;

		if (tmpSm >= S) {
			int length = ldx - fdx;	//길이
			if (ans > length) {
				//cout<<"최소값 갱신 : " << length << endl;
				ans = length;
			}//최소값 갱신
			if (fdx < N) {
				fdx++;	//앞의 인덱스를 떙겨온다.
			}
			
		}
		else {	//작다면
			if (ldx < N) {
				ldx++;	//뒤에 인덱스를 증가한다.
			}
			else {	//가망이 없으므로 끝낸다.
				break;
			}
		}
		
	}
}

int main() {
	fastIO();
	cin >> N >> S;
	For(i, 1, N+1) {
		cin >> arr[i];
		dp[i] = dp[i - 1] + arr[i];	//누적합 구한다.
	}

	solve();
	if (ans == 1e9) {
		ans = 0;
	}
	cout << ans << endl;

	return 0;
}