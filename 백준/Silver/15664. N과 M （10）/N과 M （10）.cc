//
// Created by newbi on 2024-04-06.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M,tmp;
int input[10];
set<vector<int>> ans;
vector<int> vec;

void combi(int start,int depth){

    if(depth == M){
        vector<int>v;
        for(int i=0;i<M;i++){
            v.push_back(input[i]);
        }
        ans.insert(v);
        return;
    }

    for(int i=start+1;i<vec.size();i++){
        input[depth] = vec[i];
        combi(i,depth+1);
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

    combi(-1,0);

    for(auto elem : ans){
        for(auto e : elem){
            cout << e <<" ";
        }
        cout << endl;
    }
    /*
    for(auto st : ans){
        for(auto c : st){
            cout << c <<" ";
        }
        cout << endl;
    }
     */

    return 0;
}