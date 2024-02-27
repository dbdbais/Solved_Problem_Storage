//
// Created by newbi on 2024-02-27.
//
#include <iostream>

#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int T,N;
typedef long long ll;
int oper[4];    //  +, -, *, /
ll input[13];
ll mx = -1e8,mn = 1e9;

void solve(int idx,ll sm){
    if(idx == N){
        if(sm > mx) mx = sm;
        if(sm < mn) mn = sm;

        return;
    }
    for(int i=0;i<4;i++){
        if(!oper[i]) continue;
        oper[i]--;  //감소
        if(i == 0){
            solve(idx+1,sm+input[idx]);
        }
        else if(i == 1){
            solve(idx+1,sm-input[idx]);
        }
        else if(i == 2){
            solve(idx+1,sm*input[idx]);
        }
        else{
            solve(idx+1,sm/input[idx]);
        }
        oper[i]++;  //원복
    }
}
void reset(){
    mx = -1e8;
    mn = 1e9;
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    fastIO();

    cin >> T;

    for(int t =1;t<=T;t++){
        cin >> N;
        For(i,0,4){
            cin >> oper[i];
        }
        For(i,0,N){
            cin >> input[i];
        }
        solve(1,input[0]);
        //cout << mx <<" " <<mn<<endl;
        cout << "#"<<t<<" "<<mx-mn<<endl;

        reset();
    }

    return 0;
}