//
// Created by newbi on 2023-10-02.
//
#include<iostream>
using namespace std;
int N,S,R, team[12],cnt;

int main(){

    int tmp;
    cin >> N >> S >> R;
    for(int i=0;i<S;i++){
        cin >> tmp;
        team[tmp]--;
    }
    for(int i=0;i<R;i++){
        cin >> tmp;
        team[tmp]++;
    }

    for(int i =1;i<=N;i++){
        if(team[i] >0){
            if(team[i-1]<0){
                team[i]--;
                team[i-1]++;
                continue;
            }
            else if(team[i+1]<0){
                team[i]--;
                team[i+1]++;
                continue;
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(team[i]<0) cnt++;
    }

    cout << cnt <<'\n';

    return 0;
}