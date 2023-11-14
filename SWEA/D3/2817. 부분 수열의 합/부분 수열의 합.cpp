//
// Created by newbi on 2023-11-14.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int T,N,K,cnt;
int arr[21];

void input(){
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
}

void combi(int start, vector<int> v){
    int sm =0;
    for(auto idx : v){  //현재 벡터의 인덱스의 값
        sm += arr[idx];
    }
    if(sm > K){
        return; //합이 K보다 크다면 이전의 경우로 리턴
    }
    else if(sm == K){
        cnt++;  //K와 같다면 증가
        return;
    }
    for(int i = start+1;i < N; i++){
        v.push_back(i);
        combi(i,v);
        v.pop_back();
    }
    return;
}

void solve(){
        vector<int>v;
        combi(-1,v);  //i의 길이를 가지는 부분수열 전부 생성

}
void reset(){
    memset(arr,0,sizeof(arr));
    cnt =0;
}

int main(){

    cin >> T;

    for(int i=1;i<=T;i++){
        cin >> N >> K;
        input();
        solve();
        cout << "#"<<i<<" "<<cnt <<'\n';
        reset();
    }

    return 0;
}
