//
// Created by newbi on 2023-08-24.
//
#include<iostream>
#include<stack>
using namespace std;
int cnt;
void solve(string st){
    stack<char> stack;
    for (auto elem : st){
        if (!stack.empty() && stack.top() == elem)
            stack.pop();
        else
            stack.push(elem);
    }
    if(stack.empty())
        cnt++;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
        solve(temp);
    }
    cout << cnt <<'\n';

    return 0;
}
