//
// Created by newbi on 2024-06-18.
//
#include <iostream>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl'\n'

using ll = unsigned long long;

using namespace std;

ll num;

bool check(){
    if(!num) return false;
    //string st = "";
    while(num){
        //값이 1 이나 0 보다 크다면 3으로 나뉘지 않는다.
        if(num%3 > 1) return false;
        num /= 3;
    }
    /*
    reverse(st.begin(),st.end());
    cout << st << endl;
     */
    return true;
}

int main(){
    fastIO();
    cin >> num;
    if(check()){
        cout <<"YES"<<endl;
    }
    else{
        cout <<"NO"<<endl;
    }
    return 0;
}