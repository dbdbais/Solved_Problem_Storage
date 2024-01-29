//
// Created by newbi on 2024-01-29.
//
#include <iostream>

using namespace std;

int n,m;
int arr[1030][1030];
int dp[1030][1030];
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << dp[i][j]<<" ";
        }
        cout <<endl;
    }
}
void solve(int x1,int y1,int x2,int y2){
    int sm =0;
    for(int i= x1;i<=x2;i++){
        sm += dp[i][y2]- dp[i][y1-1];
    }
    cout << sm <<'\n';
}

int main(){
    fastIO();
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i][j-1] + arr[i][j];
        }
    }

    //print();
    int x1,y1,x2,y2;
    for(int i=0;i<m;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        solve(x1,y1,x2,y2);
    }

    return 0;
}