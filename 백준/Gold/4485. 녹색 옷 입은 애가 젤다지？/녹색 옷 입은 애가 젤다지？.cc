//
// Created by newbi on 2024-02-26.
//
#include <iostream>
#include <queue>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int arr[126][126];
int visited [126][126];
int N;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool out(int x,int y){
    return x <0 || y <0 || x>=N || y >=N;
}

void BFS(int x,int y){
    fill(visited[0],visited[N],1e9);    //최대 값으로 채움

    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = arr[x][y];  //현재 값 대입

    while(q.size()){

        auto cur = q.front(); q.pop();
        x = cur.first;
        y = cur.second;

        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)) continue;

            if(visited[qx][qy]> visited[x][y]+arr[qx][qy]){
                visited[qx][qy] = visited[x][y]+arr[qx][qy];
                q.push({qx,qy});
            }

        }
    }
}

int main(){
    fastIO();
    int num =1;
    while(true){
        cin >> N;
        if(!N) break;   //N이 0이면 break
        For(i,0,N){
            For(j,0,N){
                cin >> arr[i][j];
            }
        }
        BFS(0,0);

        cout << "Problem "<<num<<": "<<visited[N-1][N-1]<<endl;
        num++;
    }


    return 0;
}