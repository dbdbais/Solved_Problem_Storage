//
// Created by newbi on 2023-08-24.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    map<string,int> pokeNum;
    map<int,string> pokeName;

    for(int i=1;i<=N;i++){
        string name;
        cin >> name;
        pokeName[i] = name;
        pokeNum[name]= i;
    }
    for(int i=0;i<M;i++){
        string nameOrNum;
        cin >> nameOrNum;
        if(atoi(nameOrNum.c_str())==0) { // 숫자가 아니라 문자라면
            cout << pokeNum[nameOrNum] << '\n';
        }
        else{
            cout << pokeName[atoi(nameOrNum.c_str())] << '\n';
        }
    }

    return 0;
}