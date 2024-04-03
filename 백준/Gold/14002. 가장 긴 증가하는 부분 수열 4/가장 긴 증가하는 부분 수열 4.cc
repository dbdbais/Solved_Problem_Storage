#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N;
const int mx = 1000001;
int input[1000001];
int vecIdx[1000001];	//LIS의 index가 저장 될 배열 (벡터와 동일)
int inputIdx[mx];	//인풋의 원소의 가장 최근 인덱스
vector<int> vec;

void print() {
	for (int i = 0; i < N; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
	
	for (int i = 0; i < N; i++) {
		cout << vecIdx[i] << " ";
	}
	cout << endl;

}

void traceBack() {
	int tmp = inputIdx[vec.back()];	//맨 마지막 벡터의 인덱스
	stack<int>stk;
	while (tmp != -1) {
		stk.push(input[tmp]);
		tmp = vecIdx[tmp];
	}

	while (stk.size()) {
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl;
}

void solve() {

	For(i, 0, N) {
		inputIdx[input[i]] = i;	//현재 인풋의 인덱스 저장

		if (vec.empty() || vec.back() < input[i]) {	//벡터가 비어있거나 뒤에 보다 큰 경우
			//cout << "크거나 비어있다" << endl;
			if (vec.size()) {
				vecIdx[i] = inputIdx[vec.back()];	//추가되었을 때 맨 뒤에 있던 수의  최근 인덱스를 집어넣는다.
			}
			else {
				vecIdx[i] = -1;	//끝을 알림
			}
			vec.push_back(input[i]);	//집어넣는다.
			
		}
		else {
			//cout << "작다" << endl;
			int lb = lower_bound(vec.begin(), vec.end(), input[i])-vec.begin();
			//cout << lb << endl;
			if (lb == 0) {	//앞에 작은게 아무것도 없다면
				vecIdx[i] = -1;
			}
			else {	//바로 앞의 벡터상의 위치 넣는다.
				vecIdx[i] = inputIdx[vec[lb - 1]];
			}
			vec[lb] = input[i];
		}
	
	}
	//print();

}

int main() {
	fastIO();
	cin >> N;

	For(i, 0, N) {
		cin >> input[i];
	}

	solve();
	cout << vec.size() << endl;
	traceBack();
	return 0;
}