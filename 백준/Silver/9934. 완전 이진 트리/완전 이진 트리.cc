//
// Created by newbi on 2023-09-07.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int k, depth;
vector <int> route(1030,0);   //경로 저장 벡터
vector<bool> visited(1030,false);   //방문 체크
queue<int> q;

void BFS(int idx){
    int level = (idx+1)/2;  //레벨 계산
    q.push(idx);    //부모노드 인덱스
    while(!q.empty()){
        int qSize = q.size();   //레벨 별 순회
        for(int i=0;i<qSize;i++){
            auto c = q.front(); q.pop();
            if(c <0 || c >= depth) continue;    //인덱스가 허용 범위가 아니라면
            if(visited[c]) continue;        //이미 방문한 인덱스 라면 SKIP
            cout << route[c]<<" ";  //레벨 별 출력
            visited[c] = true;
            q.push(c-level);    //다음 왼쪽 자식 집어 넣는다
            q.push(c+level);    //다음 오른쪽 자식 집어 넣는다
        }
        cout << '\n';   //줄바꿈
        level= level/2;    //레벨 2로 나눠서 감소
    }
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    depth= pow(2,k)- 1; //완전이진트리 깊이 산출
    for(int i=0;i< depth ;i++){
        cin >> route[i];    //입력
    }
    BFS(depth/2);

    return 0;
}