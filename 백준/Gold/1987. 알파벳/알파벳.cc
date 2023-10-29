//
// Created by newbi on 2023-09-06.
//
#include <iostream>
#include <vector>
using namespace std;

int R,C;
vector<vector<char>> board (24,vector<char>(24,' ')); //알파벳 저장
vector<int> visited (26,0); //알파벳 26개 방문 여부 확인
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int ans = -9999;    //최종 정답이 저장될 변수

void DFS(int x,int y,int res){
    ans = max(ans,res); //최대값을 계속 갱신

    for(int i=0;i<4;i++){
        int qx = x + dx[i];
        int qy = y + dy[i];

        if(qx<0 || qx >= R || qy < 0 || qy >= C) continue;  //허용 범위 벗어날 시 SKIP

        int nxt =(int)board[qx][qy]-'A';    //다음 문자열 인덱스 A-0 Z-25 변환
        if(!visited[nxt]){  //방문되지 않은 경우라면
            visited[nxt] = 1;   //방문 후
            DFS(qx,qy,res+1);   // 그 루트로 방문했다고 가정하고 DFS로 진행
            visited[nxt] = 0;   //방문 안한 상태로 복원하고 다른 루트 방문
            }
        }
    return;
    }

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    string temp;
    for(int i=0;i<R;i++){
        cin >> temp;
        for(int j=0;j<C;j++)
            board[i][j] = temp[j];
    }
    visited[(int)board[0][0]-'A'] = 1;  //좌상단에서 탐색 시작
    DFS(0,0,1);
    cout << ans <<'\n';

    return 0;
}