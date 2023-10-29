//
// Created by newbi on 2023-10-29.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec(100,0);
int dump,hidx,lidx,ans;

void input(){
    for(int i=0;i<100;i++){
        cin >> vec[i];
    }
}
void update(){
    int hi =0,lo= 9999;
    for(int i=0;i<100;i++){
        if(hi < vec[i] && vec[i]>1) hi = max(vec[i],hi);
        if(lo > vec[i]) lo = min(lo,vec[i]);
    }

    auto ht = find(vec.begin(),vec.end(),hi);
    auto lt = find(vec.begin(),vec.end(),lo);
    hidx = ht - vec.begin();
    lidx = lt - vec.begin();
    ans = vec[hidx] - vec[lidx];
}

void solve(){
    int idx=0;
    while(dump){
        idx++;
        update();
        if(ans <=1) break; //평탄화 완료 조건
        vec[hidx] -=1;
        vec[lidx] +=1;
        dump--;
    }
}

void reset(){
    fill(vec.begin(),vec.end(),0);
    hidx =0;
    lidx =0;
    dump =0;
    ans = 0;
}
void print(){
    for(auto elem: vec){
        cout << elem<<" ";
    }
    cout <<endl;
}

int main(){

    for(int i=1;i<=10;i++){
        cin >> dump;
        input();
        solve();
        update();   //중요! 전에 있던 변수 말고 모든 dump가 끝난 뒤, 다시 update후 ans 출력
        cout <<"#"<<i<<" "<<ans<<'\n';
        reset();
    }

    return 0;
}
