//
// Created by newbi on 2024-05-11.
//
#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int ans;
char arr[25];
int ipt[7];
bool visited[5][5];
bool adj[5][5];

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

pair<int,int> conv(int num){
    return {num/5,num%5};
}

bool out(int x,int y){
    return x < 0 || y <0 || x >= 5 || y >= 5;
}

bool isAdj(){
    memset(visited,false,sizeof(visited));
    memset(adj,false,sizeof(adj));
    For(i,0,7){
       auto c = conv(ipt[i]);
       adj[c.first][c.second] = true;
    }

    queue<pair<int,int>> q;
    auto st = conv(ipt[0]);
    q.push(st);
    visited[st.first][st.second] = true;
    int cnt = 1;
    while(q.size()){
        auto cur = q.front();q.pop();
        int x = cur.first;
        int y = cur.second;

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)||visited[qx][qy]|| !adj[qx][qy]) continue;

            cnt++;
            visited[qx][qy] = true;
            q.push({qx,qy});
        }
    }

    return cnt == 7;
}
bool check(){
    int scnt =0;
    int ycnt = 0;
    For(i,0,7){
        if(arr[ipt[i]] =='S') scnt++;
        else ycnt++;
    }
    return scnt > ycnt;
}

void print(){
    For(i,0,7){
        cout << ipt[i] <<" ";
    }
    cout << endl;
}

void combi(int cnt,int start){
    if(cnt == 7){
        if(check() && isAdj()){
            ans++;
            //print();
        }
        return;
    }
    for(int i=start+1;i<25;i++){
        ipt[cnt] = i;
        combi(cnt+1,i);
    }
}
void input(){
    string s;
    For(i,0,5){
        cin >> s;
        For(j,0,5){
            arr[5*i+j] = s[j];
        }
    }
}

int main(){
    fastIO();
    input();
    combi(0,-1);
    cout << ans << endl;
    return 0;
}