//
// Created by newbi on 2024-06-17.
//
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int N,M,R,C,ans = 1e9;

int arr[1002][1002];
bool visited[1002][1002];

const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

bool out(int x,int y){
    return x < 1 || y < 1 || x >N || y >M ;
}
struct cord{
    int x;
    int y;
    int dist;
};

queue<cord> conv;

void input(){
    int a,b,p,c,d;
    cin >> N >> M >> R >> C;
    For(i,0,R){
        cin >> a >> b >> p;
        arr[a][b] = p;
    }
    For(i,0,C){
        cin >> c >> d;
        conv.push({c,d,0});
        visited[c][d] = true;
        //편의점에 밀어넣는다.
    }
}

void BFS(){

    while(conv.size()) {
        auto c = conv.front(); conv.pop();
        int x,y,dist;
        x = c.x;
        y = c.y;
        dist = c.dist;

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy) || visited[qx][qy] ) continue;

            visited[qx][qy] = true;

            if(arr[qx][qy]){
                //cout << qx << qy << "D : "<< dist<< arr[qx][qy] <<endl;
                int ps = arr[qx][qy] * (dist+1);
                if(ans > ps) ans = ps;
            }
            conv.push({qx,qy,dist+1});
            //다음 탐색을 위해 ㄱㄱ

        }
    }

}

void solve(){
    BFS();
    cout << ans << endl;
}


int main(){
    fastIO();
    input();
    solve();
    return 0;
}