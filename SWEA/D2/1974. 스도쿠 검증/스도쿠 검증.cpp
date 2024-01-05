//
// Created by newbi on 2024-01-05.
//
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[14][14];
int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] ={1,-1,0,0,1,1,-1,-1};
 
int T , ans;
bool suc;
 
void reset(){
    suc = false;
}
 
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> arr[i][j];
        }
    }
}
 
void solve(){
 
    for(int i =0;i<9;i++){       //가로세로 중복 학인
        vector<int>v1;
        vector<int>v2;
        for(int j=0;j<9;j++){
 
            v1.push_back(arr[i][j]);
            v2.push_back(arr[j][i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        v1.erase(unique(v1.begin(),v1.end()),v1.end()); //중복 삭제
        v2.erase(unique(v2.begin(),v2.end()),v2.end()); //중복 삭제
        if(v1.size() != 9 || v2.size() != 9){
            return;
        }
    }
 
    for(int i=1;i<9;i+=3){
        for(int j=1;j<9;j+=3){
            vector<int>v3;
            v3.push_back(arr[i][j]);
            for(int k=0;k<8;k++){
                v3.push_back(arr[i+dx[k]][j+dy[k]]);    //여러방향에 있는 값 다 더함
            }
            sort(v3.begin(),v3.end());
            v3.erase(unique(v3.begin(),v3.end()),v3.end());   //중복 삭제
            if(v3.size() != 9){
                return;
            }
        }
    }
    suc = true;
 
}
 
int main(){
    cin >> T;
    for(int idx = 1;idx<=T;idx++){
        input();
        solve();
        if(suc) ans = 1;
        else ans = 0;
        cout << "#"<<idx<<" "<<ans<<'\n';
        reset();
 
    }
 
    return 0;
}