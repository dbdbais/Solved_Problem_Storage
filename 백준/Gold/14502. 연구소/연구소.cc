//
// Created by newbi on 2023-10-10.
//
#include <iostream>
#include<vector>

using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int N,M,ans;
vector<vector<int>> vec(10,vector<int>(10,-1));
vector<pair<int,int>> wall;
vector<pair<int,int>> virus;
bool out(int x,int y){
    if(x<0 || y <0 || x >= N || y >=M) return true;
    else return false;
}

void DFS(int x,int y){

    for(int i=0;i<4;i++){
        int qx = x + dx[i];
        int qy = y + dy[i];

        if(out(qx,qy)) continue;
        if(vec[qx][qy] !=0) continue;
        vec[qx][qy] = 2;
        DFS(qx,qy);
    }
    return;
}

int search(){
    for(auto cord : virus){
        DFS(cord.first,cord.second);
    }
    int cnt =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(vec[i][j] == 0) cnt++;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(vec[i][j] == 2) vec[i][j] = 0;
        }
    }
    for(auto cord : virus){
        vec[cord.first][cord.second] = 2;
    }
    return cnt;
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> vec[i][j];
            if(vec[i][j] == 2){ //바이러스 라면
                virus.push_back({i,j});
            }
            else if(vec[i][j] == 0){   //벽의 후보 push
                wall.push_back({i,j});
            }
        }
    }
    for(int i=0;i<wall.size();i++){
        for(int j=i+1;j<wall.size();j++){
            for(int k = j+1;k<wall.size();k++){
                vec[wall[i].first][wall[i].second] = 1;
                vec[wall[j].first][wall[j].second] = 1;
                vec[wall[k].first][wall[k].second] = 1;
                ans = max(ans,search());
                vec[wall[i].first][wall[i].second] = 0;
                vec[wall[j].first][wall[j].second] = 0;
                vec[wall[k].first][wall[k].second] = 0;
            }
        }
    }

    cout << ans <<'\n';


    return 0;
}
