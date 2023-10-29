//
// Created by newbi on 2023-08-12.
//

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int dx[] ={0,0,-1,1};
int dy[] ={1,-1,0,0};
int ans = 0 ;
void DFS(pair<int,int>cord,vector<vector<char>> & campus,vector<vector<bool>> & visited,int n,int m){
    int x = cord.first;
    int y = cord.second;
    for(int i=0;i<4;i++){
        int qx= x + dx[i];
        int qy= y + dy[i];

        if((qx>=0 && qx< n) && (qy>=0 && qy < m) && visited[qx][qy] ==false){
            if(campus[qx][qy]=='P'){
                ans +=1;
            }
            else if(campus[qx][qy] =='X')
                continue;
            visited[qx][qy] = true;
            DFS(make_pair(qx,qy),campus,visited,n,m);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<vector<char>> campus(n,vector<char>(m));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    string input;
    pair<int, int> cord;
    for(int i=0;i<n;i++){
        cin>> input;
        for(int j=0;j<m;j++){
            campus[i][j]= input[j];
            if(input[j]=='I') {
                cord = make_pair(i, j);
                visited[i][j] = true;
            }
        }
    }

    DFS(cord, campus, visited, n, m);

    /*for(auto row: visited){
        for(auto elem: row){
            cout<< elem<<" ";
        }
        cout<<endl;
    }*/

    if(ans ==0){
        cout<<"TT";
    }
    else{
        cout<< ans;
    }

    return 0;
}