#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int T,N,K ,input[28];
vector<string> ans;

int convert(string s) {
	int num = 0;
	int digit = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (isalpha(s[i])) {
			int tmp = s[i] - 'A';	//A : 0 B : 1 C : 2 D : 3 E : 4 F : 5
			tmp += 10;
			num += tmp * digit;
		}
		else {
			num += (s[i] - '0')*digit;
		}
		digit *= 16;	//자릿 수 증가
	}
	return num;
}

bool custom(string s1, string s2) {

	return convert(s1) > convert(s2);

}

void generate(string s) {
	deque<char>q[4];

	int idx = 0;
	int mod = N / 4;

	int qidx = -1;
	for (char c : s) {	//하나하나 잘라서 넣는다.
		if (idx % mod == 0) qidx++;	//큐 인덱스 증가
		q[qidx].push_back(c);
		idx++;
	}

	For(i, 0, mod) {

		string elem;
		For(i, 0, 4) {
			elem = "";
			For(j, 0, q[i].size()) {
				elem += q[i].at(j);
			}
			ans.push_back(elem);
		}

		q[0].push_front(q[3].back());
		q[1].push_front(q[0].back());
		q[2].push_front(q[1].back());
		q[3].push_front(q[2].back());

		For(j, 0, 4) {	//하나 씩 넣어서 pop한다.
			q[j].pop_back();
		}
		
	}
}

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	fastIO();

	cin >> T;
	string s;
	For (t, 1, T + 1) {
		cin >> N >> K;

		cin.ignore();	//버퍼 비운다.
		getline(cin, s);

		generate(s);
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());	//중복 제거
		sort(ans.begin(), ans.end(), custom);

		cout << "#" << t << " " << convert(ans[K-1]) << endl;

		ans.clear();


	}

	return 0;
}
