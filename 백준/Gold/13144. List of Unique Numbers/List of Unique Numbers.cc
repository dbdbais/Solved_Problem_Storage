//
// Created by newbi on 2023-09-12.
//
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll N,lo,hi;
ll ans; //10만이 들어올 경우 경우의 수가 int의 최대값보다 높아질 수 있음
vector<ll> cnt(100001,0);  //카운팅 벡터
vector<ll> vec(100001,0);
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0;i<N;i++){
        cin >>vec[i];
    }

    while(hi<N){
        if(!cnt[vec[hi]]){ //vec의 숫자가 cnt되지 않았다면
            cnt[vec[hi]] ++; //카운트 기록
            hi++;//다음 탐색
        }
        else{   //같은게 있었다면
            ans += (hi - lo); //같은 것을 포함하는 경우의 수 더한다.
            cnt[vec[lo]]--;
            lo++;
        }
    }
    ans += ll((hi-lo)*(hi-lo+1))/2;
    cout << ans << '\n';
    return 0;
}