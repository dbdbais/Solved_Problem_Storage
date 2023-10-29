//
// Created by newbi on 2023-09-15.
//
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;   //숫자가 상당히 크므로 long long 사용할 것
struct room{    //몬스터와 포션이 들어 있는 방 구조체
    ll type;
    ll attack;
    ll health;
};
vector<room> vec(123457);
int N;
ll atk,lo=1,hi= 1e18,mid,ans=1e18;
bool check(ll val){
    bool suc = true;
    ll mxHP = val;
    ll curHP = val;
    ll tmpAtk = atk;
    for(int i=0;i<N;i++){
        if(vec[i].type == 1){   //몬스터를 만났을 때
            int turn= (vec[i].health / tmpAtk); //몇번 공격을 시도하는 지
            if(vec[i].health % tmpAtk) turn ++;
            curHP -= vec[i].attack * (turn-1);  //HP차감
        }
        else if(vec[i].type == 2){  //포션을 만났을 때
            tmpAtk += vec[i].attack;    //공격력 상승
            curHP = min(curHP+vec[i].health, mxHP); //HP회복 (단, 최대치 넘을 시 최대치로)
        }
        if(curHP <= 0){ //용사가 죽으면 FAIL
            suc = false;
            break;
        }
    }
    return suc;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> atk;
    for(int i=0;i<N;i++){
        room temp;
        cin >> temp.type >> temp.attack >> temp.health;
        vec[i] = temp;
    }
    while(lo <= hi){
        mid = (hi+lo)/2;

        if(check(mid)){
            //cout <<"mid: "<< mid <<endl; #debug
            ans = min(ans,mid);
            hi = mid -1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << ans <<'\n';

    return 0;
}
