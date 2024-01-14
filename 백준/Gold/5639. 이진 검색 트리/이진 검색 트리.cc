//
// Created by newbi on 2024-01-14.
//
#include <iostream>
using namespace std;
int tree[40000];
int idx;

void solve(int start,int end){
    if(start >= end) return;    //재귀 종료 조건
    int partition;
    int cur = tree[start];  //현재 트리 값
    for(partition=start+1;partition<end;partition++){
        if(cur < tree[partition]){   // 처음으로 큰값 발견 시
            break;
        }
    }

    solve(start+1,partition);   //왼쪽 자식 노드 배열
    solve(partition,end);   //오른쪽 자식 노드 배열
    cout << cur <<'\n'; //LRV 순으로 출력한다.
    return;
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();

    int num;
    while (cin >> num) {
        tree[idx++] = num;
    }
    solve(0,idx);

    return 0;
}
