//
// Created by newbi on 2023-11-02.
//
#include <iostream>
#include <cstring>
using namespace std;

int maze[16][16];
int visited[16][16];
int N,suc;
int dx[]= {0,0,-1,1};
int dy[]= {-1,1,0,0};
pair<int,int> src, dest;
void input(){
    string s;
    for(int i=0;i<16;i++){
        cin >> s;
        for(int j=0;j<16;j++){
            maze[i][j] = s[j]-'0';
            if(maze[i][j] == 2){
                src = {i,j};
            }
            else if(maze[i][j]==3){
                dest = {i,j};
            }
        }
    }
}
bool out(int x,int y){
    return (x <0 || x >= 16 || y <0 || y >= 16);
}
void print(){
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            cout <<visited[i][j]<<" ";
        }
        cout <<endl;
    }
}
void DFS(int x, int y){
    if(x == dest.first && y == dest.second){
        suc = 1;
        return;
    }
    for(int i=0;i<4;i++){
        int qx = x + dx[i];
        int qy = y + dy[i];
        if(out(qx,qy)) continue;    //나갔다면
        if(maze[qx][qy] == 1 || visited[qx][qy]) continue;  //벽이거나 이미 방문한 곳이라면
        visited[qx][qy] = true; //방문처리 후 다음 DFS
        DFS(qx,qy);
        visited[qx][qy] = false; //원복
    }
    return;
}
void reset(){
    suc =0;
    memset(visited,false,sizeof(visited));
    memset(maze,0,sizeof(maze));
}

int main(){
    for(int i=1;i<=10;i++){
        cin >> N;
        input();
        visited[src.first][src.second] = true;  //출발지 방문 표시
        DFS(src.first,src.second);
        cout <<"#"<<i<<" "<< suc <<'\n';
        //print();
        reset();
    }


    return 0;
}