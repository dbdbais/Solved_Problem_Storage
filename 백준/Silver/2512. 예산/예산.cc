#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

typedef long long ll;

ll N, M, ans;

vector < ll > vec(100004, 0);


ll solve() {
	ll val = 0;
	ll _left = 0;
	ll _right = *max_element(vec.begin(), vec.end());

	while (_left <= _right) {
		ll mid = (_left + _right) / 2;	//상한액 설정
		ll tmpVal = 0;
		ll mxVal = 0;
		For(i, 0, N) {
			if (mid < vec[i]) {	//상한액보다 예산이 많을 경우
				tmpVal += mid;
				if (mxVal < mid) mxVal = mid;
			}
			else {	//작거나 같을 경우
				tmpVal += vec[i];
				if (mxVal < vec[i]) mxVal = vec[i];
			}
		}

		if (M >= tmpVal) {
			val = mxVal;
			//cout << val << endl;
			_left = mid + 1;

		}
		else {
			_right = mid - 1;
		}
	}

	return val;
}


int main() {
	fastIO();
	cin >> N;

	For(i, 0, N) {
		cin >> vec[i];
	}
	cin >> M;

	cout << solve() << endl;


	return 0;
}