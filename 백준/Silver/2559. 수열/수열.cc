//
// Created by newbi on 2023-08-24.
//
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> vec(100001,0);
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin >> N >> K;
    vector<int> temp(N+1);
    for(int i=1;i<=N;i++){
        cin >> temp[i];
        vec[i] = temp[i];
        vec[i] += vec[i-1];
    }
    int maxValue = -10000004;
    for (int i =K;i<=N;i++){
        maxValue = max(maxValue,vec[i]-vec[i-K]);
    }
    cout << maxValue <<'\n';
    return 0;
}
