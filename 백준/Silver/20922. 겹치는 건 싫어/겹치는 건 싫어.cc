//
// Created by newbi on 2024-06-02.
//
#include <iostream>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
using namespace std;

int N,K,ans;
int cnt[100004];
int a[200004];

void printCnt(){
    For(i,1,10){
        cout << cnt[i] <<" ";
    }
    cout << endl;
}

void solve(){
    int _left = 0;
    int _right = _left;
    while(_left < N){
        //cout << "left : "<< _left <<" right : "<< _right << endl;
        //printCnt();
        //right가 갈 수 있다면
        if(_right < N){
            if(cnt[a[_right]] < K){
                cnt[a[_right]]++;
                _right++;
                //오른쪽 포인터 하나 증가
            }
            else{
                //갈 수 없다면
                cnt[a[_left]]--;
                //카운팅 하나 감소 하고
                _left++;
                //왼쪽 포인터 땡겨온다
            }
        }
        else{
            _left++;
        }
        if( (_right - _left) > ans){
            ans = _right - _left;
            //최대 값 업데이트
        }
    }

}

int main(){
    fastIO();
    cin >> N >> K;
    For(i,0,N){
        cin >> a[i];
    }
    solve();
    cout << ans << endl;
    return 0;
}