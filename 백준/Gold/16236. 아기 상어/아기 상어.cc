//
// Created by newbi on 2023-08-14.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int x,y; //현재 위치를 나타내 줄 전역 좌표
queue<pair<int,int>> q;

void BFS(vector<vector<int>> & vec ,vector<vector<int>> & distance,int n){
    int shark = 2; // 아기상어 사이즈
    int fish = 0;  // 먹은 물고기 수
    int result =0; // 이동거리
    vector<pair<int,int>> canEat;
    while(true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = -1;
            }
        }
    distance[x][y] = 0; //현재 거리 0으로
    vec[x][y] = 0;     //현재 위치 0으로

    if (fish >= shark) {    //상어가 요구된 물고기 먹으면 크기 증가
        fish -= shark;
        shark++;
    }
    q.push(make_pair(x,y));

    while (!q.empty()) {
        auto cord = q.front();  //큐에서 가져올 저장된 좌표들
        q.pop();
        for (int i = 0; i < 4; i++) {
            int qx = cord.first + dx[i];
            int qy = cord.second + dy[i];

            if ((qx < 0 || qx >= n) || (qy < 0 || qy >= n) ) continue; //맵을 벗어날 경우

            if(distance[qx][qy] != -1) continue; //distance가 빈공간이 아닐 경우

            if(vec[qx][qy]> shark) continue; //상어보다 큰 물고기가 있을 경우

            if (vec[qx][qy] == 0 || vec[qx][qy]== shark) {    //같은 사이즈의 물고기거나 빈 공간인 경우
                distance[qx][qy] = distance[cord.first][cord.second] + 1;
                q.push(make_pair(qx, qy));
                }
            else if (vec[qx][qy] < shark && vec[qx][qy] >= 1) {   //먹을 수 있는 물고기 있는 경우 canEat vector에 추가
                    distance[qx][qy] = distance[cord.first][cord.second] + 1;
                    canEat.push_back(make_pair(qx, qy));
                    q.push(make_pair(qx, qy));
                }
        }
    }
    //모든 순회가 끝난 경우
    if (canEat.size() == 0) {  //먹을 수 있는 물고기가 없는 경우
        cout << result << '\n';
        break;
    }
    else if (canEat.size() == 1) { //먹을 수 있는 물고기가 하나인 경우
        x = canEat[0].first;
        y = canEat[0].second;
        vec[x][y] = 0;
        fish++;
        result += distance[x][y];
        canEat.pop_back();  // 중요! 이것때매 엄청 헤멨다. canEat을 pop해줘야 종료 가능
    }
    else { // 물고기가 두개 이상 (핵심 코드)
        int minDistance = 99999;
        for (auto elem: canEat) { //가장 가까운 물고기의 거리 측정
            minDistance = min(minDistance, distance[elem.first][elem.second]);
        }
        vector<pair<int, int>> sameDistFish; //동일 거리의 물고기가 있는 지 확인
        for (auto elem: canEat) {
            if (minDistance == distance[elem.first][elem.second])
                sameDistFish.push_back(make_pair(elem.first, elem.second));
        }
        if (sameDistFish.size() > 1) { // 1보다 크다면 정렬해서 맨왼쪽 맨 상단이 위치하게 바꿈
            sort(sameDistFish.begin(), sameDistFish.end());
        }
        x = sameDistFish[0].first;
        y = sameDistFish[0].second;
        vec[x][y] = 0;
        result += distance[x][y];
        fish++;
        canEat.clear(); //중요! 다음 탐색을 위해 잡은 물고기 전부 비움.
    }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> vec(n,vector<int>(n,0));
    vector<vector<int>> distance(n,vector<int>(n,-1));
    pair<int ,int> cord;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin >> vec[i][j];
            if(vec[i][j]==9) {
                x=i;
                y=j;
            }
        }
    }
    BFS(vec,distance,n);
    return 0;
}