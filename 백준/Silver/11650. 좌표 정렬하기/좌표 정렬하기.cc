//
// Created by newbi on 2023-08-08.
//
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a>>b;
        vec.push_back(make_pair(a,b));
    }
    sort(vec.begin(),vec.end(),[](pair<int,int> t1,pair<int,int> t2){
        if(t1.first < t2.first){
            return true;
        }
        else if (t1.first == t2.first){
            if(t1.second < t2.second){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    });

    for(pair<int,int> elem: vec)
        cout << elem.first<<" "<<elem.second<<"\n";

    return 0;
}