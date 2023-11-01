//
// Created by newbi on 2023-11-01.
//
#include <iostream>
#include <cstring>
using namespace std;
int N,T,ans;
int arr[52][52];


void input(){
    string st;
    for(int i=0;i<N;i++){
        cin >> st;
        for(int j=0;j<N;j++){
            arr[i][j] = st[j]-'0';
        }
    }
}
void reset(){
    ans = 0;
    N = 0;
    memset(arr,0,sizeof(arr));
}
void solve(){
    int start = N/2;
    int end = N/2;

    for(int i=0;i<N;i++){
        for(int j=start;j<=end;j++){
            ans += arr[i][j];
        }
        if(i < N/2){    //절반을 넘을 때 까지는 폭을 늘린다.
            start -=1;
            end += 1;
        }
        else{           //절반을 넘기면 폭을 좁힌다.
            start+=1;
            end -= 1;
        }
    }
}


int main(){
    cin >> T;

    for(int i=1;i<=T;i++){
        cin >> N;
        input();
        solve();
        cout << "#"<<i<<" "<<ans<<'\n';
        reset();
    }

    return 0;
}