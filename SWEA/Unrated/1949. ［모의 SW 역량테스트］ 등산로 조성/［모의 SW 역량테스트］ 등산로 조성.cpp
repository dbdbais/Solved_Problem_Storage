//
// Created by newbi on 2024-02-20.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int T,N,K,ans;

int arr[8][8];
bool visited[8][8];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<pair<int,int>> highest;

bool out(int x,int y){
    return x<0 || x >= N || y <0 || y >=N;
}

void input(){
    highest.clear();
    int mx =0;
    For(i,0,N){
        For(j,0,N){
            cin >> arr[i][j];
            if(arr[i][j] > mx) mx = arr[i][j];
        }
    }

    For(i,0,N){
        For(j,0,N){
            if(arr[i][j] == mx) highest.push_back({i,j});
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
    cout << endl;

    For(i,0,N){
        For(j,0,N){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }

    cout << endl;



}

void DFS(int x,int y,int cnt,bool chance){
    if(cnt > ans ) ans = cnt;
    /*
    cout << "chance :" << chance <<endl;
    print();
     */
    for(int i=0;i<4;i++){
        int qx = x + dx[i];
        int qy = y + dy[i];

        if(out(qx,qy)||visited[qx][qy]) continue;

        if(arr[qx][qy] < arr[x][y]){    //갈 수 있다면
            visited[qx][qy] = true;     //방문 처리
            DFS(qx,qy,cnt+1,chance);
            visited[qx][qy] = false;    //원복
        }
        else{
            if(chance){ //산을 깎을 수 있다면
                chance = false;
                For(a,1,K+1){
                    int tmp = arr[qx][qy] - a;
                    if(arr[x][y]>tmp){
                        visited[qx][qy] = true;
                        arr[qx][qy] -= a;
                        DFS(qx,qy,cnt+1,chance);
                        arr[qx][qy] += a;
                        visited[qx][qy] = false;
                    }
                }
                chance = true;  //다음을 위해 원복
            }
        }
    }

}

void solve(){
    for(auto cord : highest){
        visited[cord.first][cord.second] = true;
        DFS(cord.first,cord.second,1,true);
        visited[cord.first][cord.second] = false;
    }
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void reset(){
    ans =0;
    //fill(&visited[0][0],&visited[0][0]+8*8,false);
}
int main(){
    fastIO();
    cin >> T;
    For(t,1,T+1){
        cin >> N >> K;
        input();
        solve();
        cout << "#"<<t<<" "<<ans <<endl;
        reset();
    }

    return 0;
}