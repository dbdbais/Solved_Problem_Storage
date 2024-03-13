#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int arr[500][500];
int N;

const int dx[] = {0,1,0,-1};		//좌 하 우 상
const int dy[] = {-1,0,1,0};

const int sandX[4][9] = { {-1,1,1,-1,0,2,-2,1,-1},{1,1,0,0,2,0,0,-1,-1},
{1,-1,1,-1,0,2,-2,-1,1}
,{-1,-1,0,0,-2,0,0,1,1}
};		//dir 기준으로 모래가 흩날렸을 때 전부 넣어둔다.

const int sandY[4][9] = { {-1,-1,0,0,-2,0,0,1,1} ,{-1,1,1,-1,0,-2,2,-1,1},
{1,1,0,0,2,0,0,-1,-1},
{-1, 1, 1, -1, 0, -2, 2, -1, 1}
};

int score;

bool out(int x, int y) {
	return  x < 0 || y < 0 || x >= N || y >= N;
}
void print() {
	cout << endl;
	For(i, 0, N) {
		For(j, 0, N) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void tornado() {

	int curX = N / 2;
	int curY = N / 2;
	int fcnt = 1;	//점차 증가하는 cnt
	int dir = 0;	//방향
	int qx, qy;
	while (!out(curX,curY)) {
		
		For(i, 0, fcnt) {	//fcnt 만큼 전진
			qx = curX + dx[dir];
			qy = curY + dy[dir];	//다음 방향으로 ㄱㄱ

			if (arr[qx][qy] > 0) {	//모래가 있었다면

				int totSand = arr[qx][qy];	//현재 모래
				int partSum = 0;
				For(k, 0, 9) {	//퍼질 곳
					int kx = qx + sandX[dir][k];
					int ky = qy + sandY[dir][k];	//퍼질 구간

					int partSand = 0;
					if (k <= 1) {	//10인지점
						partSand = int(totSand * 0.1);
					}
					else if (k>1 && k <= 3) {	//7인지점
						partSand = int(totSand * 0.07);
					}
					else if (k == 4) {	//5인지점
						partSand = int(totSand * 0.05);
					}
					else if (k > 4 && k <= 6) {	//2인 지점
						partSand = int(totSand * 0.02);
					}
					else {		//1인 지점
						partSand = int(totSand * 0.01);
					}
					partSum += partSand;

					if (partSand == 0) break;	//0이면 의미없으니 여기서 끝

					

					if (out(kx, ky)) {	//장외로 나갔다면
						score += partSand;
					}
					else {	//아니라면 그쪽 모래로 옮겨준다.
						arr[kx][ky] += partSand;	
					}
				}

				totSand -= partSum;	//부분 함수에서 뺸다.

				int cx = qx + dx[dir];
				int cy = qy + dy[dir];	//모래가 최종적으로 이동할 곳


				if (out(cx, cy)) {
					score += totSand;	//점수 더하고
				}
				else {
					arr[cx][cy] += totSand;	// 모래 옮겨주고
				}
				arr[qx][qy] = 0;	// 이전의 모래 초기화
			}
			curX = qx;	//현재 위치 업데이트
			curY = qy;
			//print();
		}
		dir = (dir + 1) % 4;	//방향 바꾼다.

		if (dir == 0 || dir == 2) {
			fcnt++;	//카운트를 증가
		}
	}

}


void input() {
	For(i, 0, N) {
		For(j, 0, N) {
			cin >> arr[i][j];
		}
	}
}

int main() {
	fastIO();
	cin >> N;
	input();
	tornado();	//가운데서 시작한다.
	cout << score << endl;
	return 0;
}