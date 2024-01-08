//
// Created by newbi on 2024-01-08.
//
#include <iostream>
#include <queue>

using namespace std;

int T, N, A, B, C, D;
const int INF = 1e8;
int visited[17][17];
int arr [17][17];
int dx[] ={0,0,-1,1};
int dy[] = {1,-1,0,0};
bool out(int x,int y){
    return x <0 || x >= N || y < 0 || y >= N;
}

void input(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j] == INF){
                cout << "I" <<" ";
            }
            else{
            cout << visited[i][j]<<" ";}
        }
        cout <<'\n';
    }
    cout <<'\n';
}

void reset(){
    fill(&visited[0][0], &visited[0][0] + 17 * 17, INF);
    fill(&arr[0][0], &arr[0][0] + 17 * 17, 0);
}

void BFS(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;

    while(q.size()){
        auto cord = q.front(); q.pop();
        x = cord.first;
        y = cord.second;
        bool tornado = false;
        for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];
            if(out(qx,qy) || arr[qx][qy] == 1 || visited[qx][qy] != INF) continue;    //나갔거나 벽이거나 이미 방문
            if(arr[qx][qy] == 2){   //소용돌이라면
                if(visited[x][y] % 3 == 0){   //지나갈 수 있는 시기라면
                    visited[qx][qy] = visited[x][y] + 1;
                    q.push({qx,qy});
                }
                else{   //그렇지 않다면
                    q.push({x,y});  //다시 집어넣는다.
                    tornado = true; //토네이도를 지나가기 위해 기다린다.
                }
            }
            else{   //지나갈 수 있는 곳이라면
                visited[qx][qy] = visited[x][y] + 1;
                q.push({qx,qy});
            }
        }
        if(tornado) visited[x][y] += 1;   //토네이도를 만났다면 지금 자리 +1 해준다
        if(visited[C][D] != INF) break;
    }

}

int main(){

    fastIO();

    cin >>T ;

    for(int idx = 1;idx <= T;idx++){
        reset();
        cin >> N;
        input();
        cin >> A >> B >> C >>D;
        BFS(A,B);
        if(visited[C][D] == INF){
            cout << "#" << idx << " " << -1<< '\n';
        }
        else {
            cout << "#" << idx << " " << visited[C][D] - 1 << '\n';
        }
        //print();
    }

    return 0;
}

