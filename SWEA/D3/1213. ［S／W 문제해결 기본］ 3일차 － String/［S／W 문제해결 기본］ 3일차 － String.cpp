//
// Created by newbi on 2023-11-17.
//
#include <iostream>

using namespace std;
int n, cnt;
string s;

void solve(string st){
    int pos =0;
    while((pos =st.find(s))!= string::npos){    //찾은 문자열 위치 반환
        cnt ++;
        st.erase(0,pos+s.size());   //0부터 현재 위치까지 삭제
    }
}

void reset(){
    cnt =0;
}

int main(){
    string st;
    for(int i=1;i<=10;i++){
        cin >>n >> s >> st;
        solve(st);
        cout <<"#"<<i<<" "<<cnt <<'\n';
        reset();
    }
}