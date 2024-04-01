//
// Created by newbi on 2024-04-01.
//
#include <iostream>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

typedef long long ll;

ll mod = 1000000007;

ll pow(ll base, ll x){
    if(x == 0){
        return 1;
    }
    if(x == 1){
        return base;
    }
    ll tmp = pow(base,x/2);
    if(x % 2 == 1){
        return (tmp % mod * tmp % mod * base) % mod;
    }
    else{
        return (tmp % mod * tmp % mod) % mod;
    }

}
int T,N;

int main(){
    fastIO();
    cin >> T;
    For(t,0,T){
        cin >> N;
        if(N > 1) {
            cout << pow(2, N - 2) << endl;
        }
        else{
            cout << 1 << endl;
        }
    }

    return 0;
}