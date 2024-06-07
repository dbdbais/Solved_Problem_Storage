//
// Created by newbi on 2024-06-07.
//
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int W,H,startX,startY,dCnt,ans = 1e9,mxKey;
int visited[22][22][1024];
char arr[22][22];

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

struct robot{
    int x;
    int y;
    int hasKey;
    int distance;
};

map<pair<int,int>,int> dMap;
bool out(int x,int y){
    return x < 1 || y < 1 || x > H || y > W;
}

void print(int depth){
    cout << "D : "<< depth << endl;
    For(i,1,H+1){
        For(j,1,W+1){
            cout << visited[i][j][depth]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(){
    queue<robot> q;
    q.push({startX,startY,0,1});
    visited[startX][startY][0] = 1;
    while(q.size()){
        auto cur = q.front(); q.pop();
        int x = cur.x;
        int y = cur.y;
        int hKey = cur.hasKey;
        int curDist = cur.distance;

        if(curDist > ans) continue;
        //ans보다 크다면 nonpromising
        //cout <<"x: "<< x <<" y: "<< y <<endl;
        //print(hKey);
        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];
            int tKey = hKey;
            if(out(qx,qy) || arr[qx][qy] == 'x') continue;
            //if(visited[qx][qy][tKey] != 0 && visited[qx][qy][tKey] < curDist +1) continue;
            //더 작은 곳은 안간다.
            //나갔거나, 벽이라면 컨티뉴
            if(arr[qx][qy] == '*'){
                int no = dMap[{qx,qy}];
                int foundKey = 1 << (no-1);
                //이미 찾은 키라면
                if(!(tKey & foundKey)){
                    tKey |= foundKey;
                    //더한다.
                }
            }
            if(visited[qx][qy][tKey]) continue;
            //if(visited[qx][qy][tKey] != 0 && visited[qx][qy][tKey] < curDist+1) continue;
            //모든 걸 찾았다면
            if(tKey == mxKey){
                //cout << "done" <<endl;
                ans = min(ans,curDist);
                //최소 갱신
            }
            else{
                visited[qx][qy][tKey] = curDist+1;
                q.push({qx,qy,tKey,curDist+1});
            }
        }
    }
}

void input(){
    string s;
    For(i,1,H+1){
        cin >> s;
        For(j,1,W+1){
            arr[i][j] = s[j-1];
            if(arr[i][j] == 'o'){
                startX = i;
                startY = j;
            }
            else if(arr[i][j] == '*'){
                dMap.insert({{i,j},++dCnt});
            }
        }
    }
    mxKey = (1 << dCnt) -1;
}
void output(){
    For(i,1,H+1){
        For(j,1,W+1){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
    cout << startX << startY << endl;
    cout << dCnt << endl;
    for(auto elem :dMap){
        cout << elem.first.first << elem.first.second << elem.second << endl;
    }
    cout << mxKey << endl;
}
void reset(){
    ans = 1e9;
    dCnt = 0;
    dMap.clear();
    memset(visited,0,sizeof(visited));
}

int main(){
    fastIO();
    while(true){
        cin >> W >> H;
        if(W == 0 &&  H == 0) break;
        input();
        solve();
        //output();
        if(ans == 1e9) ans = -1;
        cout << ans << endl;
        reset();
    }

    return 0;
}