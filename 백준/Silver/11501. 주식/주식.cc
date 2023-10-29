//
// Created by newbi on 2023-09-29.
//
#include<iostream>
#include<vector>
using namespace std;
int T, N;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();

    cin >> T;
    for(int i=0;i<T;i++){
        long long res =0;   // long long으로 바꾸어 더 넓은 값을 담을 수 있게 수정
        int mx =0;
        cin >> N;
        vector<int> vec(N,0);

        for(int j=0;j<N;j++){
            cin >>vec[j];
        }
        for(int k = N-1;k>=0;k--){
            mx = max(mx,vec[k]);    //뒤에서 부터 연산을 들어간다.
            res += mx - vec[k];     //최댓값 계산
        }
        cout << res << '\n';
    }
    return 0;
}