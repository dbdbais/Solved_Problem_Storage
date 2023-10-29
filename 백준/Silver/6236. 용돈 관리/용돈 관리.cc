//
// Created by newbi on 2023-09-15.
//
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;   //이분탐색은 long long 박고 시작하자.
vector<ll> vec(100001,0);
ll N, M, K,lo,hi,mid, ans=1e9;

bool check(int val){
    int temp = val;
    int cnt = 1;
    for(int i=0;i< N;i++){
        temp -= vec[i];
        if(temp < 0){
            temp = val;
            cnt ++;
            temp -= vec[i];
        }
    }
    //cout << "cnt: "<<cnt << endl;
    return cnt <= M;    // 남은 금액이 그날 사용할 금액보다 많더라도 남은 금액은 통장에 집어넣고 (cnt가 M보다 작거나 같기만 하면 OK)
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> vec[i];
        hi += vec[i];   //모든 vec을 한번에 처리할 수 있는 것을 hi
        lo = max(lo,vec[i]);    //배열 안의 가장 큰 값을 lo
    }
    while(lo <= hi){
        mid = (hi+lo)/2;
        //cout << "mid: "<<mid << endl;
        if(check(mid)){
            hi= mid-1;
            ans = min(ans,mid);
        }
        else{
            lo = mid+1;
        }
    }
    cout <<ans<<'\n';

    return 0;
}