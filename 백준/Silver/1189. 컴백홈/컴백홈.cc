//
// Created by newbi on 2023-09-08.
//
#include <iostream>
#include <vector>
using namespace std;

int R,C,K,cnt=0;
vector<vector<char>> route(6,vector<char>(6,' '));
vector<vector<bool>> visited(6,vector<bool>(6,false));
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};


void DFS(int x,int y,int way){
    if(way == K && x== 1 && y == C){    //K번째에 집에 도착했다면 cnt 증가
        cnt++;
        return;
    }
    for(int i=0;i<4;i++){
        int qx= x + dx[i];
        int qy = y + dy[i];

        if(qx <1 || qx > R || qy < 1 || qy >C || visited[qx][qy]||route[qx][qy]=='T') continue; //조건에 걸린다면 SKIP
        visited[qx][qy] = true;     //방문 처리
        DFS(qx,qy,way+1);   //다음으로 넘김
        visited[qx][qy] = false;    //원복
    }
    return;
}

int main(){
    cin >> R >> C >> K;
    string temp;
    for(int i=1;i<=R;i++){
        cin >> temp;
        for(int j=1;j<=C;j++){
            route[i][j]= temp[j-1];
        }
    }

    visited[R][1] =true;    //시작점 방문 처리
    DFS(R,1,1); //좌하단에서 DFS시작

    cout << cnt << '\n';
    return 0;
}