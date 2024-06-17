//
// Created by newbi on 2024-06-17.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int N,M;
vector<pair<int,int>> AC;
int arr[2002][2002];
int ans;
bool isOK[2002][2002];
bool visited[2002][2002][4];

const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

//좌 우 상 하

bool out(int x,int y){
    return x < 0 || x >= N || y < 0 ||  y >= M;
}

void input(){
    cin >> N >> M;
    For(i,0,N){
        For(j,0,M){
            cin >> arr[i][j];
            if(arr[i][j] == 9) AC.push_back({i,j});
            //에어컨 집어넣는다.
        }
    }
}

void BFS(int x,int y){
    //memset(visited,false,sizeof(visited));
    queue<pair<int,pair<int,int>>> q;
    if(!isOK[x][y]) {
        ans++;
        isOK[x][y] = true;
    }

    For(d,0,4){
        q.push({d,{x,y}});
        visited[x][y][d] = true;
        //하나씩 추가
    }
    //큐에 집어넣는다.

    while(q.size()){
        auto c = q.front(); q.pop();
        int cx,cy,dir;
        dir = c.first;
        tie(cx,cy) = c.second;

        int qx = cx + dx[dir];
        int qy = cy + dy[dir];

        if(out(qx,qy)||visited[qx][qy][dir]) continue;
        int thing = arr[qx][qy];
        visited[qx][qy][dir] = true;
        if(!isOK[qx][qy]) {
            ans++;
            isOK[qx][qy] = true;
            // T로 만든다.
        }
        if(thing == 1 && dir <= 1){
            continue;
        }
        else if(thing == 2 && dir >= 2){
            continue;
        }
        else if (thing == 3){
            //좌 우 상 하
            if(dir == 0){
                dir = 3;
            }
            else if(dir == 1){
                dir = 2;
            }
            else if(dir == 2){
                dir = 1;
            }
            else{
                dir = 0;
            }
            q.push({dir,{qx,qy}});
        }
        else if(thing == 4){
            //좌 우 상 하
            if(dir == 0){
                dir = 2;
            }
            else if(dir == 1){
                dir = 3;
            }
            else if(dir == 2){
                dir = 0;
            }
            else{
                dir = 1;
            }
            q.push({dir,{qx,qy}});
        }
        else{
            q.push({dir,{qx,qy}});
            // 그대로 넣는다.
        }
    }

}

void solve(){
    for(auto c : AC){
        int x,y;
        tie(x,y) = c;
        BFS(x,y);
    }
    cout << ans << endl;
}

int main(){
    fastIO();
    input();
    solve();
    return 0;
}