//
// Created by newbi on 2024-01-13.
//
#include <iostream>
#include <vector>

using namespace std;
int N,M;

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

void solve(int idx,vector<int> v){
    if(v.size() == M){  //M개라면 모두 출력
        print(v);
        return;
    }
    for(int i = idx+1;i<= N; i++){
        v.push_back(i);
        solve(i,v);
        v.pop_back();
    }
}

int main(){

    fastIO();
    cin >> N >> M;
    vector<int> v;
    solve(0,v);

    return 0;
}
