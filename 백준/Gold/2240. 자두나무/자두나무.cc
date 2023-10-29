//
// Created by newbi on 2023-09-19.
//
#include <iostream>
#include <string.h>
using namespace std;
int dp[1004][2][34], T, W , plum[1004];

int go(int idx, int tree, int move){
    if(move < 0) return -1e9;   //move가 음수로 떨어지면 제일 작은 수를 return해 max값에서 밀리게 함
    if(idx == T) return 0;      //idx가 T, 즉 주어진 시간이 다 흘렀을 때 0 반환
    auto & ret = dp[idx][tree][move];   //현재 방문한 ret 반환
    if(ret != -1) return ret;   //ret가 초기값이 아니라면 리턴한다.
    return ret = max(go(idx+1,tree ^ 1 ,move-1), go(idx+1,tree,move)) + (tree==plum[idx]-1);
    //그대로 있거나, 움직였을 때, 자두를 줍는다면 +1
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp,-1,sizeof(dp));
    cin >> T >> W;
    for(int i=0;i<T;i++){
        cin >> plum[i];
    }
    cout << max(go(0,0,W),go(0,1,W-1)) << '\n'; //1번 나무 에서 그대로 있을 경우, 2번 나무로 이동 했을 경우
    return 0;
}