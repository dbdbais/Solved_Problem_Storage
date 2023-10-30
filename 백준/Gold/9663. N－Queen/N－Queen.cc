//
// Created by newbi on 2023-10-30.
//
#include<iostream>
using namespace std;
int N,cnt;
int columns[16];


bool check(int row){
    for(int i=0;i<row;i++){
        if(columns[row] == columns[i] || (row -i == abs(columns[row]-columns[i])))  //퀸이 같은 열이나 대각선에 있을 경우
            return false;
    }
    return true;
}


void play(int now){
    if(now==N){
        cnt++;
        return;
    }
    for(int col=0;col<N;col++){
        columns[now]= col;  //원복 필요 x, 다음 으로 이동 시 overwrite.
        if(check(now)){
            play(now+1);
        }
    }
    return;
}

int main(){

    cin >> N;
    play(0);
    cout <<cnt<<'\n';
    return 0;
}