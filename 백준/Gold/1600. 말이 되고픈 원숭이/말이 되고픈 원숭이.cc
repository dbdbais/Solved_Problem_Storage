//
// Created by newbi on 2024-02-28.
//
#include <iostream>
#include <queue>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int K,W,H;
int arr[204][204];
bool visited[204][204][32];

struct Monkey{
    int x,y,k;

    Monkey(int x,int y,int k):x(x),y(y),k(k){
    }

};

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int ans = -1;
int hdx[] = {-2,-1,1,2,2,1,-1,-2};
int hdy[] = {1,2,2,1,-1,-2,-2,-1};

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool out(int x,int y){
    return x < 1 || y < 1 || x > H || y > W;
}

void BFS(int x,int y,int k){
    queue<Monkey> q;
    Monkey m(x,y,k);
    q.push(m);

    visited[x][y][k] = true;    //방문 처리

    int depth = -1;
    bool found = false;

    while(q.size()){

        int qSize = q.size();
        depth++;

        For(a,0,qSize){
            auto cur = q.front(); q.pop();

            if(cur.x == H && cur.y == W){
                found = true;
                ans = depth;
                break;
            }

            if(cur.k >0){
                For(i,0,8){
                    int qx = cur.x + hdx[i];
                    int qy = cur.y + hdy[i];
                    if(out(qx,qy)|| arr[qx][qy] == 1 || visited[qx][qy][cur.k-1]) continue;
                    visited[qx][qy][cur.k-1] = true;
                    q.push(Monkey(qx,qy,cur.k-1));
                }
            }
            For(i,0,4){
                int qx = cur.x + dx[i];
                int qy = cur.y + dy[i];
                if(out(qx,qy)|| arr[qx][qy] == 1 || visited[qx][qy][cur.k]) continue;
                visited[qx][qy][cur.k] = true;
                q.push(Monkey(qx,qy,cur.k));
            }
        }
        if(found) break;
    }
}

int main(){
    fastIO();
    cin >> K >> W >> H;
    For(i,1,H+1){
        For(j,1,W+1){
            cin >> arr[i][j];
        }
    }
    BFS(1,1,K);

    cout << ans << endl;

    return 0;
}