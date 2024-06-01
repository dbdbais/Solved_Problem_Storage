//
// Created by newbi on 2024-05-31.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int cube[5][5][5];
int nowCube[5][5][5];
int visited[5][5][5];
bool isSel[5];
int ordArr[5];
int perArr[5];
int ans = 1e9;

const int dz[] = {0,0,0,0,1,-1};
const int dx[] = {0,0,-1,1,0,0};
const int dy[] = {-1,1,0,0,0,0};

bool out(int z,int x,int y){
    return  z < 0 || x < 0 || y < 0 || x >=5 || y >= 5 || z >=5;
}

struct cord{
    int z;
    int x;
    int y;
};

void output(){
    cout << "CUBE" << endl;
    For(a,0,5){
        For(i,0,5){
            For(j,0,5){
                cout << nowCube[a][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "VISITED" << endl;
    For(a,0,5){
        For(i,0,5){
            For(j,0,5){
                cout << visited[a][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void input(){
    string ipt;
    For(a,0,5){
        For(i,0,5){
            For(j,0,5){
                cin >> cube[a][i][j];
            }
        }
    }
}

void BFS(){
    memset(visited,0,sizeof(visited));
    queue<cord> q;
    q.push({0,0,0});
    visited[0][0][0] = 1;
    while(q.size()){
        auto c = q.front(); q.pop();

        For(i,0,6){
            int qz = c.z + dz[i];
            int qx = c.x + dx[i];
            int qy = c.y + dy[i];

            if(out(qz,qx,qy) || nowCube[qz][qx][qy] == 0 || visited[qz][qx][qy] != 0) continue;
            //갈 수 없으면 스킵

            visited[qz][qx][qy] = visited[c.z][c.x][c.y] + 1;
            q.push({qz,qx,qy});
        }
    }
}

void rotate(int idx,int rotNum){
    int tmp[5][5];
    int rotTmp[5][5];
    int sIdx = ordArr[idx];
    copy(&cube[sIdx][0][0],&cube[sIdx][0][0]+5*5,&tmp[0][0]);
    copy(&cube[sIdx][0][0],&cube[sIdx][0][0]+5*5,&rotTmp[0][0]);

    For(a,0,rotNum){
        For(i,0,5){
            For(j,0,5){
                rotTmp[i][j] = tmp[4-j][i];
            }
        }
        copy(&rotTmp[0][0],&rotTmp[0][0]+5*5,&tmp[0][0]);
    }

    //대입
    For(i,0,5){
        For(j,0,5){
            nowCube[idx][i][j] = tmp[i][j];
        }
    }
}


void permutation(int idx){
    if(idx == 5){
        For(i,0,5){
           rotate(i,perArr[i]);
        }

        //BFS탐색 들어감
        if(nowCube[0][0][0] && nowCube[4][4][4]){
            BFS();
            //output();
            if(visited[4][4][4] != 0){
                if(ans > visited[4][4][4]){
                    ans = visited[4][4][4];
                }
            }
        }

        return;
    }
    For(i,0,4){
        perArr[idx] = i;
        permutation(idx+1);
    }
}

void orderPerm(int idx){
    if(idx == 5){
        permutation(0);
        return;
    }
    For(i,0,5){
        if(isSel[i]) continue;
        ordArr[idx] = i;
        isSel[i] = true;
        orderPerm(idx+1);
        isSel[i] = false;
    }
}


int main(){
    fastIO();

    input();
    orderPerm(0);
    if(ans == 1e9){
        cout << -1 << endl;
    }
    else{
        cout << ans-1 << endl;
    }

    return 0;
}