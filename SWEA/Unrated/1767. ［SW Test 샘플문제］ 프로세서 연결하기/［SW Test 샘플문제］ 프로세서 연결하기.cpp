//
// Created by newbi on 2024-02-17.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int arr[13][13];
bool visited[13][13];
int mx;
bool found;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int T,N;
vector<pair<int,int>> core;
vector<pair<int,int>> ans;  //연결된 코어, 전선 길이

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool out(int x,int y){
    return x<1 || x >N || y <1 || y >N;
}

void DFS(int x,int y,int dir){
    x = x+dx[dir];
    y = y+dy[dir];

    if(out(x,y)){
        found = true;
        return;
    }
    if(visited[x][y] || arr[x][y] == 1) return; //전선이 있거나, 코어에 부딪히면
    visited[x][y] = true;   //전선 깐다.
    DFS(x,y,dir);   //다음 루트로 전진한다.

}
int search(){
    int cnt =0;
    For(i,1,N+1){
        For(j,1,N+1){
            if(visited[i][j]) cnt++;
        }
    }
    return cnt;
}

bool custom(pair<int,int>a, pair<int,int>b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

void solve(int idx,int connect){

    if(connect+ core.size()-idx < mx) return;   //가망 없는 경우 가지 치기

    if(idx ==core.size()){
        mx = max(connect,mx);
        if(connect >= mx) {
            ans.push_back({connect, search()});    //연결된 코어 + 전선길이
        }
        return;
    }


    int x = core[idx].first;
    int y = core[idx].second;
    bool savePoint[13][13];

    copy(&visited[0][0],&visited[0][0]+13*13,&savePoint[0][0]);   //임시 저장
    For(i,0,4){
        int tempConn = connect;
        DFS(x,y,i); //4방향 탐색한다.
        if(!found){ //찾지 못했다면
            //초기화 한다.
            copy(&savePoint[0][0],&savePoint[0][0]+13*13,&visited[0][0]);
        }
        else{   //찾았다면
            found =false;
            tempConn++;
        }
        solve(idx+1,tempConn);  //다음 케이스, 연결된 프로게서 넘긴다.
        copy(&savePoint[0][0],&savePoint[0][0]+13*13,&visited[0][0]);   //원복
    }
}

void reset(){
    ans.clear();
    core.clear();
    mx =0;
    fill(&visited[0][0],&visited[0][0]+13*13,false);
}

int main(){
    fastIO();
    cin >> T;

    for(int t =1;t<=T;t++){
        cin >> N;
        For(i,1,N+1){
            For(j,1,N+1){
                cin >> arr[i][j];
                if(arr[i][j] == 1) {
                    if( i !=1 && i!=N && j!=1 && j!=N){ //가장자리가 아니라면
                        core.push_back({i, j});
                    }
                }    //코어 기억
            }
        }
        solve(0,0);


        sort(ans.begin(),ans.end(),custom);
        cout <<"#"<<t<<" "<<ans[0].second <<endl;
        reset();

    }


    return 0;
}

