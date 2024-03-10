//
// Created by newbi on 2024-03-10.
//
#include <iostream>
#include <algorithm>
#include <string>

#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int dp[1001][1001];
int ans;
string s1,s2;

void print(){

    For(i,1,s1.size()+1){
        For(j,1,s2.size()+1){
            cout << dp[i][j] <<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}

bool out(int x,int y){
    return x <0 || y <0 || x>=s1.size() || y >= s2.size();
}

const int dx[] = {-1,0,-1};
const int dy[] = {0,-1,-1};

bool found;

void getAlpha(int x,int y,string st){
    //cout << st << endl;

    if(found) return;

    if(dp[x][y] == 0){
        found = true;
        reverse(st.begin(), st.end());
        cout << st <<endl;
        return;
    }
    int curVal = dp[x][y];  //현재
    For(i,0,2){
        int qx = x + dx[i];
        int qy = y + dy[i];
        //if(out(qx,qy)) continue;
        if(curVal == dp[qx][qy]) getAlpha(qx,qy,st);
    }
    int qx = x +dx[2];
    int qy = y +dy[2];
    getAlpha(qx,qy,st+s1[x-1]);
}

void solve(){
    int s1Len = s1.size();
    int s2Len = s2.size();

    for(int i=1;i<=s1Len;i++){
        char cur = s1[i-1];   //현재
        for(int j=1;j<=s2Len;j++){
            if(s2[j-1] == cur) {
                dp[i][j] = dp[i-1][j-1] + 1;  //더한다.
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);  //기존 값 누적한다.
            }
            if(ans < dp[i][j]) ans = dp[i][j];
        }
    }

}

int main(){
    fastIO();
    cin >> s1 >> s2;

    solve();
    cout << ans << endl;
    getAlpha(s1.size(),s2.size(),"");
    //print();
    return 0;
}