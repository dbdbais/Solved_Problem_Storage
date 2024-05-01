//
// Created by newbi on 2024-05-01.
//
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M,S,E;
int arr[2004];
bool dp[2004][2004];

bool check(int _start,int _end){
    bool isPal = false;
    if(dp[_start][_end]){
        isPal = true;
    }
    else{
        if(arr[_start] != arr[_end]){
            isPal = false;
        }
        else{       //같다면
            if(_start+1 <= _end-1){
                isPal = check(_start+1,_end-1);
                if(isPal){
                    dp[_start][_end] = true;
                }
            }
        }


    }

    return isPal;
}

int main(){
    fastIO();
    cin >> N;
    For(i,1,N+1){
        cin >> arr[i];
    }

    For(i,1,N+1){   //하나만 있을 때
        dp[i][i] = true;
    }

    For(i,1,N){ //2개만 있을 때
        if(arr[i] == arr[i+1]){
            dp[i][i+1] = true;
        }
    }


    for(int i=1;i<=N-2;i++){
        for(int j=i+2;j<=N;j++){
            if(check(i,j)){
                dp[i][j] = true;
            }
        }
    }

    cin >> M;

    For(i,0,M){
        cin >> S >> E;
        cout << dp[S][E] <<endl;
    }

    return 0;
}