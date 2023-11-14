//
// Created by newbi on 2023-11-14.
//
#include <iostream>
using namespace std;

int table[104][104];    //  1 : N극, 2 : S극
int n,cnt;

void countNS(string st){
    string delim = "12";    //교착상태 문자열
    int pos=0;
    while((pos= st.find(delim))!= string::npos){    //12가 나오는 횟수 카운트
        cnt++;
        st.erase(0,pos+delim.size());
    }
}
/*
void countNS(string st){
    string delim = "12";

    for(int i=0;i<st.size()-1;i++){
        if(st.substr(i,2)==delim){
            cnt++;
        }
    }
}
두가지 방식 구현
*/

void solve(){
    for(int i=0;i<100;i++){
        string st="";
        for(int j=0;j<100;j++){
            if(table[j][i]) {   //0이 아니라면
                st += to_string(table[j][i]);
            }
        }
        countNS(st);
    }
}

void input(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cin >> table[i][j];
        }
    }
}
void reset(){
    cnt =0;
}
int main(){

    for(int i=1;i<=10;i++){
        cin >> n;
        input();
        solve();
        cout << "#"<<i<<" "<<cnt <<'\n';
        reset();
    }
    
    return 0;
}