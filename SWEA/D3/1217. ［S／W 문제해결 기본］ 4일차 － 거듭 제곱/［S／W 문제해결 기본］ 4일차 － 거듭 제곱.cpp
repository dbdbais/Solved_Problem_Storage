//
// Created by newbi on 2023-11-17.
//
#include <iostream>
#include <cmath>
using namespace std;
int n,N,M;
int main(){
    for(int i=1;i<=10;i++){
        cin >> n >> N >> M;
        cout << "#"<<i<<" "<<(int)pow(N,M)<<'\n';
    }
    return 0;
}