//
// Created by newbi on 2024-06-10.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
bool found;
bool visited[7][7];
char cArr[7][7];
vector<pair<int,int>> teachers;

struct cord{
    int x;
    int y;
    int dir;
};

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

bool out(int x,int y){
    return x < 1 || y < 1 || x >N || y > N;
}

void print(){

    For(i,1,N+1){
        For(j,1,N+1){
            cout << cArr[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
    For(i,1,N+1){
        For(j,1,N+1){
            cout <<visited[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

bool check(){
    queue<cord> q;
    for(auto elem : teachers){
        For(i,0,4){
            q.push({elem.first,elem.second,i});
            //4방향으로 넣는다.
        }
    }
    while(q.size()){
        auto cur = q.front(); q.pop();
        int x = cur.x;
        int y = cur.y;
        int dir = cur.dir;
        visited[x][y] = true;
        int qx = x + dx[dir];
        int qy = y + dy[dir];

        if(out(qx,qy)||cArr[qx][qy] == 'O') continue;
        //나갔거나, 장애물을 만나면 끝

        if(cArr[qx][qy] == 'S') return false;

        //다음 탐색 진행
        q.push({qx,qy,dir});
    }
    return true;
}

void input(){
    For(i,1,N+1){
        For(j,1,N+1){
            cin >> cArr[i][j];
            if(cArr[i][j] == 'T'){
                teachers.push_back({i,j});
            }
        }
    }
}

void DFS(int idx,int x,int y){

    //NonPromising 제거
    if(found) return;

    if(idx == 3){
        if(check()){
            found = true;
            //print();
        }
        return;
    }
    for(int i=x;i<=N;i++){
        for(int j=y;j<=N;j++){
            if(cArr[i][j] == 'X'){
                cArr[i][j] = 'O';
                if(j == N){
                    DFS(idx+1,i+1,0);
                }
                else{
                    DFS(idx+1,i,0);
                }
                //원복
                cArr[i][j] ='X';
            }
        }
    }

}

int main(){
    fastIO();
    cin >> N;
    input();
    DFS(0,0,0);
    if(found) cout << "YES" << endl;
    else{
        cout <<"NO" <<endl;
    }
    return 0;
}