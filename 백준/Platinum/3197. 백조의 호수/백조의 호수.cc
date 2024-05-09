//
// Created by newbi on 2024-05-09.
//
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int R, C;

pair<int, int> swan[2];

bool ice[1505][1505];
char arr[1505][1505];
bool visited[1505][1505];
bool sVisited[1505][1505];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

queue<pair<int, int>> iceList;
//가장 외곽의 얼음을 체크
queue<pair<int, int>> nextIce;
//다음 거 체크

queue<pair<int,int>> swanList;
queue<pair<int,int>> nextSwan;

vector<pair<int, int>> delIce;
//없앨 곳 체크
bool out(int x, int y) {
    return x <1 || y < 1 || x > R || y > C;
}

void output() {
    cout << "ICE : " << endl;
    For(i, 1, R + 1) {
        For(j, 1, C + 1) {
            cout << ice[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Visited : " << endl;
    For(i, 1, R + 1) {
        For(j, 1, C + 1) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "sVisited : " << endl;
    For(i, 1, R + 1) {
        For(j, 1, C + 1) {
            cout << sVisited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

//가장 처음에만 사용
void putBoarder() {
    For(i, 1, R + 1) {
        For(j, 1, C + 1) {
            if (!ice[i][j]){
                iceList.push({i,j});
            }
        }
    }

    while(iceList.size()){
        auto c = iceList.front(); iceList.pop();
        int x = c.first;
        int y = c.second;

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];
            if(out(qx,qy) || visited[qx][qy]) continue;
            if(ice[qx][qy]){
             nextIce.push({qx,qy});
            }
            visited[qx][qy] = true;
        }
    }

//    while(nextIce.size()){
//        auto c = nextIce.front(); nextIce.pop();
//        cout << c.first <<", " << c.second << endl;
//    }

}

void BFS(){

    while(nextIce.size()){
        auto m = nextIce.front();
        ice[m.first][m.second] = false;
        iceList.push(m);
        nextIce.pop();
    }
    while(iceList.size()){
        auto c = iceList.front();
        iceList.pop();
        int x = c.first;
        int y = c.second;

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)||visited[qx][qy]) continue;
            if(ice[qx][qy]){
                nextIce.push({qx,qy});
            }
            else{
                iceList.push({qx,qy});
            }
            visited[qx][qy] = true;
        }

    }
}

bool sBFS(){
    bool found =false;
    while(swanList.size()){
        auto c = swanList.front(); swanList.pop();
        int x = c.first;
        int y = c.second;
        sVisited[x][y] = true;
        if(x == swan[1].first && y == swan[1].second){
            found = true;
            break;
        }
        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];
            if(out(qx,qy) || sVisited[qx][qy]) continue;

            sVisited[qx][qy] = true;
            if(ice[qx][qy]){
                nextSwan.push({qx,qy});
            }
            else{
                swanList.push({qx,qy});
            }
        }
    }
    while(nextSwan.size()){
        auto c = nextSwan.front();
        swanList.push({c});
        nextSwan.pop();
    }

    return found;

}

//빙하 시간마다 풀이
int solve() {
    putBoarder();
    int t =0;
    while(true){
        if(sBFS()) break;
        BFS();
        //output();
        t++;
    }
    return t;
}


/*
//시간마다 녹고 새로운 외곽의 얼음을 추가한다.
void melt() {

    for (auto elem : iceList) {
        int x = elem.first;
        int y = elem.second;
        visited[x][y] = true;
        bool found = false;
        For(i, 0, 4) {
            int qx = x + dx[i];
            int qy = y + dy[i];

            if (out(qx, qy) || ice[qx][qy]) continue;
            delIce.push_back({ x,y });
            //녹을 얼음 체크
            found = true;
            break;
        }

        if (found) {
            For(i, 0, 4) {
                int qx = x + dx[i];
                int qy = y + dy[i];

                if (out(qx, qy) || !ice[qx][qy]|| visited[qx][qy]) continue;

                visited[qx][qy] = true;
                nextIce.push_back({ qx,qy });	//다음 얼음 집어넣는다.
            }
        }
    }

    for (auto elem : delIce) {
        ice[elem.first][elem.second] = false;
    }
    delIce.clear();

    iceList = nextIce;
    //다음 거로 전환
    nextIce.clear();
}

bool check(){
    bool found =false;
    queue<pair<int,int>> q;
    q.push({swan[0]});
    ground[swan[0].first][swan[0].second] = true;

    while(q.size()){

        auto c = q.front();q.pop();
        int x = c.first;
        int y = c.second;

        if(x == swan[1].first && y == swan[1].second){
            found = true;
            break;
        }

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy) || ground[qx][qy] || ice[qx][qy]) continue;

            ground[qx][qy] = true;
            q.push({qx,qy});
        }
    }
    memset(ground,false,sizeof(ground));
    return found;
}


//빙하 시간마다 풀이
int solve() {
    putBoarder();
    int t =0;
    while(!check()){
        melt();
        //output();
        t++;
    }
    return t;
}
*/
void input() {
    string s;
    int cnt = 0;
    For(i, 1, R + 1) {
        cin >> s;
        For(j, 0, C) {
            arr[i][j + 1] = s[j];

            if (arr[i][j + 1] == 'L') {
                swan[cnt++] = {i,j+1};
            }
            else if (arr[i][j + 1] == 'X') {
                ice[i][j+1] = true;
                //얼음 체크
            }
        }
    }
}


int main() {
    fastIO();
    cin >> R >> C;
    input();
    swanList.push(swan[0]);
    cout << solve() << endl;

    return 0;
}