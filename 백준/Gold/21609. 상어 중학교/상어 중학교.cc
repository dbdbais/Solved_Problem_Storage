//
// Created by newbi on 2024-03-20.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

const int INF = 1e9;
int N, M ,score;
int arr[21][21];
bool visited [21][21];
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

struct BlockGroup{
    int x;
    int y;
    int rainbowCnt;
    int size;

    BlockGroup(int x,int y,int rainbowCnt, int size):x(x),y(y),rainbowCnt(rainbowCnt),size(size){

    }
    bool operator<(const BlockGroup b){
        if(size == b.size){
            if(rainbowCnt == b.rainbowCnt){
                if(x == b.x){
                    return y > b.y;
                }
                else{
                    return x > b.x;
                }
            }
            else{
                return rainbowCnt > b.rainbowCnt;
            }
        }
        else{
            return size > b.size;
        }
    }
};

vector<BlockGroup> blocks;
bool out(int x,int y){
    return x <0 || y < 0 || x >=N || y >=N;
}

pair<int,int> findBFS(int x,int y){
    int cur = arr[x][y];    //현재 상태 기억
    queue<pair<int,int>>q ;
    q.push({x,y});
    int size = 1;
    int rainbowCnt =0;
    visited[x][y] = true;

    while(q.size()){
        auto cord = q.front(); q.pop();
        x = cord.first;
        y = cord.second;
        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];
            if(out(qx,qy)||visited[qx][qy]) continue;    //SKIP
            if(arr[qx][qy] == 0){
                visited[qx][qy] = true;
                size++;
                rainbowCnt++;
                q.push({qx,qy});
            }
            else if(arr[qx][qy] == cur){
                visited[qx][qy] = true;
                size++;
                q.push({qx,qy});
            }
            else{
                continue;
            }
        }
    }
    return {rainbowCnt,size};
}

void print(){
    For(i,0,N){
        For(j,0,N){
            cout << visited[i][j]<<" ";
        }
        cout << endl;
    }
    cout <<endl;
}
void arrPrint(){
    For(i,0,N){
        For(j,0,N){
            if(arr[i][j] == INF){
                cout << "I   ";
            }
            else {
                cout << arr[i][j] << "   ";
            }
        }
        cout << endl;
    }
    cout <<endl;
}

void findGroup(){
    vector<pair<int,int>> zeros;
    For(i,0,N){
        For(j,0,N){
            if(arr[i][j] == 0) zeros.push_back({i,j});
        }
    }

    For(i,0,N){
        For(j,0,N){
            if(visited[i][j] || arr[i][j] ==0 || arr[i][j] == -1||arr[i][j] == INF) continue;
            auto ret = findBFS(i,j);
            if(ret.second >1) { //1보다 커야 넣는다.
                blocks.push_back(BlockGroup(i, j, ret.first, ret.second));
            }
            for(auto zcord : zeros){
                visited[zcord.first][zcord.second] = false;
            }
        }
    }
}
void deleteBlock(int x,int y){
    int cur = arr[x][y];
    queue<pair<int,int>> q;
    q.push({x,y});
    arr[x][y] = INF;
    while(q.size()){
        auto cord = q.front(); q.pop();
        x = cord.first;
        y = cord.second;
        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];
            if(out(qx,qy)) continue;
            if(arr[qx][qy] == 0 || arr[qx][qy] == cur){
                arr[qx][qy] = INF;
                q.push({qx,qy});
            }
        }

    }
}
void gravity(){
    For(i,0,N){
        stack<int> stk;

        For(j,0,N){
            if(arr[j][i] == -1){
                int t = j;
                while(stk.size()){
                    arr[--t][i] = stk.top();
                    stk.pop();
                }
            }
            else if (arr[j][i] != INF) {
                stk.push(arr[j][i]);
                arr[j][i] = INF;
            }
        }
        int a = N-1;
        while(stk.size()){
            arr[a--][i] = stk.top();
            stk.pop();
        }
    }
}

void rotateDeclock(){
    int temp[21][21];
    For(i,0,N){
        For(j,0,N){
            temp[i][j] = arr[j][N-1-i];
        }
    }
    copy(&temp[0][0],&temp[0][0]+21*21,&arr[0][0]);

}

void solve(){
    while(true){
        findGroup();
        if(blocks.empty()) break;   //더이상 블락이 없을 때
        sort(blocks.begin(),blocks.end());
        BlockGroup best = blocks.at(0);
        int sz =  best.size;
        deleteBlock(best.x,best.y);
        score += (sz * sz);
        blocks.clear(); //비우고
        memset(visited,false,sizeof(visited));  //방문배열 초기화
        gravity();
        rotateDeclock();
        gravity();


    }

}

void input(){
    For(i,0,N){
        For(j,0,N){
            cin >> arr[i][j];
        }
    }
}

int main(){
    fastIO();
    cin >> N >> M;
    input();
    solve();
    cout << score << endl;
    return 0;
}