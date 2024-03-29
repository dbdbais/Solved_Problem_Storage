//
// Created by newbi on 2024-03-01.
//
#include <iostream>
#include <vector>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T,N;
int arr[101][101];
bool visited[101][101];
int startX;
int startY;
int score;
int ans;
const int dx[] = {0,0,-1,1}; // 좌, 우, 상, 하
const int dy[] = {-1,1,0,0};

vector<pair<int,int>> hole[5];

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool out(int x,int y){
    return x<0 || y <0 || x>=N || y >= N;
}
int bounce(int dir){
    if(dir == 0){
        return 1;
    }
    else if(dir == 1){
        return 0;
    }
    else if(dir == 2){
        return 3;
    }
    else{
        return 2;
    }
}

void print(){

    For(i,0,N){
        For(j,0,N){
            cout << arr[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;

    For(i,0,N){
        For(j,0,N){
            cout << visited[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}

void play(int x,int y,int dir){
    //cout << "( "<<x <<", "<<y <<" )" <<endl;

    int qx = x +dx[dir];    //다음 move
    int qy = y +dy[dir];

    if(arr[qx][qy] == -1||(qx == startX && qy == startY)){  //블랙홀을 만나거나, 시작자리로 돌아오면
        if(ans < score) ans = score;
        return;
    }

    if(out(qx,qy)){ //벽에 부딪히면 방향 반대로 바꾸고 반영
        //방향 바꾸고
        score = (score*2)+1;
        if(ans < score) ans = score;
        return;
    }

    if(arr[qx][qy] == 1){   //다음이 벽이라면

        if(dir == 0){
            dir = 2;
        }
        else if(dir == 3){
            dir = 1;
        }
        else{
            score = (score*2)+1;
            if(ans < score) ans = score;
            return;
        }
        score++;
        play(qx,qy,dir);
    }
    else if(arr[qx][qy] == 2){

        if(dir == 0){   //
            dir = 3;
        }
        else if(dir == 2){
            dir = 1;
        }
        else{
            score = (score*2)+1;
            if(ans < score) ans = score;
            return;
        }
        score++;
        play(qx,qy,dir);
    }
    else if(arr[qx][qy] == 3){

        if(dir == 1){
            dir = 3;
        }
        else if(dir == 2){
            dir = 0;
        }
        else{
            score = (score*2)+1;
            if(ans < score) ans = score;
            return;
        }
        score++;
        play(qx,qy,dir);
    }
    else if(arr[qx][qy] == 4){

        if(dir == 1){
            dir = 2;
        }
        else if(dir == 3){
            dir = 0;
        }
        else{
            score = (score*2)+1;
            if(ans < score) ans = score;
            return;
        }
        score++;
        play(qx,qy,dir);
    }
    else if(arr[qx][qy] == 5){
        score = (score*2)+1;
        if(ans < score) ans = score;
        return;
    }
    else if(arr[qx][qy] >= 6 && arr[qx][qy] <= 10){  //웜 홀이라면
        for(auto cord :hole[arr[qx][qy]-6]){
            if(cord.first == qx && cord.second == qy) continue;
            qx = cord.first;
            qy = cord.second;   //웜홀로 이동
            break;
        }
        play(qx,qy,dir);
    }
    else{   //0이면
        play(qx,qy,dir);    //다음으로 간다.
    }
    return;
}

void solve(){
    For(i,0,N){
        For(j,0,N){
            if(arr[i][j] == 0){
                startX = i;
                startY = j;
                For(a,0,4){
                    score = 0;  //점수 초기화
                    play(startX,startY,a);
                }
            }
        }
    }
}

int main(){
    fastIO();
    cin >> T;
    For(t,1,T+1){
        cin >> N;
        For(i,0,N){
            For(j,0,N){
                cin >> arr[i][j];
                if(arr[i][j] >= 6 && arr[i][j] <= 10 ){
                    hole[arr[i][j]-6].push_back({i,j});
                }
            }
        }

        solve();
        cout <<"#"<<t<<" "<< ans << endl;
        ans = 0;
        For(i,0,6){
            hole[i].clear();
        }
    }
    return 0;
}