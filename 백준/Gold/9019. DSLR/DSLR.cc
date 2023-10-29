//
// Created by newbi on 2023-08-12.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;


int D(int val){
    return (val*2) % 10000;
}
int S(int val){
    int res;
    if(val == 0)
        res = 9999;
    else
        res = val - 1;
    return res;
}
int L(int val){
    int res;
    if(val < 1000){
        res = val * 10;
    }
    else{
        res = val*10;
        res = res +(res/10000); // 초과된 숫자 1의 자리로 보낸다.
        res = res % 10000;  //초과된 10000의 자리 날린다.
    }
    return res;
}
int R(int val){
    int res;
    if(val % 10 ==0){ //1의 자리수가 0이라면 1230
        res = val/10;
    }
    else{
        res = (val % 10)*1000;
        res += ((val/10) % 1000);
    }
    return res;
}


void BFS(int A, int B){
    vector<bool> visited(10001, false);
    queue <pair<int,string>> q;
    q.push(make_pair(A,"")); //첫 스타팅 push

    while(!q.empty()){
        int curNum = q.front().first;   //현재 숫자 (A의 변화과정)
        string curSt = q.front().second;    //지금까지의 명령어
        q.pop();

        if(curNum == B){    //목적지 달성 시 출력
            cout << curSt<<'\n';
            break;
        }
        int temp;

        temp = D(curNum);
        if(!visited[temp]){
            visited[temp] = true;
            q.push(make_pair(temp,curSt+"D"));
        }
        temp = S(curNum);
        if(!visited[temp]){
            visited[temp] = true;
            q.push(make_pair(temp,curSt+"S"));
        }
        temp = L(curNum);
        if(!visited[temp]){
            visited[temp] = true;
            q.push(make_pair(temp,curSt+"L"));
        }
        temp = R(curNum);
        if(!visited[temp]){
            visited[temp] = true;
            q.push(make_pair(temp,curSt+"R"));
        }
    }
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int A,B;
        cin >> A >> B;
        BFS(A,B);
    }

    return 0;
}