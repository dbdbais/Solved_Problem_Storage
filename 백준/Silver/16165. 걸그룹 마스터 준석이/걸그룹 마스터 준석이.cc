//
// Created by newbi on 2024-06-04.
//
#include<iostream>
#include <map>
#include <vector>
#include <algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int N,M;
map<string,string> ggName;
map<string,vector<string>> ggroup;
int main(){
    fastIO();
    string _name;
    int num;
    cin >> N >> M;
    For(i,0,N){
        cin >> _name >> num;
        string memName;
        vector<string> tmpVec;
        For(n,0,num){
            cin >> memName;
            ggName.insert({memName,_name});
            tmpVec.push_back(memName);
        }
        sort(tmpVec.begin(),tmpVec.end());
        ggroup.insert({_name,tmpVec});
    }
    int _type;
    string qzName;
    For(j,0,M){
        cin >> qzName >> _type;
        if(_type == 0){
            auto ans = ggroup[qzName];
            for(auto m : ans){
                cout << m << endl;
            }
        }
        else{
            cout << ggName[qzName] <<endl;
        }
    }

    return 0;
}