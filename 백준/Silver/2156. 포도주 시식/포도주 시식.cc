//
// Created by newbi on 2023-11-08.
//
#include <iostream>
#include <algorithm>
using namespace std;
int N, ans;
int dp[10004][3]; // n번째, 몇 번 연속 선택?(0 ~ 2)
int arr[10004];

void solve(){
    dp[1][1] = arr[1];
    for(int i=2;i<=N;i++){
        int tmp = max(dp[i-1][1],dp[i-1][2]);  //이번에 선택안한다면 전의 1번째나 2번째 중에 큰걸 임시저장
        if(tmp > dp[i-1][0]){   //이전에 아무것도 선택안한 것보다 크다면
            dp[i][0] = tmp; //대입
        }
        else{
            dp[i][0] = dp[i-1][0];  //전의 값 그대로 들고온다 (이번 것은 버린다)
        }
        dp[i][1] = dp[i-1][0] + arr[i]; //첫번째 연속 선택한다면 i-1번째 선택 안한 메모제이션과 지금 값을 더한다.
        dp[i][2] = dp[i-1][1] + arr[i]; // 두번째 연속 선택
    }
    ans = max({dp[N][0],dp[N][1],dp[N][2]});    //최종 가장 많은 수 구하기
}
void print(){
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            cout <<dp[i][j]<<" ";
        }
        cout <<endl;
    }
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    solve();
    //print(); //Debug
    cout << ans <<'\n';
    return 0;
}