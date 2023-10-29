//
// Created by newbi on 2023-10-11.
//
#include <iostream>
#include <vector>

using namespace std;
int N,M,ans;
int tetroX[5][4]={{0,0,0,0},{0,0,1,1},{0,1,2,2},{0,1,1,2},{0,0,0,1}};
int tetroY[5][4]={{0,1,2,3},{0,1,0,1},{0,0,0,1},{0,0,1,1},{0,1,2,1}};
int dx[]={1,1,-1,-1};
int dy[]= {1,-1,1,-1};
vector<vector<int>> vec(504,vector<int>(500,0));
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool out(int x,int y){
    if(x <0 || x >= N || y < 0 || y >=M) return true;
    else return false;

}

void go(int x, int y){
    for(int k=0;k<4;k++){
        for(int i=0;i<5;i++){
            int cnt =0;
            for(int j=0;j<4;j++){
             int qx = x + tetroX[i][j] * dx[k];
             int qy = y + tetroY[i][j] * dy[k];
             if(out(qx,qy)){
                 cnt = 0;
                 break;
             }
             cnt += vec[qx][qy];
            }
            ans = max(cnt,ans);
        }
        for(int i=0;i<5;i++){
            int cnt =0;
            for(int j=0;j<4;j++){
                int qx = x + tetroY[i][j] * dx[k];
                int qy = y + tetroX[i][j] * dy[k];
                if(out(qx,qy)){
                    cnt = 0;
                    break;
                }
                cnt += vec[qx][qy];
            }
            ans = max(cnt,ans);
        }
    }

}
int main(){

    fastIO();
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> vec[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            go(i,j);
        }
    }

    cout << ans <<'\n';

    return 0;
}