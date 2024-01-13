//
// Created by newbi on 2024-01-13.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;

int ipt[10];
bool visited[10];
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void print(vector<int> v){
    for(auto elem : v){
        cout << elem<<" ";
    }
    cout <<'\n';
}

void solve(vector<int> v){
    if(v.size() == M){  //M개라면 모두 출력
        print(v);
        return;
    }

    for(int i = 1;i<= N; i++){
        if(!visited[i]){    //방문하지 않았다면
            visited[i] = true;
            v.push_back(ipt[i]);
            solve(v);
            v.pop_back();
            visited[i] = false;
        }
    }
    return;
}

int main(){

    fastIO();
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >>ipt[i];
    }
    sort(ipt+1,ipt+N+1);    //N까지 정렬한다.

    vector<int> v;
    solve(v);

    return 0;
}
