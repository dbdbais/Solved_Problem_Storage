//
// Created by newbi on 2024-03-19.
//
#include<iostream>
#include <queue>
#include <vector>
#include <cstring>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M, ans=1e9, zcnt;
const int dx[] ={0,0,-1,1};
const int dy[] = {-1,1,0,0};

int arr[51][51],ipt[10];
bool visited[51][51];

vector<pair<int, int>> virus;

bool out(int x,int y){
    return x<0 || y <0 || x >=N || y >= N;
}

void input() {
    For(i, 0, N) {
        For(j, 0, N) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) virus.push_back({ i,j });
        }
    }
}
void print(){
    For(i,0,N){
        For(j,0,N){
            cout << visited[i][j] <<" ";
        }
        cout << endl;
    }
    cout <<endl;
}
void check(){
    For(i,0,N){
        For(j,0,N){
            if(arr[i][j] ==0) zcnt++;
        }
    }

}

void BFS( queue<pair<int,int>> q) {
    int cnt = 0;
    int tzcnt=0;
    bool found = false;
    while (q.size()) {
        cnt++;  // 1증가
        if(cnt >= ans) break;
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {   //레벨 순회
            auto cord = q.front();
            q.pop();
            int x = cord.first;
            int y = cord.second;

            For(j, 0, 4) {
                int qx = x + dx[j];
                int qy = y + dy[j];
                if (out(qx, qy) || visited[qx][qy] || arr[qx][qy] == 1) continue;
                if(arr[qx][qy] == 0) tzcnt++;   //0을 발견하면 증가
                visited[qx][qy] = true;
                q.push({qx, qy});
            }
            if (tzcnt == zcnt){
                found = true;
                break;
            }
        }
        if(found) break;
//        cout << "cnt :" << cnt << endl;
//        print();
    }
    if (found && ans > cnt) ans = cnt;
}

void combi(int start,int cnt){
    if(cnt == M){
        memset(visited,false,sizeof(visited));
       queue<pair<int,int>> temp;
        for(int j=0;j<M;j++){
            //cout << ipt[j] <<" ";
            auto cord = virus.at(ipt[j]);
            visited[cord.first][cord.second] = true;
            temp.push(cord);
        }
        BFS(temp);
        return;
    }

    for(int i=start+1;i<virus.size();i++){
        ipt[cnt] = i;
        combi(i,cnt+1);
    }
}

int main() {
    fastIO();
    cin >> N >> M;
    input();
    check();    //zcnt 계산
    if(zcnt == 0){
        ans =0;
    }
    else {
        combi(-1, 0);
    }
    if(ans == 1e9) ans = -1;
    cout << ans <<endl;
    return 0;
}