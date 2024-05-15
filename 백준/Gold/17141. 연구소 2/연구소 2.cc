//
// Created by newbi on 2024-05-15.
//
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,M, ans = 1e9 , fcnt;

int arr[52][52];
int visited[52][52];
int ipt[2501];
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
vector<pair<int,int>> cord;

bool out(int x,int y){
    return  x < 0 || y <0 || x>= N || y >= N;
}

int BFS(){
    memset(visited,false,sizeof(visited));
    queue<pair<int,int>> q;
    bool found = false;
    int cnt = 0;    //칸 수 방문한 횟수
    int mxDist = 0;
    For(i,0,M){
        auto c = cord[ipt[i]];
        q.push(c);
        visited[c.first][c.second] =true;
        cnt++;
    }
    while(q.size()){

        if(cnt == fcnt){
            found = true;
            break;
        }

        int qSize = q.size();
        mxDist++;
        For(a,0,qSize){
            auto c = q.front(); q.pop();
            int x = c.first;
            int y = c.second;

            For(i,0,4){
                int qx = x + dx[i];
                int qy = y + dy[i];

                if(out(qx,qy)|| arr[qx][qy] == 1|| visited[qx][qy]) continue;

                visited[qx][qy] = true;
                cnt++;

                q.push({qx,qy});
            }
        }

    }

    if(found){
        return mxDist;
    }
    else return -1;
}


void combi(int start,int cnt){
    if(cnt == M){
        /*For(a,0,M){
            cout << ipt[a] <<" ";
        }
        cout << endl;*/
        int dist = BFS();
        if(dist != -1 && dist < ans){
            ans = dist;
        }
        return;
    }
    for(int i=start+1;i<cord.size();i++){
        ipt[cnt] = i;
        combi(i,cnt+1);
    }

}


void input() {
    int wcnt = 0;
    For(i,0,N){
        For(j,0,N){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                cord.push_back({i,j});
            }
            else if(arr[i][j] == 1){
                wcnt++;
            }
        }
    }
    fcnt = N*N - wcnt;  //총 개수 업데이트
}

int main(){
    fastIO();
    cin >> N >> M;
    input();
    combi(-1,0);
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
    return 0;
}