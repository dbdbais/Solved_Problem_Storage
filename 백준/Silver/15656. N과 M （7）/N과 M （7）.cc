//
// Created by newbi on 2024-04-05.
//
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M;
int input[8];
vector<int> ipt;
void perm(int depth){
    if(depth == M){
        For(i,0,M){
            cout << input[i] <<" ";
        }
        cout << endl;
        return;
    }
    for(int a = 0;a<N;a++){
        input[depth] = ipt[a];
        perm(depth+1);
    }
}
int main(){
    fastIO();
    cin >> N >> M;
    int tmp;
    For(i,0,N){
        cin >> tmp;
        ipt.push_back(tmp);
    }
    sort(ipt.begin(),ipt.end());
    perm(0);

    return 0;
}