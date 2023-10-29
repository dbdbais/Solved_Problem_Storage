//
// Created by newbi on 2023-10-09.
//
#include<iostream>
#include<vector>
using namespace std;
int N,M,J,lft=1,rgt,cnt;
vector<int> apple(20,0);

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();

    cin >> N >> M >> J;

    for(int i=0;i<J;i++){
        cin >> apple[i];
    }
    rgt = M;

    for(int i=0;i<J;i++){
        if(lft<=apple[i] && apple[i]<=rgt){ //바구니 안에 담긴다면
            continue;
        }
        else{
            if(apple[i] < lft){ //사과가 왼쪽에서 떨어진다면
                int diff = lft - apple[i];
                rgt -= diff;
                lft -= diff;
                cnt += diff;
            }
            else if(rgt < apple[i]){    //사과가 오른쪽에서 떨어진다면
                int diff = apple[i] - rgt;
                rgt += diff;
                lft += diff;
                cnt += diff;
            }
        }
    }

    cout << cnt <<'\n';

    return 0;
}