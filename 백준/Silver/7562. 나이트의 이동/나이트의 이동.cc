//
// Created by newbi on 2024-04-23.
//
#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T,L,startX,startY,endX,endY;

int arr[301][301];
const int INF = 1e9;

const int dx[] = {1,-1,-2,-2,2,2,1,-1};
const int dy[] = {-2,-2,-1,1,-1,1,2,2};

bool out(int x,int y){
    return x <0 || y <0 || x >= L || y >=L;
}

void print(){
    For(i,0,L){
        For(j,0,L){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;

}

void solve(){
    queue<pair<int,int>> q;
    arr[startX][startY] = 0;
    q.push({startX,startY});

    while(q.size()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        For(i,0,8){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy) || arr[qx][qy] != INF) continue;
            q.push({qx,qy});
            arr[qx][qy] = arr[x][y] +1;
        }
    }
}

int main(){
    fastIO();
    cin >> T;
    For(t,0,T){
        cin >> L;
        cin >> startX >> startY >> endX >> endY;
        fill(&arr[0][0],&arr[0][0]+301*301,INF);
        solve();
        //print();
        cout << arr[endX][endY] <<endl;
    }

    return 0;
}