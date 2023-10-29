//
// Created by newbi on 2023-08-29.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int R, C;
const int INF = 9999;   //무한대
vector<vector<int>> fire(1004,vector<int>(1004,INF));   //불이 퍼저나가는 벡터
vector<vector<int>> jihoon(1004,vector<int>(1004,0));   //지훈이가 도망가는 벡터
vector<vector<char>> vec(1004,vector<char>(1004,' '));  //입력받는 벡터
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int ans = INF;  //정답이 저장될 변수

void fBFS(int x,int y){ //fire BFS
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while (!q.empty()){
        auto cord =q.front();
        q.pop();
        x = cord.first;
        y = cord.second;
        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(qx <0 || qx >= R || qy <0 || qy >= C) continue;  //허용 메모리 벗어날 경우
            if(vec[qx][qy] == '#') continue;    //벽일 경우
            if(fire[x][y]+1 < fire[qx][qy]) {   //불이 여러개 났을 경우 원래 값보다 작다면 바꿔준다.
                fire[qx][qy] = fire[x][y] + 1;    //퍼져나간다.
                q.push(make_pair(qx,qy));
            }
        }
    }
/*
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << fire[i][j]<<" ";
        }
        cout<< endl;
    }*/
}
void jBFS(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        auto cord = q.front();
        q.pop();
        x = cord.first;
        y = cord.second;
        if(x == 0 || y ==0 || x == R-1 || y == C-1){ //사각형의 모서리 부분(탈출영역 도달 시)
            ans = min (ans,jihoon[x][y]); //가장 빠른 탈출시간을 update
        }
        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(qx <0 || qx >= R || qy <0 || qy >= C) continue;
            if(vec[qx][qy]=='#') continue;  //벽일 경우
            if(jihoon[qx][qy]) continue;    //0이 아닐 경우

            if(jihoon[x][y]+1<fire[qx][qy]){    //지훈이가 불이 퍼지는 속도보다 빠를 경우
                jihoon[qx][qy] = jihoon[x][y]+1;    //지훈이의 경로 +1
                q.push(make_pair(qx,qy));   //갈 수 있는 경로에 추가
            }
        }
    }
/*
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << jihoon[i][j]<<" ";
        }
        cout<< endl;
    }*/
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(int i=0;i<R;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<C;j++){
            vec[i][j] = temp[j];
        }
    }
  for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
          if(vec[i][j] == 'F'){
              fire[i][j] = 1;
              fBFS(i,j);
          }
      }
  }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(vec[i][j] == 'J'){
                jihoon[i][j] = 1;
                jBFS(i,j);
            }
        }
    }

    /*
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << vec[i][j]<<" ";
        }
        cout << endl;
    }*/
    if(ans == INF){ //지훈이가 탈출하지 못했다면
        cout << "IMPOSSIBLE"<<'\n';
    }
    else{
        cout << ans <<'\n';
    }

    return 0;
}