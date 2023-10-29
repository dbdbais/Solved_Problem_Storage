//
// Created by newbi on 2023-09-06.
//
#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int N,M,x1,y1,x2,y2,curX,curY;
vector<vector<char>> room(304,vector<char>(304,' '));   //교실 vector
vector<vector<int>> visited(304,vector<int>(304,0));    //방문 vector

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
queue<pair<int,int>> q;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M >> x1 >> y1 >> x2 >> y2;
    string temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        for(int j=0;j<M;j++){
            room[i+1][j+1] = temp[j];
        }
    }
    q.push(make_pair(x1,y1));   //주난이의 좌표 입력
    visited[x1][y1] = 1;    //방문처리
    int level =0;   //레벨별 순회를 위한 레벨 변수
    while(room[x2][y2] != '0'){ //초코바를 훔친 학생의 값이 바뀌었다면 break
        queue<pair<int,int>> temp;  //0이 아닌 값을 만났을 때 담길 큐
        level ++;
        while (!q.empty()) {
            auto cord = q.front();
            q.pop();
            curX = cord.first;
            curY = cord.second;

            for (int i = 0; i < 4; i++) {
                int qx = curX + dx[i];
                int qy = curY + dy[i];

                if (qx < 1 || qx > N || qy < 1 || qy > M) continue;     //경곗값 조건
                if (visited[qx][qy]) continue;      //방문노트 SKIP
                visited[qx][qy] = level;    //레벨 입력
                if(room[qx][qy]!='0'){      //교실에서 0이 아닌 값 만났을 경우
                    room[qx][qy] ='0';  //0으로 변경
                    temp.push(make_pair(qx,qy));    //다음레벨로 올리고 탐색예정
                }
                else{
                    q.push(make_pair(qx,qy));   //0일 경우 계속 탐색
                }
            }
        }
        q = temp;   //다름레벨의 탐색을 위해 temp를 복사
    }
    /*for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout << visited[i][j]<<" ";
        }
        cout<<endl;
    }*/

    cout <<visited[x2][y2] <<'\n';
    return 0;
}