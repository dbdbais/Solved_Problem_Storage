//
// Created by newbi on 2024-05-04.
//
#include <iostream>

#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

using namespace std;
string s;
int solve(){
    int oneCount =0;
    int zeroCount = 0;
    char _prev = s[0];
    if(_prev == '0'){
        zeroCount++;
    }
    else{
        oneCount++;
    }
    for(int i=1;i<s.length();i++){
        char cur = s[i];
        //cout <<_prev <<" : "<< cur <<", ";
        if(_prev != cur){
            if(cur == '1') oneCount++;
            else zeroCount++;
            _prev = s[i];   //이전것 이거로 변경
        }
    }
   return min(zeroCount,oneCount);
}


int main(){
    fastIO();
    cin >> s;
    cout << solve() << endl;
    return 0;
}