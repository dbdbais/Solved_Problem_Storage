//
// Created by newbi on 2023-10-27.
//
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int T,N;
ll ans;
int arr[1000004];

void reset(){
    ans = 0;
    N =0;
    memset(arr,0,sizeof(arr));
}
void solve(){
    int mx= arr[N-1];   //맨 뒤의 값을 큰값으로 설정
    for(int j = N-2;j>=0;j--){
        if(mx <= arr[j]){
            mx = arr[j];    //mx값 갱신
        }
        else{   //조금이라도 이익이 있다면
            ans += mx-arr[j];
        }
    }
}

int main(){

    int idx = 1;

    cin >> T;
    while(T){
        cin >> N;
        for(int i=0;i<N;i++){
            cin >> arr[i];
        }
        solve();
        cout <<"#"<<idx<<" "<<ans<<'\n';

        idx++;
        T--;
        reset();
    }
    return 0;
}