//
// Created by newbi on 2023-10-09.
//
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int N,C;
map<int,int> mp, seq;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool compare(pair<int,int> a, pair<int,int>b){
        if(a.second == b.second){
            return seq[a.first] < seq[b.first];
        }
        else{
            return a.second > b.second;
        }
}
int main(){
    fastIO();

    cin >> N >> C;
    int tmp;
    for(int i=0;i<N;i++){
        cin >>tmp;
        if(mp[tmp]!=0){
            mp[tmp] = mp[tmp]+1;
        }
        else{
            seq[tmp] = i+1;
            mp[tmp] = 1;
        }
    }
    vector<pair<int,int>> vec(mp.begin(),mp.end());
    sort(vec.begin(),vec.end(),compare);

    for(auto elem: vec){
        for(int i=0;i<elem.second;i++){
            cout << elem.first <<" ";
        }
    }
    
    return 0;
}