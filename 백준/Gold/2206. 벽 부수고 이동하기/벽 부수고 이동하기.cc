//
// Created by newbi on 2024-01-13.
//
#include<iostream>
#include <queue>

using namespace std;

int N,M;
int dx[] ={0,0,-1,1};
int dy[] = {1,-1,0,0};
int arr[1004][1004];    //배열 크기
int visited[1004][1004][2];    //x,y,기회 방문 처리
const int INF = 1e8;


void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    string s;
    for(int i=0;i<N;i++){
        cin >> s;
        for(int j=0;j<M;j++){
            arr[i][j] = s[j] -'0';  //정수로 변환
        }
    }
}

bool out(int x,int y){  //장외 처리
    return x < 0 || x >=N || y < 0 || y >=M;
}

void solve(int x,int y,int cnt){
    queue<pair<int,pair<int,int>>> q;
    q.push({cnt,{x,y}});    //부술 수 있는 기회, 좌표
    visited[x][y][cnt] = 1;

    while(q.size()){
        auto cur = q.front(); q.pop();
        x = cur.second.first;
        y = cur.second.second;
        cnt = cur.first;    //벽을 부술 수 있는 기회

        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];
            if(out(qx,qy)) continue;    //맵을 벗어났다면 SKIP
            if(arr[qx][qy] == 1 && cnt == 1){ //벽이 세워져 있고 부술 수 있는 기회가 있다면
                if(visited[qx][qy][cnt] > visited[x][y][cnt]+1) { //지금보다 가까워 진다면?
                    visited[qx][qy][cnt-1] = visited[x][y][cnt] + 1;
                    q.push({cnt-1, {qx, qy}});
                }
            }
            else if(arr[qx][qy] == 0){  //벽이 없다면
                if(visited[qx][qy][cnt] > visited[x][y][cnt]+1) { //지금보다 가까워 진다면?
                    visited[qx][qy][cnt] = visited[x][y][cnt] + 1;
                    q.push({cnt, {qx, qy}});
                }
            }
        }

    }

}

void print(){
    if(visited[N-1][M-1][0] == INF && visited[N-1][M-1][1] == INF){
        cout << -1 <<'\n';
    }
    else{
        cout << min(visited[N-1][M-1][0],visited[N-1][M-1][1]) <<'\n';
    }
}

int main(){
    fastIO();

    fill(&visited[0][0][0],&visited[0][0][0]+1004*1004*2,INF);
    cin >> N >> M;
    input();

    solve(0,0,1);
    print();

    return 0;
}