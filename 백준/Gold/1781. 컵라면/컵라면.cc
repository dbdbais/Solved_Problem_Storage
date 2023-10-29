//
// Created by newbi on 2023-09-10.
//
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N,deadline,ramen;
vector<pair<int,int>> vec;
priority_queue<int,vector<int>,greater<int>> pq;
int ans;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> deadline >> ramen;
        vec.push_back(make_pair(deadline,ramen));
    }
    sort(vec.begin(),vec.end());
    /*
    for(auto elem: vec){
        cout << elem.first<<" : "<<elem.second <<endl;
    }
     */
    for(int i=0;i<N;i++){
        pq.push(vec[i].second);
        if(pq.size()>vec[i].first){
            pq.pop();
        }
    }
    while(pq.size()){
        ans += pq.top();
        pq.pop();
    }

    cout << ans <<'\n';

    return 0;
}