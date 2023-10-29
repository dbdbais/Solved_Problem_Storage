//
// Created by newbi on 2023-08-29.
//

#include <iostream>
#include <vector>

using namespace std;
int N, L, R ,sm,cnt;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<vector<int>> vec(50,vector<int>(50,0));
vector<pair<int,int>> cord;

void DFS(int x,int y,vector<vector<bool>> &visited){

    for(int i=0;i<4;i++){
        int qx = x + dx[i];
        int qy = y + dy[i];

        if(qx <0 || qx >=N || qy <0 || qy >= N) continue;   //좌표 에러 핸들링
        if(visited[qx][qy]) continue;   //방문한 노드 핸들링
        if(abs(vec[qx][qy] - vec[x][y]) >= L && abs(vec[qx][qy]- vec[x][y])<=R ){       //L <= (x,y) <= R 안에 있을 시
            visited[qx][qy] = true;
            cord.push_back(make_pair(qx,qy));   //좌표 vector에 push
            sm += vec[qx][qy];  //sm 더함
            DFS(qx,qy,visited); //이 좌표를 대상으로 깊이우선탐색 수행
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;
    for (int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> vec[i][j];
        }
    }
    while(true){
        bool flag = false;
        vector<vector<bool>>visited(N,vector<bool>(N,false));   //visited 배열은 while문이 돌때마다 생성
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visited[i][j]){ //미방문시
                    cord.clear();   //좌표 vector 클리어
                    visited[i][j] = true;   //원점 처리
                    sm = vec[i][j];
                    cord.push_back(make_pair(i,j));
                    DFS(i,j,visited);
                    if(cord.size() == 1) continue;  //연결 컴포넌트 찾지 못했다면
                    else{
                        for(auto c : cord){
                            vec[c.first][c.second] = sm / cord.size();  //평균을 구해 vector에 대입
                            flag = true;    //인구이동이 일어났음을 표시
                        }
                    }
                }
            }
        }
        if(!flag){
            cout <<cnt <<'\n';
            break;
        }
        cnt++;
    }

    return 0;
}