//
// Created by newbi on 2024-06-24.
//
#include <iostream>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
using ll = long long;
using namespace std;

const int mx = 1500004;
int N;

ll DP[mx];
//최적의 값 저장
ll T[mx];
ll P[mx];

void input(){
    ll a,b;
    For(i,1,N+1){
        cin >> a >> b;
        T[i] = a;
        P[i] = b;
    }
}

void print(){
    For(i,1,N+2){
        cout << DP[i] << " ";
    }
    cout << endl;
}

void solve(){
    For(i,1,N+2){
        if(DP[i] < DP[i-1]) DP[i] = DP[i-1]; //최적의 값 업뎃

        if(i + T[i] > N+1) continue;
        //N을 넘어갔다면 컨티뉴


        int val = DP[i] + P[i];
        //최적의 값 + P 값

        if(DP[i+T[i]] < val) DP[i+T[i]] = val;
        //이 값이 더 크면 교체해준다.
        //print();
    }
    cout << DP[N+1] << endl;
}

int main(){
    fastIO();
    cin >> N;
    input();
    solve();

    return 0;
}