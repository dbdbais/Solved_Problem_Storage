#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N;
int input[1000001];
vector<int> vec;

void print() {
	for (auto elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}

void solve() {

	For(i, 0, N) {
		if (vec.empty() || vec.back() < input[i]) {	//벡터가 비어있거나 뒤에 보다 큰 경우
			//cout << "크거나 비어있다" << endl;
			vec.push_back(input[i]);	//집어넣는다.
		}
		else {
			//cout << "작다" << endl;
			int lb = lower_bound(vec.begin(), vec.end(), input[i])-vec.begin();
			//cout << lb << endl;
			vec[lb] = input[i];
		}
		//print();
	}


}

int main() {
	fastIO();
	cin >> N;

	For(i, 0, N) {
		cin >> input[i];
	}

	solve();
	cout << vec.size() << endl;

	return 0;
}