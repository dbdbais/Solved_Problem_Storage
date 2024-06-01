//
// Created by newbi on 2024-06-01.
//
#include <iostream>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using ll = long long;
using namespace std;

ll N,M;
ll A[10004];
ll DP[10004];
//A의 누적합이 저장될 공간

void input(){
    For(i,0,N){
        cin >> A[i];
    }
}

void output(){
    For(i,0,N){
        cout << A[i] <<" ";
    }
    cout << endl;

    For(i,0,N+1){
        cout << DP[i] <<" ";
    }
    cout << endl;
}

void accum(){
    DP[1] = A[0];
    For(i,2,N+1){
        DP[i] = DP[i-1] + A[i-1];
        //누적합을 구한다.
    }
}

int solve(){
    ll cnt = 0;
    int _left = 0;
    int _right = N;

    while(_left <N){
        ll val = DP[_right] - DP[_left];
        //현재 고려된 값

        if(val == M){
            //cout << _left <<" : " << _right << endl;
            cnt++;
            _right--;
        }
        else if(val > M){
            _right--;
        }
        else if(val < M){
            _left++;
            _right = N;
            //오른쪽은 원복 한다.
        }
    }
    return cnt;

}



int main(){
    fastIO();
    cin >> N >> M;
    input();
    accum();
    cout << solve() << endl;
    //output();

    return 0;
}