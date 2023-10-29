//
// Created by newbi on 2023-10-27.
//
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int T,N;
int arr[14][14];
bool visited[14][14];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout <<arr[i][j]<<" ";
        }
        cout <<'\n';
    }
}
bool out(int x,int y){
    return (x < 0 || x >= N || y < 0 || y >= N);
}

void solve(int x,int y){
    int dir = 0;    //달팽이 회전방향
    int idx = 0;
    queue <pair<int,int>> q;
    q.push(make_pair(x,y));

    while(q.size()){
        idx++;
        auto cord = q.front(); q.pop();
        x = cord.first;
        y = cord.second;

        arr[x][y] = idx;
        visited[x][y] = true;

        for(int i=0;i<4;i++){
            int qx = x + dx[(dir+i)%4];
            int qy = y + dy[(dir+i)%4];

            if(out(qx,qy)||visited[qx][qy]) continue;    //나갔다면 다음 dir로 바꾼다

            dir = (dir+i) %4;
            q.push({qx,qy});
            break;
        }

    }
    print();
}
void reset(){
    N = 0;
    memset(arr,0,sizeof(arr));
    memset(visited,false,sizeof(visited));
}


int main(){

    cin >> T;
    int no=1;
    while(T){
        cin >> N;
        cout <<"#"<<no<<'\n';
        solve(0,0);
        no++;
        T--;
        reset();
    }


    return 0;
}