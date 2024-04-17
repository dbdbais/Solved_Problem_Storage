//
// Created by newbi on 2024-04-17.
//
#include <bits/stdc++.h>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int F,S,G,U,D;
const int mx = 1000001;
const int INF = 1e9;
int arr[mx];

bool out(int x){
    return x <= 0 || x > F;
}

void solve(){
    fill(&arr[0],&arr[0]+mx,INF);
    arr[S] = 0;

    queue<pair<int,int>> q;
    q.push({0,S});

    while(q.size()){
        auto cur = q.front(); q.pop();
        int now = cur.second;
        int val = cur.first;
        //cout << now <<" : " << val << endl;
        int uX = now + U;
        int dX = now - D;

        if(!out(uX)){
            if(arr[uX] > val+1){
                arr[uX] = val + 1;
                q.push({val+1,uX});
            }
        }
        if(!out(dX)){
            if(arr[dX] > val+1){
                arr[dX] = val + 1;
                q.push({val+1,dX});
            }
        }
    }
}

int main(){
    fastIO();
    cin >> F >> S >> G >> U >> D;

    solve();
    if(arr[G] == INF){
        cout << "use the stairs"<<endl;
    }
    else{
        cout << arr[G] << endl;
    }
    return 0;
}