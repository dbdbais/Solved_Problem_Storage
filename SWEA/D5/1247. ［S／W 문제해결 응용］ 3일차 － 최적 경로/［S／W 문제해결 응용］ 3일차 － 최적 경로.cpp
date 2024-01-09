//
// Created by newbi on 2024-01-09.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int startX,startY,endX,endY, T,N,ans = 1e8;
pair<int,int> customers[14];

int getDistance(pair<int,int> a, pair<int,int> b){  //거리 구하는 함수
    return abs(a.first - b.first) + abs(a.second- b.second);
}

void update(vector<int>v){  //최소 값 갱신하는 함수
    int sm =0;
    sm += getDistance({startX,startY},customers[v[0]]);
    for(int i=0;i<v.size()-1;i++){
        sm += getDistance(customers[v[i]],customers[v[i+1]]);
    }
    sm += getDistance(customers[v[v.size()-1]],{endX,endY});
    if(ans > sm) ans = sm;
}

void solve(){
    vector<int> v;
    for(int i=1;i<=N;i++){
        v.push_back(i);
    }
    do{
        update(v);
    }while(next_permutation(v.begin(),v.end()));    //모든 순열 찾아 update
}

void input(){
    int x,y;
    cin >> startX >>startY >> endX >> endY;
    for(int i=1;i<=N;i++){
        cin >> x >> y;
        customers[i].first = x;
        customers[i].second = y;
    }
}
void reset(){   //초기화
    ans = 1e8;
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();

    cin >> T;
    for(int idx =1; idx <=T;idx++){
        cin >> N;
        input();
        solve();
        cout << "#"<<idx <<" "<<ans <<'\n';
        reset();
    }

    return 0;
}