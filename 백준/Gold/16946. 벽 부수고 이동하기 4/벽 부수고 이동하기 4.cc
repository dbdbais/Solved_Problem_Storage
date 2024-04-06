//
// Created by newbi on 2024-04-06.
//
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int arr[1004][1004];
int zeros[1004][1004];
int ans[1004][1004];
int visited[1004][1004];
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

vector<pair<int,int>> cord;

int N,M;
int no = 1;

void output(){
    /*
    For(i,0,N){
        For(j,0,M){
            cout << zeros[i][j];
        }
        cout << endl;
    }
    cout << endl;
    For(i,0,N){
        For(j,0,M){
            cout << visited[i][j];
        }
        cout << endl;
    }
    cout << endl;
     */
    For(i,0,N){
        For(j,0,M){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

bool out(int x,int y){
    return x < 0 || y < 0 || x>= N || y >= M;
}

void BFS(int x,int y,int no){
    queue<pair<int,int>> q;
    vector<pair<int,int>> path;
    q.push({x,y});
    path.push_back({x,y});
    int cnt =1;
    visited[x][y] = no;
    int tx,ty;
    while(q.size()){
        auto cur = q.front(); q.pop();
        tx= cur.first;
        ty = cur.second;
        For(i,0,4){
            int qx = tx + dx[i];
            int qy = ty + dy[i];

            if(out(qx,qy) || visited[qx][qy] == no||arr[qx][qy] == 1) continue;
            cnt++;
            path.push_back({qx,qy});    //거쳐온 경로에 넣는다.
            visited[qx][qy] = no;
            q.push({qx,qy});
        }
    }
    for(auto c : path){ //경로에 0의 개수 업데이트
        zeros[c.first][c.second] = cnt;
    }
}

void zeroCount(){

    For(i,0,N){
        For(j,0,M){
            if(arr[i][j] == 0 && visited[i][j]==0){
                BFS(i,j,no++);   //주변 0의 개수 묶는다.
            }
        }
    }
}


void solve(){
    for(auto c : cord){

        int x = c.first;
        int y = c.second;
        int cnt = 1;
        bool found = false;
        vector<int> group;
        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)||arr[qx][qy] == 1) continue;
            for(auto elem : group){
                if(visited[qx][qy] == elem){
                    found = true;
                    break;
                }
            }
            if(found){
                found = false;
                continue;
            }
            group.push_back(visited[qx][qy]);
            cnt += zeros[qx][qy];
        }
        ans[x][y] = cnt % 10;
    }
}

int main(){
    fastIO();
    cin >> N >> M;
    string s;
    For(i,0,N){
        cin >> s;
        For(j,0,M){
            arr[i][j] = s[j]-'0';
            if(arr[i][j] == 1){
                cord.push_back({i,j});
            }
        }
    }
    zeroCount();
    solve();
    output();

    return 0;
}