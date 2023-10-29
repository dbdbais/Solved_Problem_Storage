//
// Created by newbi on 2023-09-02.
//
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K,_time=1;
bool found = false;
vector<vector<int>> visited(2,vector<int>(500001,0));  //수빈이가 방문한 벡터 [홀/짝][방문 위치]
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if(N == K) {
        cout << 0 << '\n';
        return 0;
    }
    queue<int> q;
    q.push(N);
    visited[0][N] = 1;  //0초(출발 점)인 수빈이 방문 완료 처리
    while(!q.empty()) {
        K += _time; // 동생의 위치는 계속 가속된다.
        if(K > 500000){ //50만을 넘어가면 끝난다.
            break;
        }
        if(visited[_time%2][K]){    //(중요!)같은 짝수나 홀수의 시간에 이미 동생 위치에 방문을 했다면, +1 -1로 기다리며 버티는게 가능 break
            found = true;
            break;
        }
        int qSize = q.size();   //레벨 별 순회
        for (int i=0;i<qSize;i++) {
            int now = q.front();
            q.pop();
            for (int next: {now - 1, now + 1, now * 2}) { //다음 경우의 수 BFS
                if (0 > next || next > 500000) continue;    //정상적인 범위 아니라면 continue
                if (visited[_time%2][next]) continue;    //이미 방문한 정점이라면 continue
                visited[_time%2][next] = visited[(_time+1)%2][now] + 1;   //짝수시간 -> 홀수, 홀수 -> 짝수 (방문여부만 중요하기 때문에 굳이 1을 더해 줄 필요는 없다.)
                if(next == K){  //다음지점이 K라면 즉, 가속하는 동생을 따라 잡았다면 (통상적인 BFS)
                    found = true;
                    break;
                }
                q.push(next);   //다음 탐색을 위해 next값 집어 넣음
            }

        }
        if(found) break;
        _time++;
    }
    if(found)
        cout << _time << '\n';
    else
        cout << -1 <<'\n';

    return 0;
}