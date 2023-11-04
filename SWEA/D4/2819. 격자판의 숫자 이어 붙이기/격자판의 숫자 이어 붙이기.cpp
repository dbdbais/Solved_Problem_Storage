//
// Created by newbi on 2023-11-04.
//
#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int arr[5][5];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int T;
set<int> ans;
bool out(int x,int y){
    return (x <0 || y <0 || x >=4 || y >= 4);
}

void input(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> arr[i][j];
        }
    }
}
void reset(){
    memset(arr,0,sizeof(arr));
    ans.clear();
}

void DFS(int x,int y,string s){
    if(s.size() == 7){
        ans.insert(stoi(s));
        return;
    }
    for(int i=0;i<4;i++){
        int qx = x + dx[i];
        int qy = y + dy[i];

        if(out(qx,qy)) continue;    //벗어나면 다음으로
        DFS(qx,qy,s+to_string(arr[qx][qy]));   //string append해서 다음으로 넘김
    }
    return;

}

void solve(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            DFS(i,j, to_string(arr[i][j]));
        }
    }

}
int main(){
    cin >> T;

    for(int i=1;i<=T;i++){
        input();
        solve();
        cout <<"#"<<i<<" "<<ans.size()<<'\n';
        reset();
    }

    return 0;
}