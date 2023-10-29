//
// Created by newbi on 2023-09-22.
//
#include<iostream>
#include<vector>
using namespace std;
int N,M;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    double dTmp;

    while(true){
        vector<int> dp(10004,0);    //dp배열 반복마다 선언
        cin >> N >> dTmp;
        M = int(dTmp * 100+0.5);    //실수형을 정수형으로 변환
        if(!N) break;    // 0이 들어올 경우 반복문 종료
        int kcal, price;
        for(int i=0;i<N;i++){
            cin >> kcal >> dTmp;
            price = int(dTmp * 100+0.5);
            for(int j=price;j<=M;j++){
                    dp[j] = max(dp[j],dp[j - price] + kcal);    //현재 dp의 값과 전에 만든 값과 지금 kcal 더했을 때 큰 값 메모제이션
                //cout << dp[j]<<" ";
            }
            //cout <<endl;
        }
        cout << dp[M]<<'\n';    //상근이의 돈 M으로 누적된 dp배열 값 출력
    }

    return 0;
}