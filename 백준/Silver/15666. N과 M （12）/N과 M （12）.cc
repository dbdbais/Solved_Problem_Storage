//
// Created by newbi on 2024-01-26.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> vec;
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(int start,vector<int> v){
    if (v.size() == M) {
        for (auto elem: v) {
            cout << elem << " ";
        }
        cout <<'\n';
        return;
    }

        for(int i=start;i<vec.size();i++){
            v.push_back(vec[i]);
            solve(i,v);
            v.pop_back();
        }
        return;
}

int main(){
    fastIO();
    int tmp;
    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());    //정렬
    vec.erase(unique(vec.begin(),vec.end()),vec.end()); //중복제거
    vector<int>v;

    solve(0,v);

    return 0;
}