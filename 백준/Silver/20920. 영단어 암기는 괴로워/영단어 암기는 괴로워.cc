//
// Created by newbi on 2024-06-15.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

using namespace std;


map<string,int> cnt;
int N,M;

struct Word{
    string s;
    int len ;
    bool operator< (const Word o){
        if(cnt[s] == cnt[o.s]){
            if(len == o.len){
                return s < o.s;
            }
            return len > o.len;
        }
        else{
            return cnt[s] > cnt[o.s];
        }

    }
};
vector<Word> vec;

int main(){
    fastIO();
    cin >> N >> M;

    string s;

    For(i,0,N){
        cin >> s;
        if(s.length() >= M){
            bool isIn =false;
            if(cnt[s] == 0){
                vec.push_back({s,(int)s.length()});
            }
            cnt[s]++;
            //개수증가
        }
    }
    sort(vec.begin(),vec.end());
    for(auto elem : vec){
        cout << elem.s <<endl;
    }

    return 0;
}