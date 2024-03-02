//
// Created by newbi on 2024-03-02.
//
#include <iostream>
#include <vector>
#include <queue>

#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M;
vector<int> adj[32001];
int cnt[32001];
int main(){
    fastIO();
    cin >> N >> M;
    int a,b;
    For(i,0,M){
        cin >> a >> b;
        adj[a].push_back(b);
        cnt[b]++;
    }
    queue<int>q;

    while(q.size() != N){
        for(int i=1;i<=N;i++){
            if(cnt[i] == 0){
                q.push(i);
                for(int ad : adj[i]){
                    cnt[ad]--;
                }
                cnt[i] = -1;
            }
        }
    }

    while(q.size()){
        cout << q.front() << " ";
        q.pop();
    }
    cout <<endl;



    return 0;
}