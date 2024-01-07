//
// Created by newbi on 2024-01-07.
//
#include <iostream>
#include <cstring>
using namespace std;

int T,N,cnt;
const int bomb = 1e8;

int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

int visited[304][304];
int mp[304][304];

void input(){
    string s;
    for(int i=0;i<N;i++){
        cin >> s;
        for(int j=0;j<N;j++){
            if(s[j] == '*') {
                visited[i][j] = bomb; //지뢰가 있다면 해당하는 좌표 bomb으로 수정
                mp[i][j] = '*';
            }
            else{
                mp[i][j] = '.';
                visited[i][j] = -1;
            }
        }
    }
}

bool out(int x,int y){
    return x <0 || x >= N || y < 0 || y >= N;
}

int check(int x,int y){     //주변의 지뢰를 체크해서 리턴
    int bmbAround = 0;
    for(int i=0;i<8;i++){
        if(out(x+dx[i],y+dy[i])) continue; //나갔다면 SKIP
        if(mp[x+dx[i]][y+dy[i]] == '*') bmbAround++;
    }
    return bmbAround;
}

void DFS(int x,int y){
    if(visited[x][y] == bomb || visited[x][y] != -1) return;
    visited[x][y] = 0;
    for(int i=0;i<8;i++){
        int qx = x + dx[i];
        int qy = y + dy[i];
        if(out(qx,qy)) continue;
        int tmp = check(qx,qy); //연쇄적인 bomb 체크
        if(!tmp){   //주변에 아무것도 없다면
            DFS(qx,qy);
        }
        else{
            visited[qx][qy] = tmp;
        }
    }
    return;
}

void solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j] == bomb || visited[i][j] != -1) continue;
            int cur = check(i,j);   //주위의 bomb을 체크
            if(!cur){   //폭탄이 없다면
                DFS(i,j);
                cnt++;
            }
        }
    }
}
void left_check(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mp[i][j] == '*' || visited[i][j] != -1) continue;
            int cur = check(i,j);
            cnt++;
            visited[i][j] = cur;
        }
    }
}


void reset(){
    memset(visited,-1,sizeof(visited));
    memset(mp,0,sizeof(mp));
    cnt =0;
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();

    cin >> T;
    for(int idx = 1;idx <= T;idx++){
        reset();
        cin >> N;
        input();
        solve();
        left_check();
        cout << "#"<<idx<<" "<<cnt<<'\n';
    }
    
    return 0;
}