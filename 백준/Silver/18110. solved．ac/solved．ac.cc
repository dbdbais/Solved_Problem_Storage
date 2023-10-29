//
// Created by newbi on 2023-08-08.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <numeric>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if(n==0){
        cout<<0;
    }
    else {
        vector<int> vec(n);

        for (auto it = vec.begin(); it != vec.end(); it++) {
            cin >> *it;
        }
        sort(vec.begin(), vec.end());
        int val = static_cast<int>(round(n * 0.15));

        int average = static_cast<int>(round(accumulate(vec.begin() + val, vec.end() - val, 0.0) / (n - val * 2)));
        cout << average;
    }

}