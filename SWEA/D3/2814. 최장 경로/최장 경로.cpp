//
// Created by newbi on 2023-11-16.
//
#include <iostream>

#include <cstring>
using namespace std;

int T,N,M,ans=1,x,y;

int arr [14][14];
bool visited[14];
void DFS(int idx,int cnt){
    if(ans < cnt){
        ans = cnt;
    }
    for(int i=1;i<=N;i++){
        if(!visited[i] && arr[idx][i]){
            visited[i] = true;
            DFS(i,cnt+1);
            visited[i] = false;
        }
    }
    return;
}


void solve(){
    for(int i=1;i<=N;i++){
        visited[i] = true;
        DFS(i,1);
        visited[i] = false;
    }
}

void reset(){
    ans = 1;
    memset(visited,false,sizeof(visited));
    memset(arr,0,sizeof(arr));

}

int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> N >> M;
        for(int j=0;j<M;j++){
            cin >> x >> y;
            arr[x][y] = 1;
            arr[y][x] = 1;
        }
        solve();
        cout << "#"<<i<<" "<<ans<<'\n';
        reset();
    }

    return 0;
}