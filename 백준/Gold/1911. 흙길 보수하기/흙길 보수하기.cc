//
// Created by newbi on 2024-05-22.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define fastIO() ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
using namespace std;

int N,L,a,b,idx,ans;
vector<pair<int,int>> vec;
int main(){
    fastIO();
    cin >> N >> L;
    For(i,0,N){
        cin >> a >> b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());
    for(auto sink : vec){
        //웅덩이의 끝이 이미 커버된다면
        if(idx > sink.second) continue;

        //웅덩이의 맨 앞이 널빤지를 넘었다면
        if(idx < sink.first){
            //차
            int used = 0;
            int diff = sink.second - sink.first;
            used = diff/L;
            if(diff % L !=0){
                used++;
            }
            ans += used;
            idx = sink.first+ used *L;
        }
        //웅덩이의 맨 앞이 겹치면
        else{
            int used = 0;
            int diff = sink.second - idx;
            used = diff/L;
            if(diff % L !=0){
                used++;
            }
            ans += used;
            idx = idx + L * used;
        }

    }
    cout << ans << endl;

    return 0;
}