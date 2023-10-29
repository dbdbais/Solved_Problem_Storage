//
// Created by newbi on 2023-09-17.
//
#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
ll S, C, lo=1, hi=1e9,mid,ans,sm;
vector<ll> vec(1000004,0);

bool check(int val){
    ll cnt =0;
    for(int i=0;i<S;i++){
        cnt += vec[i]/ val; //사용 가능한 파의 개수 카운팅
    }
    //cout <<"cnt: "<<cnt<<endl;
    return cnt >= C;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> C;
    for(int i=0;i<S;i++){
        cin >> vec[i];
        sm += vec[i];
    }
    while(lo <= hi){
        mid = (lo + hi) / (1LL *2);
        //cout <<mid <<endl;
        if(check(mid)){
            ans = max(ans,mid); //최대 값 업데이트
            lo = mid+1;     //값을 더 증가시켜 가능한 최대 값 탐색
        }
        else{
            hi = mid -1;    //값을 감소 시킨다.
        }
    }
    cout << sm-(ans * C) <<'\n';    //라면에 넣은 파 출력

    return 0;
}