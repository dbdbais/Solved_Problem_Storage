//
// Created by newbi on 2023-09-29.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, ans = 1e9;
vector<int> vec;
void fastIO(){
    ios::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
}
void print(){
    for(auto elem: vec){
        cout << elem <<" ";
    }
    cout <<endl;
}
int main(){
    fastIO();
    cin >> N;
    int tmp;
    for(int i=0;i<2*N;i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());

    //print();

    while(vec.size()){

        int team = vec[0] + vec[vec.size()-1];

        ans = min(ans,team);

        vec.pop_back();
        vec.erase(vec.begin());
        //print();
    }

    cout << ans << '\n';

    return 0;
}