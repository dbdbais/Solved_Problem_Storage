//
// Created by newbi on 2023-09-12.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, ans, X, lo, hi;
vector<int> vec (100001,0);
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> vec[i];
    }
    cin >> X;
    sort(vec.begin(),vec.begin()+N);

    hi = N-1;
    int tmp;
    while(lo < hi){
        tmp = vec[lo]+vec[hi];  //로우와 하이 포인터의 합
        if(tmp > X){    //크면
            hi--;
        }
        else if(tmp < X){   //작으면
            lo++;
        }
        else{
            ans++;
            hi--;
        }
    }
    cout << ans <<'\n';
    return 0;
}