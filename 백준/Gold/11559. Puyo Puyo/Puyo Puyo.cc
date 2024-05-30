//
// Created by newbi on 2024-05-30.
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

char arr[12][6];
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
bool visited[12][6];

queue<pair<int,int>> explode;

bool out(int x,int y){
    return x <0 || y <0 || x >= 12 || y >=6;
}

void output(){
    For(i,0,12){
        For(j,0,6){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
}

bool check(int x,int y){
    queue<pair<int,int>> q;
    vector<pair<int,int>> way;
    int val = arr[x][y];
    //가격 대비
    visited[x][y] = true;
    way.push_back({x,y});
    int cnt = 1;
    q.push({x,y});
    while(q.size()){
        auto cur = q.front();
        q.pop();
        int cx = cur.first;
        int cy = cur.second;
        For(i,0,4){
            int qx = cx + dx[i];
            int qy = cy + dy[i];

            if(out(qx,qy)|| arr[qx][qy] != val || visited[qx][qy]) continue;
            cnt++;
            visited[qx][qy] = true;
            q.push({qx,qy});
            way.push_back({qx,qy});
        }
    }
    if(cnt >= 4){
        for(auto w : way){
            explode.push(w);
        }
        return true;
    }
    return false;
}

void popPuyo(){
    memset(visited,false,sizeof(visited));

    while(explode.size()){
        auto b = explode.front();
        arr[b.first][b.second] = '.';
        explode.pop();
    }
}

void fall(){
    stack<char> stk;
    For(i,0,6){
        For(j,0,12){
            if(arr[j][i] != '.'){
                stk.push(arr[j][i]);
                arr[j][i] = '.';
            }
        }
        for(int j = 11;j>=0;j--){
            if(stk.empty()) break;
            arr[j][i] = stk.top();
            stk.pop();
        }
    }
}

int solve(){
    bool isGo = true;
    int ans = -1;
    while(isGo){
        ans++;
        isGo = false;
        For(i,0,12){
            For(j,0,6){
                if(arr[i][j] == '.') continue;
                if(!visited[i][j]){
                    if(check(i,j)){
                        isGo = true;
                    }
                }
            }
        }
        popPuyo();
        fall();
        //output();
    }
    return ans;
}


void input(){
    string s;
    For(i,0,12){
        cin >> s;
        For(j,0,6){
            arr[i][j] = s[j];
        }
    }
}


int main(){
    fastIO();
    input();
    cout << solve() << endl;
    return 0;
}