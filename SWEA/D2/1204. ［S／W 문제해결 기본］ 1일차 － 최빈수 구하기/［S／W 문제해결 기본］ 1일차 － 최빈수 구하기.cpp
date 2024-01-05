//
// Created by newbi on 2024-01-05.
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T,N,ans;
string st;
int cnt[101];   //카운팅 배열

void split(string s, string delim){
    int pos = 0;
    string token="";
    while((pos = s.find(delim)) != string::npos){
        token = s.substr(0,pos);
        int tmp = stoi(token);  //정수 변환
        cnt[tmp]++; //카운팅
        s.erase(0,pos+delim.length());
    }
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void reset(){
    memset(cnt,0,sizeof(cnt));
    ans = 0;
    st = "";
}

int main(){

    fastIO();

    cin >> T ;
    for(int idx =1;idx<=T;idx++){
        cin >> N;
        cin.ignore();
        getline(cin,st);
        split(st," ");
        int mx = *max_element(cnt,cnt+100); //최대 값
        for(int j = 100;j>=0;j--){
            if(cnt[j] == mx){
                ans = j;
                break;
            }
        }
        cout << "#"<<idx<<" "<<ans<<'\n';
        reset();
    }
    return 0;
}