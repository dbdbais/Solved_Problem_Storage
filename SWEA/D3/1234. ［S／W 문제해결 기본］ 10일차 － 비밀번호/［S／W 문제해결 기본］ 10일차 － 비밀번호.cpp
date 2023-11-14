//
// Created by newbi on 2023-11-14.
//
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n;
string st,ans;
void solve(){
    stack<char> stk;
    for(int i=0;i<n;i++){
        if(stk.empty() || st[i] != stk.top()) { //스택이 비었거나, 지금 넣으려는 문자가 tos와 같지 않다면
            stk.push(st[i]);
        }
        else{   // 지금 문자와 tos가 같다면
           stk.pop();
        }
    }
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(),ans.end());
}
void reset(){
    ans ="";
    st="";
}
int main(){
    for(int i=1;i<=10;i++){
        cin >>n >>st;
        solve();
        cout <<"#"<<i<<" ";
        cout <<ans <<'\n';
        reset();
    }
    return 0;
}