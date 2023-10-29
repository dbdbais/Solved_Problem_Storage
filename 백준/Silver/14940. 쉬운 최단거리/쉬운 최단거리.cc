//
// Created by newbi on 2023-08-10.
//

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int count =0;
queue<pair<int,int>> q;
void BFS(int n,int m, vector<vector<int>>& visited, vector<vector<int>>& vec){

    while(!q.empty()){
        auto cord = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int qx = cord.first+ dx[i];
            int qy = cord.second + dy[i];
           if( (qx >=0 && qx< n) &&(qy>=0 && qy<m)){    //맵을 벗어나지 않고
               if(visited[qx][qy]==0 && vec[qx][qy] !=0 && vec[qx][qy] !=2) {   //유효한 값이라면
                   visited[qx][qy] = visited[cord.first][cord.second] + 1;
                   q.push(make_pair(qx, qy));
               }
           }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> vec(n,vector<int>(m,0));
    vector<vector<int>> visited(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> vec[i][j];
            if(vec[i][j] == 0){
                visited[i][j] = -1;
            }
        }
    }
    int startX;
    int startY;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]==2) {
                startX =i;
                startY = j;
                q.push(make_pair(startX, startY));
                BFS(n,m,visited,vec);
                break;
            }
        }
    }
    visited[startX][startY] = -1;
    for( auto row: visited){
        for(auto elem: row){
            if(elem == -1){
                cout<< 0 <<" ";
            }
            else if(elem == 0){
                cout <<-1<<" ";
            }
            else {
                cout << elem << " ";
            }
        }
        cout<< '\n';
    }

    return 0;
}