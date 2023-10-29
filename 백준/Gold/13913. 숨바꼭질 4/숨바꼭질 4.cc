//
// Created by newbi on 2023-09-02.
//

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
vector<int> visited(200001,0);  //최단거리 확인 vector
vector<int> route(200001,0);     //이전 거리 저장 vector
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now == K)
            break;
        for (int next: {now - 1, now + 1, now * 2}) {   //다음 경우의 수 BFS
            if (0 > next || next > 200000) continue;    //정상적인 범위 아니라면 continue
            if (visited[next]) continue;    //방문한 정점이라면 continue
            visited[next] = visited[now] + 1;   //가장 빠른 시간 update
            route[next] = now;      //어디서 시작했는지 루트를 남겨둔다.
            q.push(next);   //next값 집어 넣음
        }
    }
    vector<int> vec;
    for(int i=K;i != N;i = route[i]){
        vec.push_back(i);
    }
    vec.push_back(N);
    reverse(vec.begin(),vec.end());

    cout << visited[K]-1 << '\n';

    for(auto elem: vec){
        cout <<elem<<" ";
    }
    cout<<'\n';
    return 0;
}