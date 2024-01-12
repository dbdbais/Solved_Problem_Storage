//
// Created by newbi on 2024-01-12.
//
#include<iostream>
using namespace std;

int N, M, ans;
bool broke[10]; //리모컨 버튼의 수

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int num){
    if(num ==0){
        if(!broke[0]) return true;
        else return false;
    }
    string s = to_string(num);
    for(auto c : s){    //모든 숫자가 리모콘으로 생성할 수 있는지 체크한다.
        int tmp = c-'0';
        if(broke[tmp]) return false;
    }
    return true;
}

int main(){
    fastIO();
    cin >> N >> M;
    int button;
    for(int i=0;i<M;i++){
        cin >> button;
        broke[button] = true;
    }

    ans = abs(N - 100);

    for(int i=0;i<= 1000000;i++){
        if(check(i)){
            int pressed = to_string(i).size();  //버튼을 누른 횟수
            int diff = abs(i-N);    //그 후 +, -를 이용해 채널로 이동한 횟수
            if(ans > pressed+diff) ans = pressed+diff; //더 최소값일 경우 업데이트
        }
    }

    cout << ans <<'\n';

    return 0;
}