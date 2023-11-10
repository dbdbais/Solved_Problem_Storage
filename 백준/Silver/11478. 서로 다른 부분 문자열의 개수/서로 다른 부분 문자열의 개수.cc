//
// Created by newbi on 2023-11-10.
//
#include <iostream>
#include <set>
using namespace std;
set<string> ans;
string s;

void solve(){
    int n = s.size();
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            if(j+i > n) continue;   //문자열을 초과할 시 SKIP
            string tmp = s.substr(j,i); //s를 i의 길이만큼 쪼갠다.
            // cout << tmp<<endl;
            ans.insert(tmp);
        }
    }


}

int main(){
    cin >> s;
    solve();

    cout << ans.size()<<'\n';
    return 0;
}