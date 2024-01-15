//
// Created by newbi on 2024-01-15.
//
#include <iostream>
#include <stack>
using namespace std;

string st ,ans;
stack<char>stk;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    for(int i=0;i<st.size();i++){
        char elem = st[i];

        if(elem == '('){    // 여는 괄호는 그냥 push
            stk.push(elem);
        }
        else if(elem == ')'){
            while(stk.size()){
                char prev = stk.top();
                stk.pop();
                if(prev == '(') {   // '(' 만날 때 까지 전부 pop
                    break;
                }
                ans += prev;
            }
        }
        else if(elem == '+' || elem =='-'){
            if(stk.size()){ //우선순위가 같거나 크면 전부 pop
                while(stk.size()){
                    char prev =stk.top();
                    if(prev == '(') break;  //우선순위가 작은 것 만나면 break
                    ans += prev;
                    stk.pop();
                }
            }
            stk.push(elem);
        }
        else if(elem == '*' || elem == '/'){
            if(stk.size()){
                while(stk.size()){
                    char prev = stk.top();
                    if(prev =='*' || prev == '/'){  //우선순위가 같으면 전부 pop
                        ans += prev;    //*
                        stk.pop();  //탑 비우고
                    }
                    else{
                        break;
                    }
                }
            }
            stk.push(elem); //지금 값 넣는다.

        }
        else{   //그냥 문자가 들어올 때
            ans += elem;
        }

    }
    while(stk.size()){
        ans += stk.top();stk.pop();
    }

}


int main(){

    fastIO();

    cin >> st;
    solve();
    cout << ans <<'\n';

    return 0;
}