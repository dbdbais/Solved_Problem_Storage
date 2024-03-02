//
// Created by newbi on 2024-03-02.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T,N,M;
vector<int> bigger[502];
vector<int> smaller[502];
bool visited[502];
int bcnt = 0;
int scnt = 0;
void searchBig(int start){
    visited[start] = true;
    for(int elem : bigger[start]){
        if(visited[elem]) continue;
        bcnt++;
        searchBig(elem);
    }
}
void searchSmall(int start){
    visited[start] = true;
    for(int elem : smaller[start]){
        if(visited[elem]) continue;
        scnt++;
        searchSmall(elem);
    }
}

void reset(){
    For(i,1,N+1){
        bigger[i].clear();
        smaller[i].clear();
    }
}

int main(){
    fastIO();
    cin >> T;
    For(t,1,T+1){
        cin >> N >> M;
        int a,b;
        For(i,0,M){
            cin >> a >> b;
            bigger[a].push_back(b);
            smaller[b].push_back(a);
        }
        int ans =0;
        For(i,1,N+1){
            memset(visited,false,sizeof(visited));
            bcnt =0;
            searchBig(i);
            memset(visited,false,sizeof(visited));
            scnt = 0;
            searchSmall(i);
            if(bcnt+scnt == N-1) ans++;
        }

        cout <<"#"<<t<<" "<<ans<<endl;
        reset();
    }




    return 0;
}