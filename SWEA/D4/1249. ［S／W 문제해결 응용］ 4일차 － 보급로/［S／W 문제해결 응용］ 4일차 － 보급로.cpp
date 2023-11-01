//
// Created by newbi on 2023-11-02.
//
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int T,N;
int arr[101][101];
vector<vector<int>> visited(101,vector<int>(101,1e8));

int dx[]={0,0,-1,1};
int dy[]= {-1,1,0,0};

void input(){
    string s;
    for(int i=0;i<N;i++){
        cin >> s;
        for(int j=0;j<N;j++){
            arr[i][j] = s[j]-'0';
        }
    }
}
bool out(int x,int y){
    return (x < 0 || y <0 || x >=N || y >= N);
}
void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << visited[i][j]<<" ";
        }
        cout<<endl;
    }
}
void reset(){
    memset(arr,0,sizeof(arr));
    fill(visited.begin(),visited.end(),vector<int>(101,1e8));
}
void BFS(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;

    while(q.size()){
        auto cord = q.front(); q.pop();
        x = cord.first;
        y = cord.second;

        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)) continue;    //밖에 나갔다면
            if(visited[qx][qy] > visited[x][y] + arr[qx][qy]){  //현재 visited가 지금 갱신하려는 값보다 크다면
                visited[qx][qy] = visited[x][y] + arr[qx][qy];  //변경
                q.push({qx,qy});
            }
        }

    }
}

int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> N;
        input();
        BFS(0,0);
        //print();
        cout <<"#"<<i<<" "<<visited[N-1][N-1]-1<<'\n';
        reset();
    }

    return 0;
}