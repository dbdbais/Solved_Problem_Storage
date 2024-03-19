#include <iostream>
#include <algorithm>
#include <iterator>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int mxDP[3];	//최대
int mnDP[3];	//최소
int _next[3];		//다음 입력
int mxTemp[3];
int mnTemp[3];
int N,mx,mn = 1e9;

void input() {
	int tmp;
	For(i, 0, 3) {
		cin >> tmp;
		mxTemp[i] = tmp;
		mnTemp[i] = tmp;
		mxDP[i] = tmp;
		mnDP[i] = tmp;
	}
}
void print() {
	For(i, 0, 3) {
		cout << mxDP[i] << " ";
	}
	cout << endl;
	For(i, 0, 3) {
		cout << mnDP[i] << " ";
	}
	cout << endl;

}

void solve() {
		For(i, 0, N -1) {
			For(j, 0, 3) {
				cin >> _next[j];
			}
			mxDP[0] = max(mxTemp[0] + _next[0], mxTemp[1] + _next[0]);
			mxDP[1] = max({ mxTemp[0] + _next[1], mxTemp[1] + _next[1], mxTemp[2] + _next[1] });
			mxDP[2] = max(mxTemp[1] + _next[2], mxTemp[2] + _next[2]);

			mnDP[0] = min(mnTemp[0] + _next[0], mnTemp[1] + _next[0]);
			mnDP[1] = min({ mnTemp[0] + _next[1], mnTemp[1] + _next[1], mnTemp[2] + _next[1] });
			mnDP[2] = min(mnTemp[1] + _next[2], mnTemp[2] + _next[2]);

			//print();
			copy(mxDP, mxDP + 3, mxTemp);
			copy(mnDP, mnDP + 3, mnTemp);
		}
	mx = max({ mxDP[0],mxDP[1] ,mxDP[2] });
	mn = min({ mnDP[0],mnDP[1] ,mnDP[2] });
}

int main() {
	fastIO();
	cin >> N;
	input();
	solve();
	cout << mx << " " << mn << endl;

	return 0;

}