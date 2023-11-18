#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cnt[10];
int T,N;

void conv(string s) {
	if (s == "ZRO") {
		cnt[0]++;
	}
	else if (s == "ONE") {
		cnt[1]++;
	}
	else if (s == "TWO") {
		cnt[2]++;
	}
	else if (s == "THR") {
		cnt[3]++;
	}
	else if (s == "FOR") {
		cnt[4]++;
	}
	else if (s == "FIV") {
		cnt[5]++;
	}
	else if (s == "SIX") {
		cnt[6]++;
	}
	else if (s == "SVN") {
		cnt[7]++;
	}
	else if (s == "EGT") {
		cnt[8]++;
	}
	else if (s == "NIN") {
		cnt[9]++;
	}
	
}
string out(int i) {
	if (i == 0) {
		return "ZRO";
	}
	else if (i == 1) {
		return "ONE";
	}
	else if (i == 2) {
		return "TWO";
	}
	else if (i == 3) {
		return "THR";
	}
	else if (i == 4) {
		return "FOR";
	}
	else if (i == 5) {
		return "FIV";
	}
	else if (i == 6) {
		return "SIX";
	}
	else if (i == 7) {
		return "SVN";
	}
	else if (i == 8) {
		return "EGT";
	}
	else if (i == 9) {
		return "NIN";
	}
}
void print() {
	for (int i = 0; i <= 9; i++) {
		while (cnt[i]) {
			cout << out(i)<<" ";
			cnt[i]--;
		}
	}
	cout << '\n';
}
void reset() {
	memset(cnt, 0, sizeof(cnt));
}
int main() {
	string tmp;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >>tmp >> N;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			conv(tmp);
		}
		cout << "#" << i << '\n';
		print();
		//reset();
	}


	return 0;
}