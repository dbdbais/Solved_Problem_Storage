//
// Created by newbi on 2023-08-24.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> cnt (26,0);
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    for(char elem: s){
        cnt[elem-'A']++;
    }
    char odd;
    int temp = 0 ;
    string ans;
    for(int i=cnt.size()-1;i>=0;i--){
        if(temp > 1){
            break;
        }
        if(cnt[i]){
            if(cnt[i] % 2 == 1){ //홀수가 나온다면
                odd = 'A'+i;
                temp ++;
                cnt[i]--;
            }
            for(int j=0;j<cnt[i];j+=2){
                ans = char('A'+i) + ans;
                ans += char('A'+i);
            }
        }
    }
    if(temp > 1){
        cout<<"I'm Sorry Hansoo"<<'\n';
    }
    else{
        if(odd){
            ans.insert(ans.begin()+ans.size()/2,odd);
        }
        cout << ans << '\n';
    }

    return 0;
}