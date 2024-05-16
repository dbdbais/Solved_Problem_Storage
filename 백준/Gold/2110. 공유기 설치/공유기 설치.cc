//
// Created by newbi on 2024-05-16.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
using ll = long long;
using namespace std;

vector<ll> v;
int N,C;
ll ans;

void solve(){
    sort(v.begin(),v.end());

    int _left =1;
    int _right = v[N-1];

    while(_left <= _right){
        int mid = (_left+_right) / 2;
        //cout << mid << endl;
        int cnt = 1;

        int _start = v[0];
        //첫 시작

        for(int i=1;i<N;i++){

            int _end = v[i];
            //현재 공유기 위치 가져옴

            //공유기 사이가 설정한 mid 넘는지 확인
            if(_end - _start >= mid){
                cnt++;
                _start = _end;
                //다음 공유기를 이전 공유기로 변경
            }
        }
        // 만족한다면
        if(cnt >= C){
            //cout << "updated" << endl;
            ans = mid;  //최댓값 갱신
            _left = mid+1;
        }
        //만족하지 않는다면
        else{
            _right = mid -1;
            //값을 줄인다
        }
    }
}

int main(){
    fastIO();
    cin >> N >> C;
    ll tmp;
    For(i,0,N){
        cin >> tmp;
        v.push_back(tmp);
    }

    solve();
    cout << ans << endl;
}