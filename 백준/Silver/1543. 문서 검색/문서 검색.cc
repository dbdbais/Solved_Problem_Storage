//
// Created by newbi on 2023-09-27.
//
#include<iostream>
using namespace std;
int cnt;
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    string st,delim;
    getline(cin,st);
    getline(cin,delim);
    while(true){
        if(st.size() < delim.size()) break;
        bool suc = true;
        for(int i = 0; i< delim.size();i++){
            if(st[i] != delim[i]){
                suc =false;
                break;
            }
        }
        if(suc){
            st.erase(0,delim.size());
            cnt++;
        }
        else{
            st.erase(0,1);
        }
        //cout <<suc << endl;
        //cout << st << endl;
    }
    cout << cnt <<'\n';
    return 0;
}