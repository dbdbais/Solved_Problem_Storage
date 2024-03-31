//
// Created by newbi on 2024-03-31.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M;
vector<int>v;
int output[10];
void combi(int start,int cnt){

    if(cnt == M){
        for(int i=0;i<M;i++){
            cout << output[i] <<" ";
        }
        cout <<endl;
        return;
    }

    for(int i=start+1;i<v.size();i++){
        output[cnt] = v[i];
        combi(i,cnt+1);
    }

}


int main(){
    fastIO();
    cin >> N >> M;

    int num;
    For(i,0,N){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    combi(-1,0);

    return 0;
}