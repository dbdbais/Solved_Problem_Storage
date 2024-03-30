//
// Created by newbi on 2024-03-26.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int arr[13][13];
deque<int> visited[13][13];

int N,K;
const int dx[] = { 0,0,-1,1 };	//우좌상하
const int dy[] = { 1,-1,0,0 };


struct Horse {
    int x;
    int y;
    int dir;
    int num;

    Horse(int x, int y, int dir,int num) :x(x), y(y), dir(dir),num(num) {}

    bool operator<(Horse h) {
            return num < h.num;
    }

};
vector<Horse> horses;
bool out(int x, int y) {
    return x <1 || y <1 || x >N || y > N;
}

int backward(int direc) {
    if (direc == 0) return 1;
    else if (direc == 1) return 0;
    else if (direc == 2) return 3;
    else if (direc == 3) return 2;

}

void print(){
    For(i,1,N+1){
        For(j,1,N+1){
            cout << visited[i][j].size() <<" ";
        }
        cout << endl;
    }
    cout << endl;

}

void solve() {
    int turn = 1;
    bool found = false;
    sort(horses.begin(), horses.end());	//말 정렬하고
    while (turn <= 1000) {
        for (Horse &h : horses) {
            //print();
            int x = h.x;    //지금 좌표
            int y = h.y;

            int qx = x + dx[h.dir];	//이동한 좌표
            int qy = y + dy[h.dir];

            if (out(qx, qy) || arr[qx][qy] == 2) {	//나가거나 파란색이라면 거꾸로 만든다.
                h.dir = backward(h.dir);	//거꾸로 한다.
                qx = x + dx[h.dir];
                qy = y + dy[h.dir];
                if (out(qx, qy) || arr[qx][qy] == 2) {  //거꾸로 한곳도 나갔거나 파랑색이면 그대로 있는다.
                    qx = x;	//이동하지 않는다.
                    qy = y;
                    continue;
                }
            }

            if(visited[x][y].size() > 1){   //여럿이 있는 다면
                if(arr[qx][qy] == 1){   //빨간색이라면
                    while(true){

                        int cur = visited[x][y].back();    //맨 위 에 위치한 것
                        for(Horse &c : horses){
                            if(c.num == cur){
                                c.x = qx;
                                c.y = qy;
                                visited[qx][qy].push_back(c.num);   //다음 위치의 위로 올린다.
                                visited[x][y].pop_back(); //위에거 제거
                                break;
                            }
                        }
                        if(cur == h.num) break; //지금 이동하는 놈까지 찾았으면 끝낸다.
                    }
                }
                else{   //빨간색이 아니라면
                    stack<int> stk;
                    while(true){

                        int cur = visited[x][y].back();    //맨 위 에 위치한 것
                        for(Horse &c : horses){
                            if(c.num == cur){
                                c.x = qx;
                                c.y = qy;
                                stk.push(c.num);  //임시벡터에 저장
                                visited[x][y].pop_back(); //위에거 제거
                                break;
                            }
                        }
                        if(cur == h.num) {
                            while(stk.size()) {
                                visited[qx][qy].push_back(stk.top());
                                stk.pop();
                            }
                            break;
                        }
                    }
                }
            }
            else{   //혼자라면
                visited[x][y].pop_back();
                h.x = qx;
                h.y = qy;
                visited[qx][qy].push_back(h.num);
            }

            if(visited[qx][qy].size() >=4){
                found = true;
                //print();
                //cout << "done" <<endl;
                break;
            }
        }
        if(found) break;
        turn++;
    }
    if(found) cout << turn << endl;
    else cout << -1 << endl;

}

void input() {

    For(i, 1, N+1) {
        For(j, 1, N+1) {
            cin >> arr[i][j];
        }

    }
}

int main() {
    fastIO();

    cin >> N >> K;
    input();
    int x, y, dir, num = 1;
    For(i, 1, K+1) {
        cin >> x >> y >> dir;
        visited[x][y].push_back(num);
        horses.push_back(Horse(x, y, dir - 1, num++));
    }
    solve();
    return 0;
}