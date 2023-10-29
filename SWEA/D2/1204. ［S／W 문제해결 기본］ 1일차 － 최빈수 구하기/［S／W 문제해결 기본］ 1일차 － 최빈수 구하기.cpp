//
// Created by newbi on 2023-10-27.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;
int T,N,high,ans;
vector<int> std_cnt(1004,0);

void split(string input,string delim){
    string token = "";
    int conv;
    long long pos =0;
    while((pos = input.find(delim)) != string::npos){
        token = input.substr(0,pos);
        conv = stoi(token);
        if(high < conv) high =conv;
        std_cnt[conv]++;
        input.erase(0,pos+delim.length());
    }
}


void solve(){
    auto mx = max_element(std_cnt.begin(),std_cnt.end());
    for(int i=high;i>=0;i--){
        if(std_cnt[i] == *mx){
            ans = i;
            break;
        }
    }
}
void reset(){
    high = 0;
    ans =0;
    fill(std_cnt.begin(),std_cnt.end(),0);
}


int main(){
    int idx=0;
    string ipt;

    cin >> T;
    while(T){
        idx++;
        cin >> N;
        string buffer;
        getline(cin,buffer);    //버퍼 해결

        getline(cin,ipt);
        split(ipt," ");
        solve();
        cout <<"#"<<idx<<" "<<ans<<'\n';
        reset();
        T--;
    }

    return 0;
}