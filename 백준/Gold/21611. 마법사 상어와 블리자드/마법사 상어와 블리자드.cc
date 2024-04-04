//
// Created by newbi on 2024-04-04.
//


#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i, a, b) for(int i=a;i<b;i++)

using namespace std;

int N, M, sharkX, sharkY, d, s;
int score[4];
int arr[50][50];

const int dx[] = {-1, 1, 0, 0};        //상 하 좌 우
const int dy[] = {0, 0, -1, 1};

const int tx[] = {0, 1, 0, -1};        //좌 하 우 상
const int ty[] = {-1, 0, 1, 0};

vector<int> vec;

bool out(int x, int y) {
    return x < 0 || y < 0 || x >= N || y >= N;
}

void input() {
    For(i, 0, N) {
        For(j, 0, N) {
            cin >> arr[i][j];
        }
    }
}

void print() {
    cout << endl;
    For(i, 0, N) {
        For(j, 0, N) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void destroy(int d, int s) {    //방향 d와 거리 s
    int curX = sharkX;
    int curY = sharkY;
    while (s--) {
        int qx = curX + dx[d];
        int qy = curY + dy[d];

        if (out(qx, qy)) break;

        if (arr[qx][qy] != 0) {
            arr[qx][qy] = -1;    //삭제할 거 표시
        }

        curX = qx;
        curY = qy;

    }

}


void tornado(int x, int y) {    //토네이도 처럼 돌면서 벡터에 구슬을 넣는다.

    int dir = 0;
    int depth = 1;
    int cnt = 1;
    bool done = false;
    while (cnt < N * N) {

        for (int d = 0; d < depth; d++) {
            int qx = x + tx[dir];
            int qy = y + ty[dir];

            if (out(qx, qy) || arr[qx][qy] == 0) {
                done = true;
                break;
            }
            if (arr[qx][qy] != -1) {
                vec.push_back(arr[qx][qy]);    //벡터에 집어 넣는다.
            }
            cnt++;

            x = qx;
            y = qy;
        }

        if (done) break;

        dir = (dir + 1) % 4;
        if (dir % 2 == 0) {        //방향이 짝수로 나뉘어진다면
            depth++;
        }
    }

}

void tornadoColor(int x, int y) {
    int dir = 0;
    int depth = 1;
    bool done = false;
    int cnt = 1;

    memset(arr, 0, sizeof(arr));    //배열 초기화

    while (cnt < N * N) {
        for (int d = 0; d < depth; d++) {
            int qx = x + tx[dir];
            int qy = y + ty[dir];
            if (out(qx, qy) || vec.size() < cnt) {
                done = true;
                break;
            }
            arr[qx][qy] = vec[cnt - 1];
            cnt++;

            x = qx;
            y = qy;
        }

        if (done) break;

        dir = (dir + 1) % 4;
        if (dir % 2 == 0) {        //방향이 짝수로 나뉘어진다면
            depth++;
        }
    }
}


bool explode() {
    vector<int> ret;
    bool found = false;
    bool done = false;
    int idx = 0;
    while (!done) {
        if (vec.empty()) break;
        //cout << "IDX : " << idx << endl;
        if (vec.size() - 1 - idx < 4) {
            for (int a = idx; a < vec.size(); a++) {
                ret.push_back(vec[a]);
            }
            break;
        }

        int cur = vec[idx]; //현재 원소
        int cnt = 1;


        for (int j = idx + 1; j < vec.size(); j++) {
            int nxt = vec[j];   //다음 원소
           // cout << "J: " << j << endl;
            if (j != vec.size() - 1) { //마지막 인덱스가 아니라면
                if (cur == nxt) {     //현재 원소와 다음원소가 같다면
                    cnt++;
                } else {   //다음원소랑 다르다면
                    if (cnt < 4) {
                        for (int a = idx; a < j; a++) {
                            ret.push_back(vec[a]);  //안 터진 원소 집어넣는다.
                        }
                    } else {
                        score[cur] += cnt;
                        found = true;
                    }
                    idx = j;    //인덱스 업데이트
                    break;
                }
            } else {   //마지막 인덱스라면 nxt가 마지막 원소
                if (cur == nxt) {     //현재 원소와 다음원소가 같다면
                    cnt++;
                    if (cnt < 4) {
                        for (int a = idx; a < j + 1; a++) {
                            ret.push_back(vec[a]);  //안 터진 원소 집어넣는다.
                        }
                    } else {
                        score[cur] += cnt;
                        found = true;
                    }
                } else {   //다음 원소와 다르다면
                    ret.push_back(nxt);
                    if(cnt >= 4){
                        score[cur] += cnt;
                        found = true;
                    }
                }
                done = true;
            }

        }
    }
    if (found) {
        vec = ret;
        return true;
    } else {
        return false;
    }
}


void change() {    //변화하는 구슬

    vector<int> cVec;
    int idx = 0;

    while (true) {    //인덱스가 마지막에 도착하면
        //cout <<"지금: " << idx << " ";

        int cur = vec[idx];    //현재 가리키는 값
        int cnt = 1;
        int j = idx;
        if (idx != vec.size() - 1) {
            for (j = idx; j < vec.size() - 1; j++) {

                if (vec[j + 1] == cur) {    //지금 값과 동일하다면
                    cnt++;
                } else {
                    //cout << j << endl;
                    break;
                }
            }
        }
        if (cVec.size() <= N * N - 1) {    //cVec이 모든 배열의 수보다 작다면 Push
            cVec.push_back(cnt);
            if (cVec.size() <= N * N - 1) {
                cVec.push_back(cur);
            }
        }
        //최종 벡터에 넣는다. 카운팅 숫자와 현재 번호

        idx = j + 1;    //끊긴데서 부터 위치 이동


        if (idx == vec.size()) break;    // 현재 가리키는 인덱스가 벡터의 사이즈와 같을 경우 끝낸다.
    }

    vec = cVec;    //벡터 갱신한다.

}

int getScore() {
    int sm = 0;
    sm += score[1];
    sm += score[2] * 2;
    sm += score[3] * 3;
    return sm;
}

void solve() {
    For(i, 0, M) {
        cin >> d >> s;
        destroy(d - 1, s);
        tornado(sharkX, sharkY);
        tornadoColor(sharkX, sharkY);
        //print();
        while (true) {
            if (!explode()) break;
        }
        tornadoColor(sharkX, sharkY);
        if (vec.size()) {
            change();
            tornadoColor(sharkX, sharkY);
            vec.clear();
        }
        //print();
    }
    cout << getScore() << endl;

}


int main() {
    fastIO();
    cin >> N >> M;
    sharkX = N / 2;
    sharkY = N / 2;
    input();

    solve();

    return 0;
}