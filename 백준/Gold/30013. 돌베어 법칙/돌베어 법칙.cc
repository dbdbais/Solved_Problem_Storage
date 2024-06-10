//
// Created by newbi on 2024-06-10.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,res = 1e9;

int check(int term, vector<char> s){
    int cnt = 0;
    For(i,0,N){
        if(s[i] == '#'){
            s[i] = '.';
            int idx = i + term;
            while(idx < N){
                if(s[idx] == '.') break;
                s[idx] = '.';
                idx += term;
            }
            cnt++;
        }
    }
    //cout<<"cnt: " << cnt << endl;
    return cnt;
}


int main(){
    fastIO();
    string s;
    cin >> N >> s;
    vector<char>sound(s.begin(),s.end());
    For(term,1,N+1){
        res = min(res, check(term,sound));
    }
    cout << res << endl;

    return 0;
}