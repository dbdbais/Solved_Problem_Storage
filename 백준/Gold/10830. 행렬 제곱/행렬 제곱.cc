//
// Created by newbi on 2024-03-18.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
typedef long long ll;

ll N,B;
const int mod = 1000;

void print(vector<vector<ll>>vec){
    for(auto row : vec){
        for(auto elem : row){
            cout << elem << " ";
        }
        cout <<endl;
    }
}
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b ){
    vector<vector<ll>> res (N,vector<ll>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                res[i][j] += (a[i][k]%mod * b[k][j]%mod);
            }
            res[i][j] %=mod;    //1000으로 나눈다.
        }
    }
    return res;
}

vector<vector<ll>> solve(vector<vector<ll>>vec){

    vector<vector<ll>> res (N,vector<ll>(N,0));
    For(i,0,N){
        res[i][i] = 1;
    }

        while(B>0){
           // cout<< "B : " <<B << endl;
            if(B % 2 == 1){ //홀수라면
                res = mul(res,vec);
//                cout << "res" <<endl;
//                print(res);
            }
//            cout << "before" <<endl;
//            print(vec);
            vec = mul(vec,vec);
//            cout << "after" <<endl;
//            print(vec);
            B/=2;
        }

    return res;
}

int main(){

    fastIO();
    cin >> N >> B;
    vector<vector<ll>> A (N,vector<ll>(N,0));
    ll tmp;
    For(i,0,N){
        For(j,0,N){
            cin >> tmp;
            A[i][j] = tmp;
        }
    }

    auto res =solve(A);

    print(res);

    return 0;
}