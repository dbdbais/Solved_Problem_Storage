//
// Created by newbi on 2024-01-06.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool visited[101];  //방문 배열
int T,N,M,a,b,cnt;  //연결요소의 개수

vector<int> v [104];    //연결 확인

void DFS(int n){    //DFS로 방문 처리
        visited[n] = true;  //방문 처리
        for (auto elem: v[n]) {
            if (!visited[elem]) {    //연결된 요소 중 방문하지 않은 곳이 있다면
                DFS(elem);
            }
        }


}

void solve(){   //1 ~ N까지 DFS
  
    for(int i = 1;i<=N;i++){
        if(!visited[i]){
            DFS(i);
            cnt++;
        }
    }
}

void reset(){   //초기화
    memset(visited,false,sizeof(visited));
    for(int i=0;i<104;i++){
        v[i].clear();
    }
    cnt = 0;
}
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();

    cin >> T;

    for(int idx = 1;idx<=T; idx++){
        cin >> N >> M;
        for(int j = 0;j<M;j++){
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        solve();
        cout << "#"<<idx <<" "<<cnt<<'\n';
        reset();
    }

    return 0;
}