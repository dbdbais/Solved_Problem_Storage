//
// Created by newbi on 2023-09-16.
//
#include <iostream>
using namespace std;
typedef long long ll;   //10억까지의 수를 표현하기 때문에 long long 사용
ll x,y,res,lo=1,hi=1e9,mid,ans=1e9+1;

bool check(ll val){
    ll temp = (y+val)*100 / (x+val);    //val 만큼 더한 후의 퍼센트
    return temp != res; // 퍼센트가 달라졌는지 T/F
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y;
    res = y * 100 / x; //퍼센트 정수형으로 체크
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(mid)){
            ans = min(ans,mid);
            hi = mid-1;
        }
        else{
            lo = mid +1;
        }
    }
    if(ans > 1e9){
        cout << -1 <<'\n';
    }
    else{
        cout << ans <<'\n';
    }

    return 0;
}