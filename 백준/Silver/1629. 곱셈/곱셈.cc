//
// Created by newbi on 2023-08-24.
//
#include <iostream>
using namespace std;
typedef long long ll;

ll solve(ll A, ll B, ll C){
    ll ans;
    if (B == 1) return A % C;   // 1승이면 나머지연산만 하고 리턴.
    ans = solve(A,B/2,C);
    ans = (ans * ans) % C;      // ex) 2^8 = 2^4 * 2^4
    if(B % 2 == 1){     //홀수면 한번 더 곱한다. ex) 2^9 = 2^4 * 2^4 * 2^1
        ans = (ans *A)%C;
    }
    return ans;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll A, B, C;
    cin >> A >> B >> C;
    cout << solve(A,B,C)<< '\n';

    return 0;
}