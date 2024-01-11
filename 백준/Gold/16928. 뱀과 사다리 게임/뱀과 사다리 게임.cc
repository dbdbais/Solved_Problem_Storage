//
// Created by newbi on 2024-01-11.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> board(101,-1);
int N, M, a, b;
int special[104];

void input(){
    for(int i=0;i<N;i++){
        cin >> a >> b;
        special[a] = b;
    }
    for(int j=0;j<M;j++){
        cin >> a >> b;
        special[a] = b;
    }
}

bool out(int x){
    return x <1 || x>100;
}

void BFS(int x){
    queue<int> q;
    q.push(x);
    board[x] = 0;
    while(q.size()){
        x = q.front(); q.pop();
        for(int i=1;i<=6;i++){
            int cnt = board[x]+1 ;  //전에 지점에서 주사위 한번 추가
            int qx = x + i;
            if(out(qx)) continue;   //나가면 SKIP
            if(special[qx]) qx = special[qx];
            if(board[qx] == -1){
                board[qx] = cnt;
                q.push(qx);
            }
        }
    }
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void print(){
    for(auto elem: board){
        cout << elem <<" ";
    }
}

int main(){

    fastIO();

    cin >> N >> M;
    input();
    BFS(1);
    //print();
    cout << board[100]<<'\n';

    return 0;
}