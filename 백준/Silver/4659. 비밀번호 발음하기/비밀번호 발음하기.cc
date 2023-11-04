//
// Created by newbi on 2023-11-04.
//
#include <iostream>

using namespace std;
string s;

bool check(){
    bool ret = false;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'|| s[i] == 'u' ){
            ret = true;
        }
    }
    return ret;
}

bool isNotCont(){
    int acnt = 0;
    int bcnt = 0;
    bool ret =true;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'|| s[i] == 'u' ){
            acnt++;
            bcnt = 0;
        }
        else{   //자음이라면
            acnt = 0;
            bcnt++;
        }
        if(acnt >= 3 || bcnt >= 3){
            ret = false;
            break;
        }
    }

    return ret;
}

bool notTwice(){
    bool ret = true;
    for(int i=0;i<s.size()-1;i++){
        if(s[i] == 'e' || s[i] == 'o'){  //e나 o라면
            continue;
        }
        if(s[i] == s[i+1]){
            ret = false;
            break;
        }
    }
    return ret;
}

void solve(){
    if(check() && isNotCont() && notTwice()){
        cout <<"<"<<s<<"> is acceptable."<<'\n';
    }
    else{
        cout <<"<"<<s<<"> is not acceptable."<<'\n';
    }
}

int main(){
    while(cin>>s && s!="end"){
        solve();
    }
    return 0;
}