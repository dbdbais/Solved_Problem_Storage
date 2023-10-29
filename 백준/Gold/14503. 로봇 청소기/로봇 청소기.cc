//
// Created by newbi on 2023-10-11.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M,cnt,direc;  //0 : 북, 1 : 동, 2 : 남, 3 : 서
vector<vector<int>> vec(52,vector<int>(52,0));
vector<vector<bool>> visited(51,vector<bool>(51,false));
int dx []= {-1,0,1,0};
int dy []= {0,1,0,-1};
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool out(int x,int y){
    if(x<0 || x >= N || y < 0 || y >= M) return true;
    else return false;
}

void BFS(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});

    while(q.size()){
        auto cord = q.front(); q.pop();
        x = cord.first;
        y = cord.second;
        if(visited[x][y] == false) visited[x][y] = true;

        bool found = false;
        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)) continue;
            if(vec[qx][qy] == 1 || visited[qx][qy]) continue;
            found = true;   //청소되지 않은 빈칸 찾음
        }
        if(found){    //하나라도 비었다면
           for(int i=0;i<4;i++) {
               direc -= 1;
               if (direc < 0) direc = 3;
               int qx = x + dx[direc];
               int qy = y + dy[direc];
               if(out(qx,qy)){
                   continue;
               }
               if(vec[qx][qy] == 1 || visited[qx][qy]){
                   continue;
               }
               q.push({qx,qy}); //한칸 전진
               break;
           }
        }
        else{   // 주변에 갈 수 있는 곳이 없을 때 후진
            int qx = x - dx[direc];
            int qy = y - dy[direc];
            if(out(qx,qy) || vec[qx][qy] == 1) break;
            q.push({qx,qy});
        }
    }
}
void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j] == true) cnt++;

        }
    }
    cout << cnt << endl;
}

int main(){
    int x,y;

    fastIO();
    cin >> N >> M;
    cin >> x >> y >> direc;

    for(int i=0; i< N;i++){
        for(int j=0;j<M;j++){
            cin >> vec[i][j];
        }
    }

    BFS(x,y);

    print();

    return 0;
}
