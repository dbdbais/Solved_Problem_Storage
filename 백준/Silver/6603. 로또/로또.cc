//
// Created by newbi on 2024-05-16.
//
#include <iostream>

#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
int ipt[13],k;
int order[13];
using namespace std;

void combi(int start,int idx){
    if(idx == 6){
        For(i,0,6){
            cout << ipt[order[i]] <<" ";
        }
        cout << endl;
        return;
    }
    For(i,start+1,k){
        order[idx] = i;
        combi(i,idx+1);
    }

}

int main(){
    fastIO();
    while(cin >> k){
        if(k == 0) break;

        For(i,0,k){
            cin >> ipt[i];
        }
        combi(-1,0);
        cout << endl;
    }
    return 0;
}