//
// Created by newbi on 2024-06-09.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

struct pokemon{
    int no;
    string name;
    int evol;

    bool operator<(pokemon p){
        if(evol == p.evol){
            return no < p.no;
        }
        else{
            return evol > p.evol;
        }
    }
};
int N,cnt;
vector<pokemon> vec;

int evolution(int _have, int _need){
    int ret =0;
    int leftover = _have;
    while(leftover >= _need){
        leftover -= _need;
        if(leftover >= 0){
            ret++;
            leftover += 2;
            //사탕 2개 돌려줌
        }
    }
    return ret;

}

int main(){
    fastIO();
    string _name;
    int _need =0, _have = 0;
    cin >> N;
    For(i,0,N){
        cin >> _name >> _need >> _have;
        int e = evolution(_have,_need);
        vec.push_back({i,_name,e});
    }

    sort(vec.begin(),vec.end());
    for(auto elem : vec){
       // cout << elem.name <<" : " << elem.evol << " : " << endl;
         cnt += elem.evol;
    }
    cout << cnt << endl;
    cout << vec[0].name << endl;

    return 0;
}