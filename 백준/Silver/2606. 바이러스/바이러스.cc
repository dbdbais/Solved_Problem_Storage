//
// Created by newbi on 2023-08-11.
//
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> computer(101); // 방향성이 없는 간선
vector<bool> visited(101,false); //방문을 알릴 배열
int cnt =0; //바이러스에 걸릴 컴퓨터 수

void DFS(int virus){
    visited[virus] = true;
    for(int i=0;i<computer[virus].size();i++){
        int next = computer[virus][i];
        if(!visited[next]){
            cnt++;
            DFS(next);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,p;
    cin >> n >> p; //컴퓨터의 수, 쌍의 수
    for(int i=0;i<p;i++){
        int x,y;
        cin >> x >> y;
        computer[x].push_back(y);
        computer[y].push_back(x);
    }
    DFS(1);
    /*
    for(int i=1;i<=n;i++){
        cout<<i <<": ";
        for(auto elem: computer[i]){
            cout << elem<<" ";
        }
        cout<< endl;
    }*/
    cout<< cnt;
    return 0;
}