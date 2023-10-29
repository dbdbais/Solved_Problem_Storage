//
// Created by newbi on 2023-09-09.
//
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
vector<pair<int,int>>v;
int n,ans=0;
void print(){
    priority_queue<int, vector<int>, greater<int>> temp = pq;
    cout << "PQ: ";
    while (!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int p,d;
    for(int i=0;i<n;i++){
        cin >> p >> d;
        v.push_back(make_pair(d,p));    //일자를 기준으로 정렬하기 위해 pair만들어 삽입
    }
    sort(v.begin(),v.end());    //날짜 첫번째 가격 두번째 기준으로 정렬
//cout <<endl;
   // print();  확인용
    for(int i=0;i<n;i++){
        pq.push(v[i].second);   //가격을 min heap에 삽입
        if(pq.size() > v[i].first){ //i일 안에 수행할 수 없는 것중에 가장 가격이 낮은 강연 취소
            pq.pop();
        }
        //print();
    }
    while(pq.size()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';

    return 0;
}

