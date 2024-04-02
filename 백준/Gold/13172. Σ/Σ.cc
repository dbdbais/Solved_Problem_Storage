#include <iostream>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;

ll mod = 1000000007; 
ll A, B, C;

ll pow(ll base, ll x) {
	if (x == 0) {
		return  1;
	}
	if (x == 1) {
		return base;
	}
	ll tmp = pow(base, x / 2);
	if (x % 2 == 1) {
		return  (tmp % mod * tmp%mod * base%mod) % mod;
	}
	else {
		return (tmp%mod * tmp%mod) %mod;
	}
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else
		return gcd(b, a%b);

}

int M;
ll Nsm = 1, Ssm = 1, ans = 0, N, S;
int main() {
	fastIO();
	cin >> M;

	For(t, 0, M) {
		cin >> N >> S;
		N %= mod;
		S %= mod;

		ll gcdn = gcd(N, S);	//최대 공약수 구한다.

		N /= gcdn;	//최대공약수로 나눈다. 기약 분수로 만든다.
		S /= gcdn;

		ans += (S * (pow(N, mod - 2) % mod)) % mod;
		ans %= mod;
	}
	cout << ans << endl;

	return 0;
}