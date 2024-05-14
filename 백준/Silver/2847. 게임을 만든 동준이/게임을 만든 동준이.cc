//
// Created by newbi on 2024-05-14.
//
#include <iostream>
#include <stack>
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

using namespace std;

int N,ans;

int main(){
    fastIO();
    cin >> N;

    stack<int> stk;

    int tmp;

    For(i,0,N){
        cin >> tmp;
        stk.push(tmp);
    }

    int top = stk.top();
    stk.pop();
    while(stk.size()){
        int _next = stk.top();
        stk.pop();
        if(top <= _next){
            int diff = _next - top +1;
            ans += diff;
            top = _next - diff;
        }
        else{
            top = _next;
        }

        //cout << top <<" : " << _next << endl;
    }
    cout << ans << endl;
    return 0;
}