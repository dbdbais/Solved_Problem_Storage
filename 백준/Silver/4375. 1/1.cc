//
// Created by newbi on 2023-08-24.
//
#include <iostream>
using namespace std;
typedef long long ll;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    ll digit;
    while(cin >> N){
        ll ans = 1;
        digit = 1;

        while(true) {
            if (ans % N == 0) {
                cout << digit << '\n';
                break;
            }
            ans = ans * 10 + 1;
            digit++;
            ans %= N;
        }
    }
    return 0;
}