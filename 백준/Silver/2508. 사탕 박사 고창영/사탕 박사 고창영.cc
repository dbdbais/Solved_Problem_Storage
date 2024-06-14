//
// Created by newbi on 2024-06-14.
//
#include <iostream>
#include <vector>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, R, C, ans;
char arr[402][402];

vector<pair<int,int>> candy;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {-1,1,0,0};

bool out(int x,int y){
    return x < 0 || y < 0 || x >= R || y >= C;
}

void solve(){
    for(auto c : candy){
        int cx = c.first;
        int cy = c.second;
        int hCnt =0;
        int wCnt = 0;
        For(i,0,4){
            int qx = cx +dx[i];
            int qy = cy +dy[i];
            if(out(qx,qy)) continue;
            if(i==0 && arr[qx][qy] == '>') wCnt++;
            else if(i==1 && arr[qx][qy] == '<') wCnt++;
            else if(i==2 && arr[qx][qy] == '^') hCnt++;
            else if(i==3 && arr[qx][qy] == 'v') hCnt++;
        }
        if(wCnt ==2 || hCnt == 2) {
            //cout << cx <<" , " << cy << endl;
            ans++;
        }
    }
}
void reset(){
    ans = 0;
    candy.clear();
}

void input(){
    cin >> T;
    string s;
    For(t,0,T){
        cin >> R >> C;
        For(i,0,R){
            cin >> s;
            For(j,0,C){
                arr[i][j] = s[j];
                if(arr[i][j] == 'o') candy.push_back({i,j});
            }
        }
        solve();
        cout << ans << endl;
        reset();
    }

}

int main(){
    fastIO();
    input();

    return 0;
}