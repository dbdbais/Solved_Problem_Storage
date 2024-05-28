//
// Created by newbi on 2024-05-28.
//
#include <iostream>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
bool dp[1004];
//상근이가 이기는 경우

void solve(){
   dp[1] = true;
   dp[2] = false;
   dp[3] = true;
   dp[4] = true;
   dp[5] = true;
   for(int i=6;i<=N;i++){
       //창영이가 먼저 둠 (즉 패배할 확률이 있는 돌을 창영이에게 넘김)
       if(dp[i-1] == false || dp[i-3] == false || dp[i-4] == false ){
           dp[i] = true;
       }
   }
}


int main(){
    fastIO();
    cin >> N;
    solve();

    if(dp[N]){
        cout << "SK" << endl;
    }
    else{
        cout << "CY" << endl;
    }

    return 0;
}