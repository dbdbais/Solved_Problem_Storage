//
// Created by newbi on 2024-04-24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

const int dx[]= {0,0,-1,1};
const int dy[] = {-1,1,0,0};
const int INF = 1e9;
int W,H,T,sx,sy;

bool out(int x,int y){
    return x < 0 || y < 0 || x >= H || y >= W;
}

char arr[1002][1002];
bool sVisited[1002][1002];
int fVisited[1002][1002];
vector<pair<int,int>> fire;

void print(){
    For(i,0,H){
        For(j,0,W){
            if(fVisited[i][j] == INF){
                cout << "I ";
            }
            else{
                cout << fVisited[i][j] <<" ";
            }

        }
        cout << endl;
    }
    cout << endl;

}

void fBFS(){
    queue<pair<int,int>> q;
    fill(&fVisited[0][0],&fVisited[0][0]+1002*1002,INF);
    for(auto elem : fire){
        q.push({elem.first,elem.second});
        fVisited[elem.first][elem.second] = 0;
    }
    fire.clear();
    while(q.size()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        int val = fVisited[x][y];
        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy) || arr[qx][qy] == '#' || fVisited[qx][qy] <= val+1 ) continue;

            fVisited[qx][qy] = val + 1;
            q.push({qx,qy});
        }
    }
}

int sBFS(int x,int y){
    memset(sVisited,false,sizeof(sVisited));
    queue<pair<int,int>> q;
    q.push({x,y});
    sVisited[x][y] = true;
    int cnt = 0;
    bool found = false;
    while(q.size()){

        int qSize = q.size();
        cnt++;
        For(a,0,qSize){
            auto cur = q.front(); q.pop();

            For(i,0,4){
                int qx = cur.first + dx[i];
                int qy = cur.second + dy[i];

                if(out(qx,qy)) {
                    found = true;
                    break;
                }

                if( sVisited[qx][qy] || arr[qx][qy] == '#' || fVisited[qx][qy] <= cnt ) continue;
                sVisited[qx][qy] = true;
                q.push({qx,qy});
            }
            if(found) break;
        }
        if(found) break;

    }
    if(found){
        return cnt;
    }
    else{
        return -1;
    }
}



void solve(){
    fBFS();
    int mn = sBFS(sx,sy);
    if(mn == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << mn << endl;
    }
    }

void input(){
    string s;
    For(i,0,H){
        cin >> s;
        For(j,0,W){
            arr[i][j] = s[j];
            if(arr[i][j] == '@'){
                sx = i;
                sy = j;
            }
            else if(arr[i][j] == '*'){
                fire.push_back({i,j});
            }
        }
    }

}

int main(){
    fastIO();
    cin >> T;
    For(t,1,T+1){
        cin >> W >> H;
        input();
        solve();
    }
    return 0;
}