#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;

struct Edge {
	int from;
	int to;
	ll weight;

	Edge(int from, int to, ll weight) :from(from), to(to), weight(weight) {}

	bool operator < (Edge e) {
		return weight < e.weight;
	}
};

ll V, E, A, B, C;

vector<Edge> edgeList;

int parents[10001];

void makeSet() {
	For(i, 1, V + 1) {
		parents[i] = i;
	}
}

int find(int a) {
	
	if (parents[a] == a) return a;

	return parents[a] = find(parents[a]);

}



bool uni(int a,int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot) return false;
	
	parents[bRoot] = aRoot;
	return true;

}


int main() {
	fastIO();
	cin >> V >> E;
	For(i, 0, E) {
		cin >> A >> B >> C;
		edgeList.push_back(Edge(A, B, C));
	}


	makeSet();
	sort(edgeList.begin(), edgeList.end());

	int cnt = 0;
	ll sm = 0;

	for (Edge e : edgeList) {
		if (!uni(e.from, e.to)) continue;
		sm += e.weight;
		cnt++;
		if (cnt == V-1) break;
	}
	cout << sm << endl;



	return 0;
}