//
// Created by newbi on 2023-10-29.
//
#include <iostream>
#include <cstring>
using namespace std;
int dir[4]={-2,-1,1,2};
int building[1004],N,cnt;

void solve(){
    for(int i= 2;i<N-2;i++){
        bool suc = true;
        int neighbor =0;
        for(int j=0;j<4;j++){
            if(building[i]<=building[i+dir[j]]){ //옆에 조망이 없다면
                suc = false;
                break;
            }
            neighbor = max(neighbor,building[i+dir[j]]);    //가장 큰 이웃을 구한다.
        }
        if(suc) cnt += building[i]-neighbor;
    }

}
void reset(){
    memset(building,0,sizeof(building));
    cnt =0;
}

int main(){

    for(int i=1;i<=10;i++){
        cin >> N;
        for(int j=0;j<N;j++){
            cin >> building[j];
        }
        solve();
        cout <<"#"<<i<<" "<<cnt<<'\n';
        reset();
    }

    return 0;
}