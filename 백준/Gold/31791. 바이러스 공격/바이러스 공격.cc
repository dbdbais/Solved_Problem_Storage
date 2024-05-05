//
// Created by newbi on 2024-05-04.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M,tg,tb,X,B,iCnt;

vector<pair<int,int>> virus;
int arr[1004][1004];
bool infected[1004][1004];
bool visited [1004][1004];

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

bool out(int x,int y){
    return x <1 || y <1 || x >N || y > M;
}


void output(){
    cout << "arr" << endl;
    For(i,1,N+1){
        For(j,1,M+1){
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl <<endl;
    cout << "infec" << endl;
    For(i,1,N+1){
        For(j,1,M+1){
            cout << infected[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "visited" << endl;
    For(i,1,N+1){
        For(j,1,M+1){
            cout << visited[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;


}

void input(){
    string s;
    For(i,1,N+1){
        cin >> s;
        For(j,0,M){
            if(s[j]=='#'){
                arr[i][j+1] = tb;
            }
            else if(s[j] == '*'){
                virus.push_back({i,j+1});
            }
        }
    }
}

void BFS(){
    queue<pair<int,int>> q;
    queue<pair<int,pair<int,int>>> qq;
    int time = 0;
    for(auto elem : virus){
        infected[elem.first][elem.second] = true;
        visited[elem.first][elem.second] = true;
        iCnt++;
        q.push(elem);
    }

    while(iCnt != N*M){
        //cout << time << endl;
        if(time == tg) break;
        int qSize = q.size();

        For(i,0,qSize){ //레벨 순회
            auto cur = q.front(); q.pop();
            int x = cur.first;
            int y = cur.second;
            For(a,0,4) {
                int qx = x + dx[a];
                int qy = y + dy[a];

                if (out(qx, qy) || visited[qx][qy]) continue;

                visited[qx][qy] = true; //방문 처리
                if (arr[qx][qy] > 0) {
                    qq.push({time + arr[qx][qy], {qx, qy}});
                } else {
                    iCnt++;
                    infected[qx][qy] = true;
                    q.push({qx, qy});
                }
            }
        }
        while(qq.size()){
            auto cur = qq.front();
            int val = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            if(time >= val){
                qq.pop();
                iCnt++;
                infected[x][y] = true;
                q.push({x,y});
            }
            else{
                break;
            }
        }

        //output();
        time++;
    }
}

void getCord(){
    For(i,1,N+1){
        For(j,1,M+1){
            if(!infected[i][j]){
                cout << i <<" "<< j << endl;
            }
        }
    }


}


int main(){
    fastIO();
    cin >> N >> M >> tg >> tb >> X >> B;    //전파시간, 지연시간, 살포시점, 건물개수
    // * 살포된 곳, # 건물있는 곳, . 빈곳
    input();

    BFS();
    if(iCnt == N*M){
        cout << -1 <<endl;
    }
    else{
        getCord();
    }


}