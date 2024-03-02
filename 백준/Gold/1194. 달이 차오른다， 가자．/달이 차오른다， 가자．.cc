//
// Created by newbi on 2024-03-02.
//
#include<iostream>
#include <queue>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

using namespace std;

int N,M,ans = 1e9,startX,startY;
char arr[51][51];
bool visited[51][51][65];    //현재 키 값 가지고 있다.

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

bool out(int x,int y){
    return x<1 || y <1 || x>N || y >M;
}

struct User{
    int x;
    int y;
    int key;
    int dist;

    User(int x,int y,int key,int dist):x(x),y(y),key(key),dist(dist){

    }
};

void print(User u){
    cout << "(" <<u.x <<", "<< u.y <<") Key: "<<u.key <<" D :"<<u.dist <<endl;

    For(i,1,N+1){
        For(j,1,M+1){
            cout << visited[i][j][u.key] <<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;

}

void BFS(int x,int y){

    queue<User> q;
    visited[x][y][0] = true;


    q.push(User(x,y,0,0));
    while(q.size()){
        auto cur = q.front(); q.pop();
        x = cur.x;
        y = cur.y;
        int key = cur.key;    //현재 키 상태
       // print(cur);
        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)||arr[qx][qy] == '#' || visited[qx][qy][key]) continue;    //나가거나, 벽이거나, 이미 방문한적있다면 SKIP

            if(arr[qx][qy] == '1' ){    //다음이 종점이라면
                cur.dist++;
                if(ans > cur.dist) ans = cur.dist;
                break;
            }

            if(isalpha(arr[qx][qy])){   //알파벳이라면
                if(arr[qx][qy] >= 'A' && arr[qx][qy] <='F'){    //대문자라면
                    if(cur.key & 1<<arr[qx][qy]-'A'){   //키 검사해서 있다면
                        visited[qx][qy][cur.key] = true;
                        q.push(User(qx,qy,cur.key,cur.dist+1));
                    }
                    else{   //키가 없다면 다음으로
                        continue;
                    }

                }
                else{   //소문자라면
                    if(visited[qx][qy][cur.key | 1<<arr[qx][qy]-'a']) continue;
                    visited[qx][qy][cur.key | 1<<arr[qx][qy]-'a'] = true;
                    q.push(User(qx,qy,cur.key | 1<<arr[qx][qy]-'a',cur.dist+1));
                }

            }
            else{   //그냥 갈 수 있다면
                visited[qx][qy][cur.key] = true;
                q.push(User(qx,qy,cur.key,cur.dist+1));
            }



        }


    }
}


int main(){
    fastIO();
    cin >> N >> M;
    For(i,1,N+1){
        For(j,1,M+1){
            cin >> arr[i][j];
            if(arr[i][j] =='0'){
                startX = i;
                startY = j;
                visited[startX][startY][0] = true;
            }
        }
    }

    BFS(startX,startY);

    if(ans == 1e9){
        ans = -1;
    }
    cout << ans <<endl;


    return 0;
}