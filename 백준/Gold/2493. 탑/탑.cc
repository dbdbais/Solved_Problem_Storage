#include <iostream>
#include <stack>

using namespace std;
int n;
stack<pair<int, int>> stk;	//인덱스와 높이
int ans[500004];

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	fastIO();
	cin >> n;
	int height;
	for (int i = 1; i <= n; i++) {
		cin >> height;
		
		while (stk.size()) {
			auto top = stk.top();
			if (top.second > height) {	//높이가 현재보다 크다면
				ans[i] = top.first;
				break;
			}
			else {
				stk.pop();
			}
		}
		stk.push({ i,height });

	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i]<<" ";
	}


	return 0;
}