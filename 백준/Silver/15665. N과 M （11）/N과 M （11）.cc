//
// Created by newbi on 2024-04-06.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M,tmp;
int input[10];
vector<int> vec;
set<vector<int>> ans;

void permutation(int depth){

    if(depth == M){
        vector<int> v;
        For(i,0,M){
            v.push_back(input[i]);
        }
        ans.insert(v);
        return;
    }

    for(int i=0;i<vec.size();i++){
        input[depth] = vec[i];
        permutation(depth+1);
    }

}

int main(){
    fastIO();
    cin >> N >> M;
    For(i,0,N){
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(),vec.end());

    permutation(0);

    for(auto v : ans ){
        for(int e : v){
            cout << e <<" ";
        }
        cout << endl;
    }


    return 0;
}