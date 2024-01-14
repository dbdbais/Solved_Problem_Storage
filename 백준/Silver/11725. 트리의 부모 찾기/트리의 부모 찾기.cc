//
// Created by newbi on 2024-01-14.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N,A,B;
vector<int> tree[100004];   //트리의 부모 노드 저장
int parents[100004];
bool visited[100004];

void BFS(int n){
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while(q.size()){
        int cur = q.front(); q.pop();
        for(auto elem : tree[cur]){     //자식 노드 elem에 저장
            if(!visited[elem]){     //방문하지 않았다면..
                visited[elem] = true;   //방문 처리하고
                parents[elem] = cur;
                q.push(elem);   //다음 탐색을 위해 큐에 넣는다.
            }
        }
    }
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();

    cin >> N;
    for(int i=0;i<N-1;i++){
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    BFS(1);
    for(int i=2;i<=N;i++){
        cout << parents[i]<<'\n';
    }
    return 0;
}