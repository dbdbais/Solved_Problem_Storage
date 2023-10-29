//
// Created by newbi on 2023-09-01.
//

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int N, K;
vector<int> visited(100001,0);  //최단거리 확인 vector
vector<int> cnt(100001,0);      //경우의 수 확인 vector
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    cnt[N]= 1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next: {now - 1, now + 1, now * 2}) {   //다음 경우의 수 BFS
            if (0 > next || next > 100000) continue;    //정상적인 범위 아니라면 continue
            if (!visited[next]) {
                visited[next] = visited[now] + 1;   //가장 빠른 시간 update
                cnt[next] += cnt[now];  //경우의 수 이전 것 더함
                q.push(next);   //next값 집어 넣음
            } else if (visited[now] + 1 == visited[next]) { //2번 건너 뛰었을 때 같은 경로가 있다면 그 경로의 경우의 수 까지 더함
                cnt[next] += cnt[now];
            }
        }
    }
        cout << visited[K]-1 << '\n';
        cout << cnt[K] << '\n';

    return 0;
}