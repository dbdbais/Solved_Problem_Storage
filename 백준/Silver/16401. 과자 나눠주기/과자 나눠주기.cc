//
// Created by newbi on 2024-05-02.
//
#include <iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int M,N;

vector<int> vec;

bool check(int val){
    int cnt = 0;
    For(i,0,N){
        cnt += vec[i]/val;
    }
    if(cnt >= M) return true;
    else return false;
}

int solve(){
    int ans = 0;
    int _left = 1;
    int _right = vec[N-1];
    while(_left <= _right){
        int mid = (_left + _right) / 2;

        if(check(mid)){
            //cout << mid << endl;
            ans = mid;
            _left = mid+1;
        }
        else{
            _right = mid -1;
        }
    }

    return ans;
}

int main(){
    fastIO();
    cin >> M >> N;
    int snack;
    For(i,0,N){
        cin >> snack;
        vec.push_back(snack);
    }
    sort(vec.begin(),vec.end());
    cout << solve() << endl;


    return 0;
}