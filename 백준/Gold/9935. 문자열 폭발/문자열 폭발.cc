//
// Created by newbi on 2023-09-10.
//
#include<iostream>
#include <stack>
#include <algorithm>
using namespace std;
stack<char> stk;
string input,bomb,res="";
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input >> bomb;

    for(auto c : input){
        stk.push(c);    //스택에 계속 push
        if(stk.size() >= bomb.size()){  //폭탄의 사이즈와 같거나 크다면
            if(stk.top() == bomb[bomb.size()-1]){   //tos와 폭발문자의 마지막 단어가 같다면
                string temp= "";
                for(int i=0;i<bomb.size();i++){ //꺼내서 temp에 concat
                    temp += stk.top();
                    stk.pop();
                }
                reverse(temp.begin(),temp.end());   //뒤집어서 맞는 지 확인
                if(temp != bomb){   //아니라면 다시 꺼낸것을 스택에 넣어준다.(원복)
                    for(auto t : temp) {
                        stk.push(t);
                    }
                }
            }
        }
    }

    if(stk.empty()){    //전부 폭발했다면
        cout << "FRULA"<<'\n';
    }
    else{
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        cout << res << '\n';
    }

    return 0;
}