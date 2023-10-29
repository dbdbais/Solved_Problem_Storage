//
// Created by newbi on 2023-09-08.
//
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> land(11,vector<int>(11,0));
vector<vector<bool>> visited(11,vector<bool>(11,false));
int ans = 99999999;
int N;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

bool check(int x, int y){   //유효성 체크 함수
    bool res = true;
    for(int i=0; i<4;i++){
        int qx = x+ dx[i];
        int qy = y + dy[i];

        if(qx <1 || qx > N || qy <1 || qy > N || visited[qx][qy] || visited[x][y]) res = false;
    }
    return res;
}

void unsetFlower(int x, int y){ //원복 함수
    visited[x][y] = false;
    for(int i=0;i<4;i++){
        int qx = x+ dx[i];
        int qy = y + dy[i];
        visited[qx][qy] = false;
    }
}

int flower(int x,int y){    //꽃을 심는 함수
    int res =0;
    visited[x][y] = true;
    res += land[x][y];
    for(int i=0;i<4;i++){
        int qx = x+ dx[i];
        int qy = y + dy[i];
        visited[qx][qy] = true;
        res += land[qx][qy];
    }
    return res;
}

void DFS(int cnt, int hap){     //백트래킹 함수 여러 경우의 수를 다 조합해야 하기 때문에 사용
    if(cnt == 3){
        ans = min(hap,ans);
        return;
    }
    for(int i=1;i<=N;i++){
        for(int j=1; j<=N;j++){
            if(check(i,j)){
                DFS(cnt+1, hap+flower(i,j));    //이 꽃을 심는다고 가정 후 진행
                unsetFlower(i,j);   //원복 한 케이스 진행
            }
        }
    }
    return;
}




int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1; j<=N;j++){
            cin >> land[i][j];
        }
    }

    DFS(0,0);
    cout << ans << '\n';

    return 0;
}