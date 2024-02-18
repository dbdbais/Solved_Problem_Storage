//
// Created by newbi on 2024-02-18.
//
#include <iostream>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;
int dang[100004],cnt[100004],N;
bool isOk = true;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void print(){
    For(i,1,N+1){
        cout << dang[i] <<" ";
    }
    cout <<endl;
    For(i,1,N+1){
        cout << cnt[i]<<" ";
    }
    cout <<endl;
}
int find_idx(int _prev){
    int mx =0;
    int idx =-1;
    For(i,1,N+1){
        if(i == _prev)continue;
        if(cnt[i]> mx){
            mx = cnt[i];
            idx = i;
        }
    }
    return idx;
}
int main(){
    fastIO();
    cin >> N;
    For(i,1,N+1) {
        cin >> dang[i];
        cnt[dang[i]]++; //병사 카운트
    }
    int mx =0;

    For(i,1,100001){
        mx = max(mx,cnt[i]);    //가장 많이 서는 병사 추출
    }

    if(mx-1 <= N- mx){
        cout << "YES" <<endl;
    }
    else{
        cout << "NO" <<endl;
    }

    return 0;
}