//
// Created by newbi on 2024-03-13.
//
#include <iostream>
#include <queue>
#include <cmath>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int N,Q,L,ans;
queue<int> q;
int arr[65][65];
bool visited[65][65];
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

int fn;
bool out(int x,int y){
    return x <0 || y <0 || x >= fn || y >= fn;
}


void partition(int x,int y,int offset){
    if(offset == L){
        int temp[offset][offset];
        for(int i=0;i<offset;i++){
            for(int j=0;j<offset;j++){
                temp[i][j] = arr[x+offset-1-j][y+i];
            }
        }
        for(int i=0;i<offset;i++){
            for(int j=0;j<offset;j++){
                arr[x+i][y+j] = temp[i][j];
            }
        }
        return;
    }
    int half = offset/2 ;
    partition(x,y,half);
    partition(x+half,y,half);
    partition(x,y+half,half);
    partition(x+half,y+half,half);
}

void melt(){
    queue<pair<int,int>> area;
    For(i,0,fn){
        For(j,0,fn){
            if(arr[i][j] == 0) continue;    //얼음이 아닌 곳이라면 SKIP
            int cnt =0;
            For(a,0,4){
                int qx = i + dx[a];
                int qy = j + dy[a];
                if(out(qx,qy)||arr[qx][qy] == 0) continue;
                cnt++;
            }
            if(cnt<3) area.push({i,j}); //녹을 곳 집어넣는다.
        }
    }
    while(area.size()){
        auto cord = area.front(); area.pop();
        arr[cord.first][cord.second]--; //녹은 곳 1감소
    }
}
void BFS(int x,int y){
    queue<pair<int,int>> tq;
    tq.push({x,y});
    visited[x][y] = true;
    int eleCnt =1;

    while(tq.size()){
        auto cord = tq.front(); tq.pop();
        For(i,0,4){
            int qx = cord.first + dx[i];
            int qy = cord.second + dy[i];
            if(out(qx,qy)||arr[qx][qy] == 0||visited[qx][qy]) continue;
            visited[qx][qy] = true;
            eleCnt++;
            tq.push({qx,qy});
        }
    }
    if(ans < eleCnt) ans =eleCnt;
}

void findBig(){
    For(i,0,fn) {
        For(j,0,fn){
            if(visited[i][j]||arr[i][j] == 0) continue;
            BFS(i,j);
        }
    }
}

int count(){
    int sm =0;
    For(i,0,fn) {
        For(j,0,fn){
            sm += arr[i][j];    //다 더한다.
        }
    }
    return sm;
}


void input(){
    For(i,0,fn){
        For(j,0,fn){
            cin >> arr[i][j];
        }
    }
}
void print(){
    For(i,0,fn){
        For(j,0,fn){
            cout << arr[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}

int tmp;

int main(){
    fastIO();
    cin >> N >> Q;
    fn = pow(2,N);
    input();
    For(i,0,Q){
        cin >> tmp;
        q.push(tmp);
    }
    while(q.size()){
        auto cur = q.front(); q.pop();
        L = pow(2,cur);
        partition(0,0,fn);
        melt(); //녹이고
    }
    cout << count() <<endl;
    findBig();
    cout << ans <<endl;

    return 0;
}