//
// Created by newbi on 2024-02-27.
//
#include <iostream>

#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int dx[] = {1,-1,-1,1};
int dy[] = {1,1,-1,-1};

int N,T,startX,startY;
int arr[22][22];
int ans = -1;
bool dessert[101];
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    For(i,0,N){
        For(j,0,N){
            cin >> arr[i][j];
        }
    }
}
bool out(int x,int y){
    return x <0 || x >= N || y <0 || y >= N;
}

void DFS(int x,int y,int cnt,int dir){
    if(out(x,y)) return;    //나갔다면 리턴
    //cout <<"X: "<< x <<" Y: "<< y << endl;
    if( cnt > 1 && x == startX && y == startY){ //원점으로 돌아왔다면
        //cout <<"Cnt: "<< cnt << endl;
        ans = max(ans,cnt); //최대 값 갱신
        return;
    }
    for(int i = dir ; i<= dir+1;i++){
        if(i>3) break;  //다시 도는 순간 사각형이 아니다.

        int qx = x + dx[i];
        int qy = y + dy[i];

        if(out(qx,qy)) continue;    //밖으로 나가면 방향을 바꾼다

        if(dessert[arr[qx][qy]]) continue;  //이미 가본 디저트 카페라면

        dessert[arr[qx][qy]] = true;    //먹은 디저트 처리
        DFS(qx,qy,cnt+1,i); //카운트 증가해서 다음으로 보냄
        dessert[arr[qx][qy]] = false;   //원복
    }
}

void solve(){
    For(i,0,N){
        For(j,0,N){
           // cout << "start"<<endl;
            startX = i;
            startY = j;
            DFS(i,j,0,0);
        }
    }
}
void reset(){
    ans = -1;
}

int main(){
    fastIO();
    cin >> T;
    for(int t = 1; t<=T;t++){
        cin >> N;
        input();
        solve();
        cout <<"#"<<t<<" "<<ans <<endl;
        reset();
    }
    return 0;
}
