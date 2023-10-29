//
// Created by newbi on 2023-09-20.
//
#include<iostream>
using namespace std;
typedef long long ll;
ll dp[31][31],N;

ll go(int full,int half){
    if(full == 0 && half == 0){     //약을 다 먹었다면 1을 리턴
        return 1;
    }
    ll & ret = dp[full][half];  //이미 이전에 계산된 값이 있다면 그 값을 참조
    if(ret) {
        return ret;
    } //다음 계산에 값 리턴
    if(full > 0){   //온전한 알약을 먹는 경우의 수 더해줌
        ret += go(full-1,half+1);
    }
    if(half>0){     //반쪽 짜리 알약을 먹는 경우의 수 더해줌
        ret += go(full,half-1);
    }
    //cout << "dp[" << full << "][" << half << "] = " << ret << endl;
    return ret;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> N && N != 0){
        cout << go(N,0)<<'\n';
    }
    return 0;
}
