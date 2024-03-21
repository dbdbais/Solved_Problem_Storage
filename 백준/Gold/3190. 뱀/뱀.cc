//
// Created by newbi on 2024-03-21.
//
#include <iostream>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,K,L;

int dx[] ={0,1,0,-1};     //우 하 좌 상
int dy[] ={1,0,-1,0};

int darr[101][101];
bool visited[101][101];
bool apple[101][101];
queue<pair<int,char>> snakeMove;

bool out(int x,int y){
    return x <1 || y < 1 || x > N || y > N;
}

void print(){
    For(i,1,N+1){
        For(j,1,N+1){
            cout  << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl;
}

void solve(){
    int startX,startY;
    darr[1][1] = 0;
    visited[1][1] = true;
    startX = 1;
    startY = 1;
    int time = 0;
    queue<pair<int,int>> q;
    q.push({1,1});

    while(q.size()){
        time++;
        auto cord = q.front(); q.pop();
        int x = cord.first;
        int y = cord.second;
        int curDir = darr[x][y];    //현재 방향

        int qx = x + dx[curDir];
        int qy = y + dy[curDir];
       // cout << qx << qy <<endl;
        if(out(qx,qy)||visited[qx][qy]) break;  //나가거나 본인 몸과 충돌한다면

        visited[qx][qy] = true; //방문 처리
        if(!snakeMove.empty() && snakeMove.front().first == time){//현재 시간이 이동할 시간이라면
            if(snakeMove.front().second == 'D'){    //우회전이라면
                curDir = (curDir+1) %4;
            }
            else{
                curDir-=1;
                if(curDir <0) curDir = 3;
            }
            snakeMove.pop();
        }
        darr[qx][qy] = curDir;  //이동방향 넣는다.

        if(!apple[qx][qy]){  //사과가 없다면
            visited[startX][startY] = false;
            int startDir = darr[startX][startY];

            startX += dx[startDir];
            startY += dy[startDir]; //갱신
        }
        else{
            apple[qx][qy] = false;
        }
        q.push({qx,qy});
        //print();
    }

    cout << time <<endl;

}

int main(){
    fastIO();
    int a,b;
    cin >> N >> K;
    For(i,0,K){
        cin >> a >> b;
        apple[a][b] = true;
    }
    cin >> L;
    int t;
    char c;
    For(i,0,L){
        cin >> t >> c;
        snakeMove.push({t,c});
    }
    solve();

    return 0;
}