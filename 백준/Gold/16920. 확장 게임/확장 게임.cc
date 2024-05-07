//
// Created by newbi on 2024-05-07.
//
#include <iostream>
#include <queue>
#include <string>
#include <vector>


#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
typedef long long ll;
int N, M, P, totCnt;

ll S[11];	//이동할 수 있는 거리
ll score[11];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

bool out(int x, int y) {
    return  x < 1 || y < 1 || x > N || y >M;
}


bool wall[1004][1004];	//벽 check
int visited[1004][1004];	//플레이어의 번호가 기록될 배열
vector<pair<int, int>> cord [11];
vector<pair<int,int>> nxtCord[11];

void output() {
    cout << "wall " << endl;
    For(i, 1, N + 1) {
        For(j, 1, M + 1) {
            cout << wall[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    cout << "visited" << endl;
    For(i, 1, N + 1) {
        For(j, 1, M + 1) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    For(i, 1, 10) {
        cout << i << " : ";
        for (auto c : cord[i]) {
            cout << " ("<<c.first << ", " << c.second << ") ";
        }
        cout << endl;
    }
}

void BFS( vector<pair<int,int>> &c,int weight,int num){

    queue<pair<int,int>> q;
    //visited[x][y] = num;
    for(auto elem : c){
        q.push(elem);
    }
    int cnt = 1;
    while(q.size()){

        int qSize = q.size();

        For(i,0,qSize){
            auto cur = q.front(); q.pop();
            int curX = cur.first;
            int curY = cur.second;

            For(a,0,4){
                int qx = curX + dx[a];
                int qy = curY + dy[a];

                if(out(qx,qy)  || wall[qx][qy] || visited[qx][qy]) continue;
                //나가거나, 이미 방문했거나 이미 누군가가 방문했다면
                    if(cnt == weight){
                        //가장 외곽의 경우

                        bool isOk = false;

                        For(b,0,4){
                            int zx = qx + dx[b];
                            int zy = qy + dy[b];

                            if(out(zx,zy)|| wall[zx][zy]||visited[zx][zy]!=0) continue;
                            isOk = true;
                            break;
                        }
                        if(isOk){
                            nxtCord[num].push_back({qx,qy});
                        }
                    }
                    score[num]++;
                    totCnt++;
                    visited[qx][qy] = num;
                    q.push({qx,qy});
            }
        }
        cnt++;
        if(cnt > weight) break;
    }

}

bool isDone(){
    For(i,1,P+1){
        if(!cord[i].empty()) return false;
    }
    return true;
}

void solve() {
    while(totCnt != N*M) {
        For(i,1,P+1){
            //cout << i <<"th" <<endl;
            BFS(cord[i],S[i],i);
            cord[i] = nxtCord[i];
            nxtCord[i].clear();
            //output();
        }
        if(isDone()) break;
    }


}

void input() {
    string s;
    For(i, 1, N + 1) {
        cin >> s;
        For(j, 1, M + 1) {
            if (s[j - 1] == '.') {
                continue;
            }
            else if (s[j - 1] == '#') {
                totCnt++;
                wall[i][j] = true;
            }
            else {
                int val = s[j - 1] - '0';
                totCnt++;
                score[val]++;
                visited[i][j] = val;
                cord[val].push_back({ i,j });	//좌표 집어 넣는다.
            }
        }
    }
}

int main() {
    fastIO();
    ll tmp;
    cin >> N >> M >> P;
    For(i, 1, P+1) {
        cin >> tmp;
        S[i] = tmp;
    }
    input();
    //output();
    solve();
    For(i,1,P+1){
        cout << score[i]<<" ";
    }
    cout << endl;

    return 0;
}