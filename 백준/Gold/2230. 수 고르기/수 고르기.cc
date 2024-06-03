//
// Created by newbi on 2024-06-03.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using ll = long long;
using namespace std;

ll N,M,ans = 1e18;
vector<ll> A;

void solve(){
    sort(A.begin(),A.end());
    //정렬하고
    int _left = 0;
    int _right = 0;

    while(_left < N){
        ll val = A[_right] - A[_left];
        // val의 차이 값

        //cout << "lft : "<< _left <<" rgt : "<< _right <<" val : " << val << endl;

        //조건을 만족하면
        if(val >= M){
            //cout << "isOK" << endl;
            ans = min(ans,val);
            //최소 값으로 업데이트
            _left++;
            //왼쪽 증가시킨다. 차를 감소
        }
        //조건을 만족하지 않으면 차를 늘린다.
        else{
            //차를 늘린다.
            if(N-1 > _right){
                _right++;
            }
            else{
                _left++;
            }
        }

    }
}

int main(){
    fastIO();
    ll tmp;
    cin >> N >> M;
    For(i,0,N){
        cin >> tmp;
        A.push_back(tmp);
    }
    solve();
    cout << ans << endl;
    return 0;
}