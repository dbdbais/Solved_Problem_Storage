#include <iostream>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int arr[33];	//현재 위치에 들어있는 값
int _next[33];	//다음위치 저장
int _special[33];	//특별 방문 처리
bool visited[33];	//방문 처리
int ans;
int dice[10];

int curPos[4]; //현재 말의 위치
void init() {
    int val = 2;
    for (int i = 1; i <= 20; i++) {
        arr[i] = val;
        val += 2;
    }
    //서브 노드 처리
    arr[22] = 13;
    arr[23] = 16;
    arr[24] = 19;
    arr[25] = 25;
    arr[26] = 22;
    arr[27] = 24;
    arr[28] = 28;
    arr[29] = 27;
    arr[30] = 26;
    arr[31] = 30;
    arr[32] = 35;

    //이전 다음 노드 처리
    for (int i = 0; i <= 20; i++) {
        _next[i] = i + 1;
    }

    _special[5] = 22;
    _special[10] = 26;
    _special[15] = 28;

    for (int i = 22; i <= 24; i++) {
        _next[i] = i + 1;
    }

    for (int i = 28; i <= 29; i++) {
        _next[i] = i + 1;
    }
    _next[26] = 27;
    _next[27] = 25;
    _next[30] = 25;
    _next[25] = 31;
    _next[31] = 32;
    _next[32] = 20;
    _next[21] = 21;

}

void print() {
    For(i, 0, 33) {
        cout << visited[i] << " ";
    }
    cout <<endl;

}


void DFS(int depth, int score) {
    if (depth == 10) {
        // 최댓값 갱신
        if (ans < score) ans = score;
        return;
    }
    //print();
    For(i,0,4){
        int prev = curPos[i];

        if(prev == 21) continue;    //마지막 점이라면 SKIP
        int cur = prev;
        int diceCnt = dice[depth];


        if(_special[cur] > 0){  //시작부터 특별한 정점으로 갈 수 있따면
            cur = _special[cur];
            diceCnt-=1;
        }

        while(diceCnt--){
            cur = _next[cur];
        }

        if(cur != 21 && visited[cur]) continue;

        visited[prev] = false;  //방문처리
        visited[cur] = true;
        curPos[i] = cur;

        DFS(depth+1,score + arr[cur]);

        visited[prev] = true;   //원복
        visited[cur] = false;
        curPos[i] = prev;
    }


}


int main() {
    fastIO();
    For(i, 0, 10) {		//주사위 입력 받고
        cin >> dice[i];
    }
    init();
    DFS(0, 0);

    cout << ans << endl;

    return 0;
}