//
// Created by newbi on 2024-03-26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;


int startX, startY;
const int INF = 32767 * 102;

int getDistance(pair<int,int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int arr[102][102];
vector<pair<int, int>> cord;
using namespace std;
int T,N;

void print() {
	For(i, 0, N + 2) {
		For(j, 0, N + 2) {
			if (arr[i][j] == INF) {
				cout << "I " << " ";
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void floyd() {
	For(k, 0, N + 2) {	//경유지
		For(i, 0, N + 2) {	//시작지
			if (k == i) continue;
			For(j, 0, N+2) {	//최종
				if (i == j || k == j) continue;
				
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}

	}

}

int main() {
	fastIO();

	cin >> T;
	For(t, 1, T + 1) {
		fill(&arr[0][0], &arr[0][0]+102*102, INF);	//무한대로 채우고
		cord.clear();
		int beer = 20;
		cin >> N;
		int x, y;
		For(i, 0, N+2) {
			cin >> x >> y;
			cord.push_back({ x,y });
		}
		For(i, 0, N + 2) {
			For(j, 0, N + 2) {
				if (i == j) arr[i][j] = 0;
				else {
					 int val = getDistance(cord[i], cord[j]);
					 int ndBeer;
					 if (val % 50 == 0) {	//나누어떨어지면
						 ndBeer = val / 50;
					 }
					 else {
						 ndBeer = val / 50 + 1;
					 }

					 if (ndBeer <= beer) arr[i][j] = val;
				}
			}
		}
		floyd();
		if (arr[0][N + 1] == INF) {
			cout << "sad" << endl;
		}
		else {
			cout << "happy" << endl;
		}
	
	}







	return 0;
}