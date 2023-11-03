//
// Created by newbi on 2023-11-03.
//
#include<iostream>
#include<cstring>
#include <vector>
using namespace std;
vector<int> ans;
int src;
int dy[]={1,-1};
int ladder[101][101];
pair<int,int> dest;


bool out(int x,int y){
    return (x <0 || y <0 || x >= 100 || y >= 100 );
}
void input(){
    for(int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            cin >> ladder[i][j];
            if(ladder[i][j] == 2){
                dest = {i,j};   //목적지 설정
            }
        }
    }

}
void reset(){
    memset(ladder,0,sizeof(ladder));
    ans.clear();
}
void DFS(int x,int y,int dir){  //0 수직, -1 왼쪽, 1 오른쪽
    if(x == dest.first && y == dest.second){    //원하는 dest의 도착한다면,
        ans.push_back(src);
        return;
    }
    if(dir == 0) {  //방향이 미설정 일때,
        for (int i = 0; i < 2; i++) {       //옆에 있는 지 확인
            int qy = y + dy[i]; //옆에 진로
            if (out(x, qy)) continue;     //나가면 SKIP
            if (ladder[x][qy]) {
                dir = dy[i];
                break;
            }
        }
    }

    if(dir ==0){
        if(!out(x+1,y)){
            DFS(x+1,y,dir);
        }

    }
    else if(dir == 1){
        if(out(x,y+1) || !ladder[x][y+1]){    //오른쪽 가려는 곳이 비어있거나 범위를 벗어났다면
            dir = 0;
            if(!out(x+1,y)){
                DFS(x+1,y,dir);
            }
        }
        else{   //우측방향으로 계속 파고든다.
            DFS(x,y+1,dir);
        }

    }
    else if(dir == -1){
        if(out(x,y-1) || !ladder[x][y-1]){    //왼쪽 가려는 곳이 비어있거나 범위를 벗어났다면
            dir = 0;
            if(!out(x+1,y)){
                DFS(x+1,y,dir);
            }
        }
        else{   //좌측방향으로 계속 파고든다.
            DFS(x,y-1,dir);
        }

    }

    return;
}

void solve(){
    for(int i=0;i<100;i++){
        if(ladder[0][i] ==1){
            src = i;
            DFS(0,i,0);
        }
    }

}


int main(){
    int n;
    for(int i=1;i<=10;i++){
        cin >> n;
        input();
        solve();
        cout << "#"<<i<<" "<< ans[0] <<'\n';
        reset();
    }

    return 0;
}