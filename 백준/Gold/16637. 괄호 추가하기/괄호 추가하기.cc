//
// Created by newbi on 2023-08-31.
//
#include <iostream>
#include <vector>
using namespace std;

int N, ans = -214700000;
string S;
vector<int> num;
vector<char>op;

int oper(char o, int x, int y){ //x y 연산한 것 반환

    if(o=='+'){
        return x+y;
    }
    if(o=='*'){
        return x*y;
    }
    if(o=='-'){
        return x-y;
    }
}

void go(int idx,int res){   //누적해서 재귀적으로 ans를 max값으로 업데이트
    if(idx == num.size()-1){
        ans = max(ans,res);
        return;
    }
    go(idx+1,oper(op[idx],res,num[idx+1]));    // 0~2 까지 라고 할 때 num[0]과 num[1]을 먼저 연산
    if(idx + 2 < num.size()){   //index error
        int temp =oper(op[idx+1],num[idx+1],num[idx+2]); //0~2 까지 라고 할 때 num[1]과 num[2]을 먼저 연산
        go(idx+2,oper(op[idx],res,temp));   //0~2 까지 라고 할 때 num[0]과 temp와 연산한다.
    }
    return;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for(int i=0;i< N;i++){
        if(i%2){
            op.push_back(S[i]);
        }
        else{
            num.push_back(S[i]-'0');
        }
    }
    go(0,num[0]);

    cout << ans <<'\n';

    return 0;
}