//
// Created by newbi on 2023-08-11.
//
#include<iostream>
using namespace std;
long ans = 0;

void recursive(int N, int r, int c){
    if(N == 0) return;
    int length = 1 << N;
    int half = length / 2;
    if(r /half ==0 && c/half ==0){
        ans += half*half*0;
        recursive(N-1,r % half,c % half);
    }//반을 넘지 못한다면 즉, 1사분면에 위치
    else if(r/half ==0 && c/half ==1){
        ans += half*half*1;
        recursive(N-1,r % half,c % half);
    } // 2사분면 위치
    else if(r/half ==1 && c/half == 0){
        ans += half*half*2;
        recursive(N-1,r % half,c % half);
    }// 3사분면 위치
    else if(r/half == 1 && c/half ==1 ){
        ans += half*half*3;
        recursive(N-1,r % half,c % half);
    }// 4사분면 위치
}

int main(){
    int N, r, c;
    cin >> N >> r >> c;
    recursive(N,r,c);
    cout << ans;
    return 0;
}