//
// Created by newbi on 2024-06-18.
//
#include <iostream>
#include <queue>
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;

int N, Q;

bool visited[1050000];
queue<int> ipt;

int main(){
    fastIO();
    cin >> N >> Q;
    int tmp;
    For(i,0,Q){
        cin >> tmp;
        ipt.push(tmp);
    }
    while(ipt.size()){
        int cur = ipt.front(); ipt.pop();
        bool isOk = true;
        int tp = cur;
        //연산을 위해 임시저장
        while(tp){
            //0이상이면 계속 진행
            if(visited[tp]){
                //어딘가를 방문 했다면
                isOk = false;
                cur = tp;
            }
            tp /= 2;
            //2씩 나눈다.
        }
        if(isOk){
            visited[cur] = true;
            //방문처리하고
            cout << 0 << endl;
        }
        else{
            cout << cur << endl;
        }
    }

    return 0;
}