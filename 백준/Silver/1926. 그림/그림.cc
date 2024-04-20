//
// Created by newbi on 2024-04-20.
//
#include <iostream>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M,mx,totCnt;
bool visited[502][502];
int arr[502][502];

const int dx[]= {0,0,-1,1};
const int dy[] = {-1,1,0,0};

bool out(int x,int y){
    return x < 0 || y < 0 || x >= N || y >= M;
}

void BFS(int x,int y){
    queue<pair<int,int>> q;
    visited[x][y] = true;
    q.push({x,y});
    int cnt =1;
    while(q.size()){
        auto cur = q.front(); q.pop();
        x = cur.first;
        y = cur.second;

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy) || visited[qx][qy] || arr[qx][qy] == 0) continue;
            cnt++;
            visited[qx][qy] = true;
            q.push({qx,qy});
        }
    }
    if(mx < cnt) mx = cnt;
}

void solve(){
    For(i,0,N){
        For(j,0,M){
            if(arr[i][j] == 1 && !visited[i][j]){
                BFS(i,j);
                totCnt++;
            }
        }
    }
}

void input(){
    For(i,0,N){
        For(j,0,M){
            cin >> arr[i][j];
        }
    }
}

int main(){
    fastIO();
    cin >> N >> M;
    input();

    solve();
    cout << totCnt << endl;
    cout << mx << endl;
    return 0;
}