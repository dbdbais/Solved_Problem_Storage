//
// Created by newbi on 2023-11-12.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int _len, strt;
bool arr[101][101];
int visited[101];
int ans;

void BFS(int cur){
    queue<int> q;
    q.push(cur);
    visited[cur] = 1;

    while(q.size()){
        cur = q.front(); q.pop();

        for(int i=1;i<=100;i++){
            if(!visited[i] && arr[cur][i]){
                visited[i] = visited[cur]+1;    //지금 경로에서 하나 추가
                q.push(i);
            }
        }
    }

    auto mx = *max_element(visited+1,visited+100);  //visited 최대 값 찾는다.
    for(int i = 100;i>=0;i--){
        if(visited[i] == mx) {
            ans = i;
            break;
        }
    }
}

void reset(){
    memset(arr,false,sizeof(arr));
    memset(visited,0,sizeof(visited));
    ans = 0;
}
int main(){
    int a,b;

    for(int i=1;i<=10;i++){
        cin >> _len >> strt;
        for(int j=0;j<(_len/2);j++){
            cin >> a >> b;
            if(!arr[a][b]){
                arr[a][b] = true;
            }
        }
        BFS(strt);
        cout << "#"<<i<<" "<<ans<<'\n';
        reset();
    }

    return 0;
}