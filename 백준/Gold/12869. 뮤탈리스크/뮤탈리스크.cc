//
// Created by newbi on 2023-08-30.
//
#include <iostream>
#include <tuple>
#include <queue>
int visited[61][61][61];    //최대 방문 수
int atk[6][3]= {    //뮤탈리스크의 공격 조합
        {9, 3, 1},
        {9, 1, 3},
        {3,1,9},
        {3,9,1},
        {1,3,9},
        {1,9,3}
};
int scv[3]; //scv 체력 담는 배열

using namespace std;

void BFS(int x,int y, int z){
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(x,y,z));
    visited[x][y][z]=1;
    while(!q.empty()){
        auto cord = q.front();
        q.pop();
        x = get<0>(cord);
        y = get<1>(cord);
        z = get<2>(cord);

        if(x ==0 && y==0 && z==0){  //모든 scv의 체력이 0을 달성하면 종료
            break;
        }

        for(int i=0;i<6;i++){
            int qx = max(0,x - atk[i][0]);  //음수로 이동하는 것을 방지
            int qy = max(0,y - atk[i][1]);  //음수로 이동하는 것을 방지
            int qz = max(0,z - atk[i][2]);  //음수로 이동하는 것을 방지

            if(visited[qx][qy][qz]) continue;   //방문한 곳이 있다면 SKIP
            visited[qx][qy][qz] = visited[x][y][z]+1;   //최소 시간 저장
            q.push(make_tuple(qx,qy,qz));   //다음 연산을 위해 큐에 집어넣음
        }
    }
    cout << visited[0][0][0]-1<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> scv[i];
    }
    BFS(scv[0],scv[1],scv[2]);

    return 0;
}