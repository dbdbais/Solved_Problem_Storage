//
// Created by newbi on 2023-11-14.
//
#include <iostream>
#include <queue>
using namespace std;
deque<int> dq;
int n;

void input(){
    int tmp;
    for(int i=0;i<8;i++){
        cin >> tmp;
        dq.push_back(tmp);
    }
}
void solve(){
    bool done = false;  //값을 찾았을 때
    while(true){
        for(int i=1;i<=5;i++){
            int cur = dq.front();   //맨 앞
            dq.pop_front();
            cur = max(cur-i,0); //0보다 낮아지는 것 방지
            dq.push_back(cur);  //뒤로 넣는다
            if(!cur) {  //현재 0이라면
                done =true;
                break;
            } // 종료
        }
        if(done) break;
    }
}
void reset(){
    dq.clear();
}
void print(){
    for(auto elem: dq){
        cout << elem <<" ";
    }
    cout <<'\n';
}
int main(){
    for(int i=1;i<=10;i++){
        cin >> n;
        input();
        solve();
        cout << "#"<<i<<" ";
        print();
        reset();
    }
    return 0;
}