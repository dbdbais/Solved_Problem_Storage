#include <iostream>
#include <vector>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;



struct Organic {
	int x;
	int y;
	int dir;
	int num;
	bool isIn;	//약품 발라져 있는 곳 접근 했는지 체크
	bool isMet;

	Organic(int x, int y, int num, int dir) :x(x), y(y), dir(dir), num(num) {
		isIn = false;
		isMet = false;
	}
};
int T, N, M, K;

int dx[] = { -1,1,0,0 };	//상 하 좌 우
int dy[] = { 0,0,-1,1 };

vector<Organic> vec;
bool visited[100][100];		//방문 처리

vector<pair<int, int>> met;	//방문 처리


bool in(int x, int y) {	//약품이 묻은 공간으로 들어간다면
	return x == 0 || x == N - 1 || y == 0 || y == N - 1;
}

void move() {	//미생물 이동
	met.clear();
	fill(visited[0], visited[N], false);	//방문 배열 초기화
	for (Organic &o : vec) {

		o.x = o.x + dx[o.dir];
		o.y = o.y + dy[o.dir];	//미생물 이동하고

		if (in(o.x, o.y)) {	//경계선에 들어왔다면
			o.isIn = true;	//경계 접근 여부 체크
		}

		if (visited[o.x][o.y]) met.push_back({ o.x,o.y });	//미생물이 겹친 부분 밀어 넣는다.
		else visited[o.x][o.y] = true;	//이동 후 방문 처리
	}
}

void check() {	//미생물 방문 및 약품 쪽 도달 했는지 체크

	for (Organic &o : vec) {
		if (!o.isIn) continue;	//약품이 묻어있지 않다면 SKIP
		
		o.num = o.num / 2;	//미생물의 절반이 죽는다.

		if (o.dir == 0) {	//방향 바꿔주고
			o.dir = 1;
		}
		else if (o.dir == 1) {
			o.dir = 0;
		}
		else if (o.dir == 2) {
			o.dir = 3;
		}
		else {
			o.dir = 2;
		}
		o.isIn = false;

	}
	vec.erase(remove_if(vec.begin(), vec.end(),[=](Organic o) {	//미생물이 0이면 벡터에서 지운다.
		return o.num == 0;
	}),vec.end());

	for (auto cord : met) {
		int totalNum = 0;	//합쳐지는 미생물 수
		int mxNum = 0;
		int mxIdx = -1;		//가장 큰 인덱스

		for (int i = 0; i < vec.size(); i++) {	//벡터에서 만난 미생물을 추출해서 더한다
			if (vec[i].x != cord.first || vec[i].y != cord.second) continue;	//현재 만난 친구가 아니라면
			
			totalNum += vec[i].num;	//값 누적
			if (mxNum < vec[i].num) {	//가장 최대의 num을 가진 놈 추출
				mxNum = vec[i].num;
				mxIdx = i;	//그 인덱스 기록
			}
			vec[i].num = 0;	//0으로 만들어준다.

		}
		Organic total(cord.first, cord.second, totalNum, vec[mxIdx].dir);	//최종본 만든다.

		vec.erase(remove_if(vec.begin(), vec.end(), [=](Organic o) {	//미생물이 0이면 벡터에서 지운다.
			return o.num == 0;
		}), vec.end());

		vec.push_back(total);
	}


}

int count() {
	int cnt = 0;
	for (Organic o : vec) {
		cnt += o.num;
	}
	return cnt;
}


void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
void orgPrint() {
	for (Organic elem : vec) {
		cout << "x : " << elem.x << ", y : " << elem.y << " Num : " << elem.num << endl;
	}
	cout << endl;
	cout << endl;
}

void solve() {
	For(i, 0, M) {		//M만큼 돈다
		move();	//이동하고
		check();	//약품 체크 -> 닿았는지 체크
		//orgPrint();
	}

}


int main() {
	fastIO();
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;

		int x, y, num, tdir;
		For(i, 0, K) {
			cin >> x >> y >> num >> tdir;
			Organic tmp(x, y, num, tdir - 1);
			vec.push_back(tmp);	//하나씩 전부 넣는ㅇ다
		}
		//orgPrint();
		solve();
		
		cout << "#" << t << " " << count() << endl;

		vec.clear();
	}


	return 0;
}