//
// Created by newbi on 2024-06-08.
//
#include<iostream>
#include <vector>
#include <map>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int startHR,startMN,endHR,endMN,dHR,dMN;
//이전
map<string,bool> pChat;
//이후
map<string,bool> aChat;
int ans;
string S,E,Q;
vector<int> split(string st,string delim){
    vector<int> ret;
    int pos = 0;
    string token;
    while((pos = st.find(delim))!= string::npos){
        token = st.substr(0,pos);
        ret.push_back(stoi(token));
        st.erase(0,pos+delim.length());
    }
    ret.push_back(stoi(st));
    return ret;
}

int main(){
    fastIO();
    cin >> S >> E >> Q;
    auto sv = split(S,":");
    auto ev = split(E,":");
    auto dv = split(Q,":");
    startHR = sv[0]; startMN = sv[1]; endHR = ev[0]; endMN = ev[1]; dHR = dv[0]; dMN = dv[1];
    string tm, _name;
    int cHR,cMN;
    while(1){
        cin>>tm>>_name;
        if(cin.eof()) break;
        auto iv = split(tm,":");
        cHR = iv[0]; cMN = iv[1];

        //스트리밍이 끝난 이후라면 SKIP
        if(dHR < cHR || (dHR == cHR && dMN < cMN)) continue;

        if(cHR < startHR || ((cHR == startHR) && (cMN <= startMN))){
            pChat.insert({_name,true});
        }
        else if(cHR> endHR || ((cHR == endHR) && (cMN >= endMN))){
            aChat.insert({_name,true});
        }
    }
    /*
    for(auto elem : pChat){
        cout << elem.first << " ";
    }
    cout << endl;

    for(auto elem : aChat){
        cout << elem.first << " ";
    }
    cout << endl;
     */

    //끝난 챗에 있는지 찾기
    for(auto elem : pChat){
        if(aChat.find(elem.first)!= aChat.end()){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}