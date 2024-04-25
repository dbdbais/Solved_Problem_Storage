//
// Created by newbi on 2024-04-25.
//
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;
char arr[31][31][31];
int visited[31][31][31];
int L, R, C,startX,startY,startK,endX,endY,endK;

const int dx[] = {0,0,-1,1,0,0};
const int dy[] = {-1,1,0,0,0,0};
const int dz[] = {0,0,0,0,1,-1};
bool out(int x,int y,int z){
    return x<0 || y < 0 || z <0 || x >= R || y >= C || z >= L;
}

struct point{
    int x;
    int y;
    int z;
    point(int x,int y,int z):x(x),y(y),z(z){}
};

void print(){
    For(k,0,L){
        For(i,0,R){
            For(j,0,C){
                cout << visited[i][j][k]<<" ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
}

void BFS(){
    queue<point> q;
    memset(visited,0,sizeof(visited));

    q.push(point(startX,startY,startK));
    visited[startX][startY][startK] = 1;
    while(q.size()){
        point cur = q.front();q.pop();
        int x = cur.x;
        int y = cur.y;
        int z = cur.z;
        int val = visited[x][y][z];
        For(i,0,6){
            int qx = x + dx[i];
            int qy = y + dy[i];
            int qz = z + dz[i];

            if(out(qx,qy,qz)||visited[qx][qy][qz] != 0|| arr[qx][qy][qz]=='#') continue;
            visited[qx][qy][qz] = val+1;
            q.push(point(qx,qy,qz));
        }
    }

    //print();

}

void input(){
    For(k,0,L){
        For(i,0,R){
            For(j,0,C){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 'S'){
                    startX = i;
                    startY = j;
                    startK = k;
                }
                else if (arr[i][j][k] == 'E'){
                    endX = i;
                    endY = j;
                    endK = k;
                }
            }
        }
    }

}
int main(){
    fastIO();

    while(true){
        cin >> L >> R >> C; //r행 c열
        if(!L && !R && !C) break;
        input();
        BFS();
        if(visited[endX][endY][endK]){
            cout << "Escaped in "<<visited[endX][endY][endK]-1 <<" minute(s)." << endl;
        }
        else{
            cout << "Trapped!"<<endl;
        }
    }



    return 0;
}