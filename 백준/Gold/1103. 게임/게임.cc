//
// Created by newbi on 2023-09-26.
//
#include<iostream>
using namespace std;
int board [51][51], dp[51][51]; //보드와 메모제이션할 2차원 배열
bool visited [51][51];  //방문처리를 기록할 2차원 배열
int N,M;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
    cout<<endl;
}

int DFS(int x, int y){
    if( x <0 || x >= N || y < 0 || y >= M || board[x][y] == -1 ) return 0;  //주어진 범위를 벗어나거나 구멍을 만난다면 경로 차단

    /*
    cout <<"("<< x <<", "<<y<<")"<<endl;
    print();
    DEBUG
    */

    if(visited[x][y]){  //루프가 생긴다면 FAIL
        cout << -1 <<"\n";
        exit(0);
    }

    auto &ret = dp[x][y];   //메모제이션 이전에 왔던 경우를 기록해둔다.
    if(ret) return ret;             //ret가 0이 아니라면 리턴

    visited[x][y] = true;   //방문 처리
    int val = board[x][y];
    for(int i=0;i<4;i++){   //보드의 값만 큼 이동
        int qx = x+ dx[i]*val;
        int qy = y+ dy[i]*val;
        ret = max(ret,DFS(qx,qy)+1);    //더 높은 값을 dp배열의 x, y 값에 저장
    }
    visited[x][y] = false;  //원복
    return ret; // 첫 스타팅 포인트에 결국 가장 최대값이 리턴된다.
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char c;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j =0; j<M;j++){
            cin >> c;
            if(isalpha(c)) board[i][j]= -1; //알파벳이면 -1로 표시
            else board[i][j]= c-'0';    //아니면 int값으로 저장
        }
    }

    cout << DFS(0,0)<<'\n';

    //print();
    return 0;
}
