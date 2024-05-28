//
// Created by newbi on 2024-05-27.
//
#include <iostream>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using ll = long long;
using namespace std;

ll A, B, ans, N, idx = -1e18 ;

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

int main(){
    fastIO();
    cin >> N;
    For(i,0,N){
        cin >> A >> B;
        pq.push({A,B});
    }
    while(pq.size()){
        auto cur = pq.top();
        if(idx < cur.second){  // 의미가 있다면
            if(idx < cur.first){    //아예 안 겹친다면
                ans += cur.second-cur.first;
            }
            else{   //조금이라도 겹친다면
                ans += cur.second - idx;
            }
            idx = cur.second;
        }
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}