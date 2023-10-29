//
// Created by newbi on 2023-09-11.
//
#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;
int N, arrival,delay,total;
priority_queue<int> pq;
vector<pair<int,int>> vec;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arrival >> delay;
        vec.push_back(make_pair(arrival,delay));    //도착시간을 기준으로 삽입
    }
    sort(vec.begin(),vec.end());    //도착시간 기준 정렬

    total = vec[0].first + vec[0].second;   //총 시간

    for(int i=1;i<N;i++){
        total = max(total,vec[i].first);    //최소시간보다 크면 SWAP
        total += vec[i].second;     //지연시간 추가로 더함
    }
    cout << total << '\n';

    return 0;
}
