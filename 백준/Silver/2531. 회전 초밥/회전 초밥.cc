//
// Created by newbi on 2024-05-15.
//
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,d,k,c;
int ans =0;
int isEat[3001];
int ipt[35001];

void solve(){
    int cnt =0;

    deque<int>dq;
    For(i,0,N+k-1){
        dq.push_back(ipt[i]);

        if(isEat[ipt[i]] == 0){
            cnt++;
        }
        isEat[ipt[i]]++;

        if(dq.size() > k){
            int fr = dq.front();
            dq.pop_front();
            isEat[fr]--;
            if(isEat[fr] == 0){
                cnt--;
            }
        }
        if(dq.size() == k){
            ans = max(ans,cnt);
        }
    }
}

int main(){
    fastIO();
    cin >> N >> d >> k >> c;

    For(i,0,N){
        cin >> ipt[i];
    }
    For(i,N,N+k-1){
        ipt[i] = ipt[i-N];
    }
    isEat[c]++;
    solve();
    cout << ans+1 << endl;

    return 0;
}