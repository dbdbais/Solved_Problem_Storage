//
// Created by newbi on 2023-11-13.
//
#include <iostream>
using namespace std;

int arr[101][101];
int ans;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
void input(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cin >> arr[i][j];
        }
    }
}

void solve(){

    for(int i=0;i<100;i++){     //가로 확인
        int sm = 0;
        for(int j=0;j<100;j++){
            sm += arr[i][j];
        }
        if(sm > ans) ans = sm; //최대 값 바꾼다.
    }

    for(int i=0;i<100;i++){     //세로 확인
        int sm = 0;
        for(int j=0;j<100;j++){
            sm += arr[j][i];
        }
        if(sm > ans) ans = sm; //최대 값 바꾼다.
    }

    int lbi = 0;
    int rbi = 0;
    for(int i=0;i<100;i++){     //대각선 확인
        lbi += arr[0+i][0+i];
        rbi += arr[99-i][0+i];
    }
    if(lbi > ans) ans = lbi; //최대 값 바꾼다.
    if(rbi > ans) ans = rbi; //최대 값 바꾼다.
}

void reset(){
    ans =0;
}

int main(){
    int n;
    for(int i=1;i<=10;i++){
        cin >> n;
        input();
        solve();
        cout << "#"<<i<<" "<<ans <<'\n';
        reset();
    }

    return 0;
}