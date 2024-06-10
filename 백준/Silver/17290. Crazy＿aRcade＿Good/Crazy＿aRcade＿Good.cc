//
// Created by newbi on 2024-06-10.
//
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

vector<pair<int,int>> bomb;
int sx,sy;

bool bArr[11][11];
bool visited[11][11];

const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

void output(){
    For(i,1,11){
        For(j,1,11){
            cout << bArr[i][j] <<" ";
        }
        cout << endl;
    }
}
bool out(int x,int y){
    return x < 1 || y < 1 || x >10 || y > 10;
}

void explode(int x,int y){
    For(i,1,11){
        bArr[x][i] = true;
        bArr[i][y] = true;
    }
}

int BFS(){
    queue<pair<int,int>> q;
    if(!bArr[sx][sy]) return 0;

    q.push({sx,sy});
    visited[sx][sy] = true;

    int cnt = 0;

    while(q.size()){
        cnt++;
        int qSize = q.size();
        bool found = false;
        For(a,0,qSize){
            auto cur = q.front(); q.pop();
            int x = cur.first;
            int y = cur.second;

            For(i,0,4){
                int qx = x + dx[i];
                int qy = y + dy[i];
                //나갔거나 이미 방문했다면
                if(out(qx,qy)||visited[qx][qy]) continue;

                if(!bArr[qx][qy]){
                    found = true;
                    break;
                }
                else{
                    q.push({qx,qy});
                }
            }
            if(found) break;
        }
        if(found) break;
    }
    return cnt;
}

void input(){
    string s;
    For(i,1,11){
        cin >> s;
        For(j,1,11){
            if(s[j-1] == 'o') bomb.push_back({i,j});
        }
    }
}


void solve(){
    for(auto elem : bomb){
        explode(elem.first,elem.second);
    }
    cout << BFS() << endl;
    //output();
}

int main(){
    fastIO();
    cin >> sx >> sy;
    input();
    solve();

    return 0;
}