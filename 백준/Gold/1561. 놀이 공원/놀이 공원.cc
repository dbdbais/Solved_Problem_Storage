//
// Created by newbi on 2023-09-18.
//
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> play(10004,0);
ll N,M,lo=1,mid,sm,hi = 60000000004, ret;

bool check(ll val){
    ll temp = M; //한명씩 다 태웠다고 가정
    for(int i =1;i<= M;i++){
        temp += val / play[i];
    }
    return temp >=N;    //덩어리 채로 구한다.
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> play[i];
    }
    if(N <= M){ //놀이기구가 사람 수 보다 많은 경우
        cout << N;
        return 0;
    }

    while(lo <= hi){
        mid = (hi+lo) / 2;
        if(check(mid)){
            //cout <<"mid: "<< mid << endl;
            ret = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
        ll temp = M;    //초기 이용자 수
        for(int i =1;i<= M;i++){
            temp += (ret-1)/play[i];    //ret-1분일 때 놀이공원 이용자 수 구한다.
        }
        for(int i= 1;i<=M;i++){
            if(ret % play[i] == 0) temp++; // ret분 일 때 딱 놀이기구가 빈다면(나누어 떨어진다면) 다음 사용자를 태운다
            if(temp == N){
                cout << i <<'\n';
                break;
            }
        }

    return 0;
}