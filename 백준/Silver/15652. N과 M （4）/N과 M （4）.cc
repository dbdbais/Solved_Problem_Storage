//
// Created by newbi on 2024-01-13.
//
#include <iostream>
#include <vector>

using namespace std;
int N,M;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void print(vector<int> v){
    for(auto elem : v){
        cout << elem<<" ";
    }
    cout <<'\n';
}

void solve(int idx,vector<int> v){
    if(v.size() == M){  //M개라면 모두 출력
        print(v);
        return;
    }

    for(int i = idx;i<= N; i++){
        if(v.size()){   //이전의 값이 존재한다면
            int _prev = v.back();   //이전 값
            if(_prev <= i){ //이전 값이 지금 값보다 작거나 같다면
                v.push_back(i);
                solve(i,v);
                v.pop_back();
            }

        }
        else{   //처음 값이라면 이전과 같이 동작
            v.push_back(i);
            solve(i,v);
            v.pop_back();
        }
    }
    return;
}

int main(){

    fastIO();
    cin >> N >> M;
    vector<int> v;
    solve(1,v);

    return 0;
}
