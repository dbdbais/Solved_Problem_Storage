//
// Created by newbi on 2024-06-05.
//
#include <iostream>

#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int N,K,arr[1000004],ans;

void solve(){
    int _left =0;
    int _right = 0;
    int _del = 0;
    while(_left < N && _right < N){

        //다음게 짝수라면
        if(arr[_right] % 2 == 0){

            //오른쪽 증가
            int _len = _right - _left +1 - _del;
            if(ans < _len) ans = _len;
            //cout << _left <<" : " << _right << " L: "<< _len <<" D : "<< _del << endl;
            _right++;
        }//짝수아니면
        else{
            if(_del < K){
                _del++;
                int _len = _right - _left +1 - _del;
                if(ans < _len) ans = _len;
                //cout << _left <<" : " << _right << " L: "<< _len <<" D : "<< _del << endl;
                _right++;
            }
            //지울 수 있는게 없다면
            else{
                if(arr[_left] % 2 != 0){
                    _del--;
                    //홀수가 빠졌다면 감소
                }
                _left++;
                //왼쪽 하나 증가

            }
        }

        }
    cout << ans << endl;
}

int main(){
    fastIO();
    cin >> N >> K;
    For(i,0,N){
        cin >> arr[i];
    }
    solve();
    return 0;
}