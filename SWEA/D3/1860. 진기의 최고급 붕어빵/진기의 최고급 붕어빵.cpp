//
// Created by newbi on 2023-11-17.
//
#include <iostream>
#include <cstring>
using namespace std;
int T,N,M,K,arrive,fishBread,mx;
int tim[11115];
string ans;

void solve(){
    bool fail = false;
    ans = "Possible";
    if(tim[0]) {	//0초에 사람 오는 반례
        ans ="Impossible";
        return;
    }
    for(int i=1;i<=mx;i++){
        if(i % M == 0){
            fishBread += K;	//K개의 붕어빵 구움
        }
        if(tim[i]){ //시간안에 사람이 온다면
            fishBread -= tim[i];    //시간에 있는 사람만큼 붕어빵 감소
            if(fishBread < 0) {
                fail = true;
                ans = "Impossible";
            }
        }
        if(fail){
            break;
        }

    }
}

void reset(){
    mx = 0;
    fishBread =0;
    ans = "";
    memset(tim,0,sizeof(tim));

}

int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> N >> M >> K;
        for(int j =0;j<N;j++){
            cin >> arrive;
            tim[arrive]= tim[arrive]+1;
            mx = max(mx,arrive);    //가작 늦게 온 손님 기록
        }
        solve();
        cout << "#"<<i<<" "<<ans<<'\n';
        reset();
    }

    return 0;
}