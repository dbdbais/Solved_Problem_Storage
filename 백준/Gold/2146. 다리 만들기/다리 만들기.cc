//
// Created by newbi on 2024-03-03.
//
#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int N,ans = 1e9;
int arr[101][101];
int visited[101][101];
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};
bool out(int x,int y){
    return x < 0 || y < 0 || x >= N || y >= N;
}
int curColor;
void color(int x,int y,int cnt){
    visited[x][y] = cnt;
    queue<pair<int,int>> q;
    q.push({x,y});

    while(q.size()){
        auto cord = q.front(); q.pop();
        x = cord.first;
        y = cord.second;

        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];
            if(out(qx,qy) || visited[qx][qy] ||arr[qx][qy] == 0 ) continue;

            visited[qx][qy] = cnt;
            q.push({qx,qy});

        }
    }
}

void setColor(){
    int cnt =1;
    For(i,0,N){
        For(j,0,N){
            if(arr[i][j] != 0 && visited[i][j] == 0){
                color(i,j,cnt++);
            }
        }
    }
}
bool searchVisited[101][101];

void BFS(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    bool found = false;
    searchVisited[x][y] = true;
    int cnt =0;
    while(q.size() && !found){
        int qSize = q.size();
        cnt++;
        if(cnt-1 > ans) break;
        For(a,0,qSize){
            auto cur = q.front(); q.pop();
            x = cur.first;
            y = cur.second;

            For(i,0,4){
                int qx = x + dx[i];
                int qy = y + dy[i];

                if(out(qx,qy)|| visited[qx][qy] == curColor || searchVisited[qx][qy]) continue;

                if(visited[qx][qy] != 0 && visited[qx][qy] != curColor){
                    found = true;
                    break;
                }
                searchVisited[qx][qy] = true;
                q.push({qx,qy});

            }
            if(found) break;
        }
        if(found) break;
    }
    if(ans > cnt-1) ans = cnt-1;

    memset(searchVisited,false,sizeof(searchVisited));
}

void solve(){
    For(i,0,N){
        For(j,0,N){
            if(visited[i][j] == 0) continue;    //물이면 SKIP
            bool isOk = false;
            curColor = visited[i][j];   //현재 섬 컬러
            For(k,0,4){
                int qi = i + dx[k];
                int qj = j + dy[k];
                if(out(qi,qj)||visited[qi][qj] != 0) continue;
                isOk = true;
                break;
            }
            if(isOk){
                BFS(i,j);
            }
        }
    }

}




void print(){
    For(i,0,N){
        For(j,0,N){
            cout << visited[i][j] <<" ";
        }
        cout << endl;
    }
    cout <<endl;
}

int main(){
    fastIO();
    cin >> N;

    For(i,0,N){
        For(j,0,N){
            cin >> arr[i][j];
        }
    }
    setColor();
    //print();
    solve();

    cout << ans <<endl;

    return 0;
}