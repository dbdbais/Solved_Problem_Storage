//
// Created by newbi on 2024-03-14.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int R, C, M,score;	// 격자판의 크기, 상어의 수 M이 주어진다.

int arr[102][102];
bool life[10001];
const int dx[] = { -1,1,0,0 };	//위 아래 오른쪽 왼쪽
const int dy[] = { 0,0,1,-1 };


struct Shark {
    int x;
    int y;
    int speed;
    int dir;
    int size;

    Shark(int x,int y, int speed,int dir, int size):x(x),y(y),speed(speed),dir(dir),size(size){}
};

vector<Shark> vec;
bool out(int x, int y) {
    return x < 1 || y < 1 || x > R || y > C;
}

int backward(int d) {
    if (d == 0) {
        return 1;
    }
    else if (d == 1) {
        return 0;
    }
    else if (d == 2) {
        return 3;
    }
    else {
        return 2;
    }
}
void print() {
    For(i,1,R+1){
        For(j,1,C+1){
            cout << arr[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}

void sharkMove() {
    for (Shark &s : vec) {
        if(!life[s.size]) continue; //죽었다면 SKIP
        int curDir = s.dir;	//현재 방향
        int time;
        if(curDir <=1){     //수직이라면
            time = s.speed % (2*(R-1));	//2번 왔다갔다 하는 시간을 열만큼 줄인다.
        }
        else{       //수평이라면
            time = s.speed % (2*(C-1));	//행만큼 줄인다.
        }

        int curX = s.x;
        int curY = s.y;	//현재 좌표

        For(i, 0, time) {
            int qx = curX + dx[curDir];
            int qy = curY + dy[curDir];

            if (out(qx, qy)) {
                curDir = backward(curDir);	//방향 바꾼다.
                qx = curX + dx[curDir];
                qy = curY + dy[curDir];	//거꾸로 이동
            }
            curX = qx;
            curY = qy;	//전부 업뎃
        }

       if(arr[curX][curY] == 0){
           arr[curX][curY] = s.size;   //현재 위치 업데이트
           s.x = curX;
           s.y = curY;
           s.dir = curDir;	//속성 값 실제 업데이트
       }
       else if(arr[curX][curY] > s.size) {
            life[s.size] = false;   //내 물고기 죽음
        }
       else if(arr[curX][curY] < s.size){
           life[arr[curX][curY]] = false;   //상대 물고기 죽임
           arr[curX][curY] = s.size;   //현재 위치 업데이트
           s.x = curX;
           s.y = curY;
           s.dir = curDir;	//속성 값 실제 업데이트
       }
    }
}
void fishShark(int col){
    For(i,1,R+1){
        if(arr[i][col] > 0){
            score += arr[i][col];   //더한다.
            life[arr[i][col]] = false;
            arr[i][col] = 0;
            break;
        }
    }
}


void solve() {
    fishShark(1);
    For(i,2, C + 1) {	//낚시왕이 오른쪽으로 이동한다.
//        cout << i << endl;
//        cout << "score : "<<score <<endl;
        memset(arr, 0, sizeof(arr));    //초기화
        sharkMove();    //상어가 움직이고
        fishShark(i);
        //print();

    }
}


int main() {
    fastIO();

    cin >> R >> C >> M;

    int r, c, s, d, z;

    For(i, 0, M) {
        cin >> r >> c >> s >> d >> z;
        arr[r][c] = z;
        life[z] = true; //생명을 준다.
        vec.push_back(Shark(r, c, s, d-1, z));	//상어 전부 넣는다.
    }
    solve();

    cout << score <<endl;

    return 0;
}