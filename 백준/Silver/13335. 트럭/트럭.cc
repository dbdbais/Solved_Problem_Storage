//
// Created by newbi on 2024-05-29.
//
#include <iostream>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,W,L,weight;
queue<int> q;
deque<pair<int,int>> dq;    //남은거리, 무게

void print(){
    cout <<"L: " <<L << endl;
    for(auto elem : dq){
        cout << elem.first <<", "<< elem.second <<" <- ";
    }
    cout << endl;
}

int solve(){
    int _time = 0;
    do{
        _time++;

        if(dq.size()){
            auto tp = dq.front();
            //맨 처음게 0이 된다면
            if(tp.first == 1){
                dq.pop_front();
                L += tp.second; //원복
            }
            for(auto &elem : dq ){
                elem.first--;
            }
        }

        //올 차가 있다면
        if(q.size()){
            int qw = q.front();
            //지나갈 수 있다면 (무게 초과 X, 다리가 꽉차지 않았다면)
            if(L - qw >= 0 && dq.size() <W){
                //다리 길이랑 현재 무게
                dq.push_back({W,qw});
                q.pop();
                L -= qw;
            }
        }
        //print();

    }while(dq.size());

    return _time;
}

int main(){
    fastIO();
    cin >> N >> W >> L;
    For(i,0,N){
        cin >> weight;
        q.push(weight);
    }
    cout << solve() << endl;
    return 0;
}