//
// Created by newbi on 2023-09-11.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> gem;
vector<ll> bag;
ll N, K, M, V, C, ans;
priority_queue<ll> pq; //최대 힙
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> M >> V;
        gem.push_back(make_pair(M,V)); //무게 위주로 맞춤
    }
    for(int i=0;i<K;i++){
        cin >> C;
        bag.push_back(C);
    }
    sort(gem.begin(),gem.end());    //무게 오름차순으로 정렬
    sort(bag.begin(),bag.end());    //가방 수용량 오름차순으로 정렬
    /*
    for(auto g : gem ){
        cout <<"Weight "<<g.first <<": Price "<<g.second<< endl;
    }*/

    ll idx =0;
    for(int i=0;i<bag.size();i++){
        while(idx < gem.size() && bag[i] >= gem[idx].first){    //SEG방지, 가방이 수용할 수있는 경우
            pq.push(gem[idx++].second); //  최대 힙에 PUSH
        }
        if(pq.size()){
            ans += pq.top();    //가방 수용량 대비 가장 값이 비싼 보석 POP
            pq.pop();
        }
    }

    cout << ans <<'\n';
    return 0;
}