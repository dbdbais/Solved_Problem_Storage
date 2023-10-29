//
// Created by newbi on 2023-10-14.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int chains [4][8];
int K;
bool clkWise[4];    //톱니의 시계방향 체크
bool visited[4];    //톱니의 방문 여부
void rotateDeClock(int which);
void rotateClock(int which);

void solve(int which){
    vector<int> tmp;

    if(which ==0){
        if(chains[which][2] != chains[which+1][6] && !visited[which+1]){
            tmp.push_back(which+1);
        }
    }
    else if(which == 1){
        if(chains[which][2] != chains[which+1][6] && !visited[which+1]){
            tmp.push_back(which+1);
        }
        if(chains[which][6] != chains[which-1][2] && !visited[which-1]){
            tmp.push_back(which-1);
        }
    }
    else if(which == 2){
        if(chains[which][2] != chains[which+1][6] && !visited[which+1]){
            tmp.push_back(which+1);
        }
        if(chains[which][6] != chains[which-1][2] && !visited[which-1]){
            tmp.push_back(which-1);
        }


    }
    else if(which == 3){
        if(chains[which][6] != chains[which-1][2] && !visited[which-1]){
            tmp.push_back(which-1);
        }
    }

    visited[which] = true;

    if(clkWise[which]){
        rotateClock(which);
    }
    else{
        rotateDeClock(which);
    }
    for(auto elem : tmp){
        solve(elem);
    }


}
void rotateClock(int which){
    int *chain = chains[which];
    int tmp = chain[7];
    for(int i= 7;i>0;i--){
        chain[i] = chain[i-1];
    }
    chain[0] = tmp;
}
void rotateDeClock(int which){
    int *chain = chains[which];
    int tmp = chain[0];
    for(int i= 0;i<7;i++){
        chain[i] = chain[i+1];
    }
    chain[7] = tmp;
}

void reset(){
    memset(visited,false,sizeof(visited));
    memset(clkWise,false,sizeof(clkWise));
}
void print(){
    for(auto chain : chains){
        for(int i=0;i<8;i++){
            cout << chain[i]<<" ";
        }
        cout <<endl;
    }
}
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void setDirection(int which,bool isClk){
    for(int i=0;i<4;i++){
        if(i%2 == 0) {
            clkWise[(which + i) % 4] = isClk;
        }
        else{
            clkWise[(which + i) % 4] = !isClk;
        }
    }
}
int calc(){
    int sm = 0 ;
    for(int i=0;i<4;i++){
        if(chains[i][0] == 1) {
            sm += pow(2, i);
        }
    }
    return sm;
}
int main(){

    fastIO();
    string st;

    for(int i=0;i<4;i++){
        cin >> st;
        for(int j=0;j<8;j++){
            chains[i][j] = st[j]-'0';
        }
    }

    int where;
    int direc;
    cin >> K;
    for(int i=0;i<K;i++){
        cin >> where >> direc;
        if(direc == 1){
            setDirection(where-1,true);
        }
        else if(direc == -1){
            setDirection(where-1,false);
        }
        solve(where-1);
        //print();
        reset();
    }
    cout << calc() << '\n';
    return 0;
}