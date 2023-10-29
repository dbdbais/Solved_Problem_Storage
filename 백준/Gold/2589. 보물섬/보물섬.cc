//
// Created by newbi on 2023-08-28.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mx = -1;
int N,M;
vector<vector<char>> vec(50,vector<char>(50,' '));

int dx[] = {0,0,-1,1};
int dy[]= {1,-1,0,0};

void BFS(int x,int y) {
    vector<vector<int>> visited(N, vector<int>(M, 0));  //visited 배열은 항상 0으로 초기화
    queue<pair<int, int>> q;    
    q.push(make_pair(x, y));
    visited[x][y] = 1;  //스타팅 포인트를 다시 방문하는 일 없도록 1로 만듦
    while (!q.empty()) {
        auto cord = q.front();
        q.pop();
        x = cord.first;
        y = cord.second;
        for (int i = 0; i < 4; i++) {
            int qx = x + dx[i];
            int qy = y + dy[i];

            if (qx < 0 || qx >= N || qy < 0 || qy >= M) continue;
            if (vec[qx][qy] == 'W') continue;
            if (visited[qx][qy]) continue;
            visited[qx][qy] = visited[x][y] + 1;    //스타팅포인트로 부터의 모든 거리 측정
            q.push(make_pair(qx, qy));
            mx = max(mx, visited[qx][qy]);  //최대 거리값 누적 저장(전역변수)
        }
    }
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }*/
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;


    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            cin >> vec[i][j];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            if(vec[i][j] == 'L')
                BFS(i,j);
    }
    cout << mx-1 << '\n';

    return 0;
}