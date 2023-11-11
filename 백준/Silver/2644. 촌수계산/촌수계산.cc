//
// Created by newbi on 2023-11-11.
//
#include <iostream>
using namespace std;
int N,M,ans = -1,fst,lst;
int arr[103][103];
bool visited[103];
bool ansFound;

void DFS(int start,int target, int cnt){
    visited[start] = true;
    if(start == target){
        ans = cnt;
        ansFound = true;
        return;
    }
    for(int i=1;i<=N;i++){
        if(!arr[start][i]) continue;
        if(arr[start][i] && visited[i]) continue;
        else{
            DFS(i,target,cnt+1);
            if(ansFound) break;
        }
    }
}

int main(){
    int a,b;
    cin >> N;
    cin >> fst >> lst >> M;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    visited[fst] = true;
    DFS(fst,lst,0);
    cout << ans <<'\n';
    return 0;
}
