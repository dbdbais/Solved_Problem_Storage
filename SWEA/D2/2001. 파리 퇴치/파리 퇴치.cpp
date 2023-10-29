//
// Created by newbi on 2023-10-29.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int arr[16][16];
int N,M,T,ans;

bool out(int x,int y){
    return (x<0 || x >= N || y < 0 || y >=N);
}

void input(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
}
void reset(){
    memset(arr,0,sizeof(arr));
    ans = 0;
}
auto combi(){
    vector<pair<int,int>> v;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
           v.push_back({i,j});
        }
    }
    return v;
}

void BFS(int x,int y){
    bool isOk = true;
    int cnt = 0;
    auto v = combi();
    for(auto cord : v){
        int qx = x+cord.first;
        int qy = y+cord.second;

        if(out(qx,qy)){
            isOk = false;
            break;
        }
        cnt += arr[qx][qy];
        }
        if (isOk){
            ans = max(ans,cnt);
        }
    }
    void solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            BFS(i,j);
        }
    }
}

int main(){

    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> N >> M;

        input();
        solve();
        cout <<"#"<<i<<" "<<ans<<'\n';
        reset();
    }

    return 0;
}
