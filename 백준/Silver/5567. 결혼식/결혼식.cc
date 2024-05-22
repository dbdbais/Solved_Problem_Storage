//
// Created by newbi on 2024-05-21.
//
#include <iostream>
#include <vector>

using namespace std;
#define fastIO() ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

vector<int>adj[502];
bool visited[502];
int N,M,a,b,cnt;

void solve(){
    visited[1] = true;
    vector<int> adAdj;
    for(int ad : adj[1]){
        if(visited[ad]) continue;
        cnt++;
        visited[ad] = true;
        adAdj.push_back(ad);
    }
    for(int adad : adAdj){
        for(int ae : adj[adad]){
            if(visited[ae]) continue;
            cnt++;
            visited[ae] = true;
        }
    }
}

int main(){
    fastIO();
    cin >> N >> M;
    For(i,0,M){
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve();
    cout << cnt << endl;
    return 0;
}