//
// Created by newbi on 2023-09-28.
//
#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
int cnt,N;
vector<int> vec;

void print(){
    for(auto elem: vec){
        cout << elem <<" ";
    }
    cout <<endl;
}
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();

    cin >> N;
    int tmp;
    for(int i=0;i<N;i++){
        cin >>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.begin()+N);

    while(vec.size() > 1){
        vec[vec.size()-2] += vec[vec.size()-1]; //맨뒤의 체인을 맨뒤의 앞의 체인에 연결
        vec[0]--;   //가장 적은 체인 하나 사용
        cnt ++; //체인을 푼 횟수 카운트
        vec.pop_back(); //맨 뒤의 체인은 하나로 연결 되었음
        
        if(vec[0] == 0){    //맨 처음 체인이 사라지면 앞의 요소 지운다.
            vec.erase(vec.begin());
        }
        //print();
    }
    cout << cnt <<'\n';

    return 0;
}