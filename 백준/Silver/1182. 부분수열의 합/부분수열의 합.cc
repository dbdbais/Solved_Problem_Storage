//
// Created by newbi on 2024-05-16.
//

#include <iostream>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,S,ans;

int ipt[21];
bool isOk[21];

void genrateSubset(int idx){
    if(idx == N){
        int sm =0;
        bool isNull = true;
        For(i,0,N){
            if(isOk[i]){
                isNull = false;
                sm += ipt[i];
                //cout << ipt[i] <<" ";
            }
        }
        //cout << endl;
        if(sm == S && !isNull){
            ans++;
            //cout <<"OK" << endl;
        }
        return;
    }
    isOk[idx] = true;
    genrateSubset(idx+1);
    isOk[idx] = false;
    genrateSubset(idx+1);
}


int main(){
    fastIO();
    cin >> N >> S;
    For(i,0,N){
        cin >> ipt[i];
    }
    genrateSubset(0);
    cout << ans << endl;
    return 0;
}