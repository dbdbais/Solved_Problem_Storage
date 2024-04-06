//
// Created by newbi on 2024-04-06.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M,tmp;
int input[10];
vector<int> vec;

void combi(int start,int depth){

    if(depth == M){
        For(i,0,M){
            cout << input[i] <<" ";
        }
        cout << endl;
        return;
    }
    bool visited[10001];
    memset(visited,false,sizeof(visited));

    for(int i=start+1;i<vec.size();i++){
        if(visited[vec[i]]) continue;   //같은 레벨에서 방문한게 있다면
        input[depth] = vec[i];
        visited[vec[i]] = true;
        combi(i,depth+1);
    }

}

int main(){
    fastIO();
    cin >> N >> M;
    For(i,0,N){
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(),vec.end());

    combi(-1,0);

    return 0;
}