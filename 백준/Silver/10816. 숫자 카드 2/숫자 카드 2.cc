//
// Created by newbi on 2023-08-08.
//
#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i=0;i<n;i++){
        int tmp;
        cin >>tmp;
        vec[i] = tmp;
    }
    sort(vec.begin(),vec.end());
    int m;
    cin >> m;
    for(int j=0;j<m;j++){
        int tmp;
        cin >> tmp;
        cout<< upper_bound(vec.begin(),vec.end(),tmp) - lower_bound(vec.begin(),vec.end(),tmp)<<" ";
    }

    return 0;
}