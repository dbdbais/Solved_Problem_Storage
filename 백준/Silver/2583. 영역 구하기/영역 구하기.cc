//
// Created by newbi on 2023-09-25.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[104][104], visited[104][104];
int M,N,K,cnt;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int DFS(int x,int y){
    arr[x][y] =1;
    int ret = 1;
    for(int i=0;i<4;i++){
        int qx = x + dx[i];
        int qy = y + dy[i];
        if(qx <0 || qx >= M || qy <0 || qy >= N || arr[qx][qy]) continue;
        arr[qx][qy] = 1;
        ret += DFS(qx,qy);
    }
    return ret;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    int x1,y1,x2,y2;
    for(int i=0;i<K;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1;j<x2;j++){
            for(int k= y1;k<y2;k++){
                arr[k][j] = 1;
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j] != 1){
                ans.push_back(DFS(i,j));
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size()<<'\n';
    for(auto elem : ans){
        cout << elem <<" ";
    }
    return 0;
}