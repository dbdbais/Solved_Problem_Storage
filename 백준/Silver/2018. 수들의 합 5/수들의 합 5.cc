//
// Created by newbi on 2024-06-25.
//
#include <iostream>

#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int N,ans;



void solve(){
    int _left =1;
    int _right = _left;
    int sm = 1;
    while(_left <= N){
        //cout << _left <<" ~ "<<_right << endl;
        //cout << sm << endl;
        //찾았을 경우
        if(sm == N){
            //cout << "FOUND" << endl;
            //cout << _left << _right << endl;
            ans++;
            _left++;
            //왼쪽거로 하고
            _right = _left;
            sm = _left;
            //오른쪽 하나 위로
        }
        //N보다 클 경우
        else if(sm > N){
            _left++;
            sm = _left;
            _right = _left;
        }
        //N보다 작을 경우
        else{
            _right++;
            sm += _right;
            //오른쪽 늘림
        }
    }
}

int main(){
    fastIO();
    cin >> N;
    //print();
    solve();
    cout << ans << endl;
    return 0;
}