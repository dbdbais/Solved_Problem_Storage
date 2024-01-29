#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
ll ans;
ll wine[10004];	//포도주, n번 연속 선택
ll dp[10004][3];	//dp 배열

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fastIO();
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    dp[1][1] = wine[1];


    for (int i = 2; i <= n; i++) {
        dp[i][0] = max({dp[i-1][0],dp[i-1][1],dp[i - 1][2]});
        dp[i][1] = dp[i - 1][0] + wine[i];	//이전에 아무것도 선택 x + 현재 와인
        dp[i][2] = dp[i - 1][1] + wine[i];	//이전에 하나 선택 + 현재 와인
    }
    /*
    for (int i = 1; i <= n; i++) {
        cout << "0 : "<<dp[i][0] << " ";
        cout << "1 : " << dp[i][1] << " ";
        cout << "2 : " << dp[i][2] << " " << endl;
    }
    */

    ans = max({dp[n][0],dp[n][1],dp[n][2]});

    cout << ans << '\n';

    return 0;
}