//
// Created by newbi on 2024-04-26.
//
#include<iostream>
#include<queue>
#include <algorithm>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
using namespace std;

int N,M;

int arr[301][301];
bool visited[301][301];
int around[301][301];

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

bool out(int x,int y){
    return x <0 || y < 0 || x >= N || y >= M;
}

void input(){
    cin >> N >> M;
    For(i,0,N){
        For(j,0,M){
            cin >> arr[i][j];
        }
    }
}

void print(){
    cout << endl;
    For(i,0,N){
        For(j,0,M){
            cout<< arr[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    For(i,0,N){
        For(j,0,M){
            cout<< around[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}
void vprint(){
    For(i,0,N){
        For(j,0,M){
            cout<< visited[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(q.size()){
        auto cur = q.front(); q.pop();
        x = cur.first;
        y = cur.second;

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy) || visited[qx][qy] || arr[qx][qy] == 0) continue;

            visited[qx][qy] = true;
            q.push({qx,qy});
        }
    }
}

int connected(){
    int piece = 0;
    fill(&visited[0][0],&visited[0][0]+301*301,false);
    For(i,0,N){
        For(j,0,M){
            if(arr[i][j] > 0 && visited[i][j] == false){
                BFS(i,j);
                piece++;
            }
        }
    }

    //초기화 한다.
    return piece;

}

void solve(){
    int T = 1;
    while(true){
        For(i,0,N){
            For(j,0,M){
                if(arr[i][j]){  //현재 자리에 값이 있다면
                    int cnt = 0;
                    For(a,0,4){
                        int qx = i + dx[a];
                        int qy = j + dy[a];

                        if(out(qx,qy) || arr[qx][qy] != 0) continue;
                        cnt++;
                    }
                    around[i][j] = cnt; //주위에 있는 값을 더한다.
                }
            }
        }
        For(i,0,N){
            For(j,0,M){
                if(around[i][j]){
                    arr[i][j] = max(arr[i][j]-around[i][j],0);
                    around[i][j] = 0;   //초기화
                }
            }
        }

        //Connected Component
        int comp = connected();


        if(comp >1){
            cout << T << endl;
            break;
        }
        else if(comp == 0){
            cout << 0 << endl;
            break;
        }
        T++;
    }
}

int main(){
    fastIO();
    input();
    solve();

    return 0;
}