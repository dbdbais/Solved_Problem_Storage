//
// Created by newbi on 2024-02-22.
//
#include <iostream>
#include <algorithm>
#include <vector>

#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n';

using namespace std;

int N, D, W, K, T;
int arr[14][21];
int ans;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool out(int y) {
    return y + K-1 > D;	//지하로 뚫고 들어가는 경우 체크
}
bool isCont(int x,int y) {
    bool f = true;	//찾은 거 확인
    int cur = arr[x][y];	//현재 상태 기억
    For(j,0,K) {
        if (arr[x+j][y] != cur) {	//K개 연속된 것 증 하나라도 현재 상태와 다르다면
            f = false;	//못 찾은거 처리
            break;
        }
    }
    return f;
}

bool check() {
    bool suc;
    For(i, 1, W + 1) {	// 가로 요소 선택
        suc = false;
        For(j, 1, D+1) {	//세로 요소 선택
            if (out(j)) {	//범위를 벗어났다면
                break;
            }
            if (isCont(j,i)) {	//연속인 거 찾았다면
                suc =true;
                break;
            }
        }
        if(!suc) break; //못 찾았다면
    }
    return suc;
}
void print(){
    For(i,1,D+1){
        For(j,1,W+1){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
    cout <<endl;
}

void setColor(int row, int color) {
    For(i, 1, W + 1) {	//해당 행의 모든 색깔 color로 바꿔버림
        arr[row][i] = color;
    }
}


void DFS(int idx,int inject) {
    if(inject >= ans) return;

    if(idx > D){   //끝까지 도달했다면
        if(check()){
            ans = min(ans,inject);
        }
        return;
    }

    DFS(idx+1,inject);

    int temp[21];
    For(i,0,21){
        temp[i] = arr[idx][i];
    }
    setColor(idx,0);
    DFS(idx+1,inject+1);
    setColor(idx,1);
    DFS(idx+1,inject+1);

    For(i,0,21){
        arr[idx][i] = temp[i];
    }
    //원복
}

int main() {
    fastIO();
    cin >> T;

    For(t, 1, T + 1) {
        cin >> D >> W >> K;

        For(i, 1, D+1) {
            For(j, 1, W + 1) {
                cin >> arr[i][j];
            }
        }

        if(K ==1 || check()){
            ans = 0;
        }
        else {
            ans = K;
            DFS(1, 0);
        }
        cout <<"#"<<t<<" "<< ans << endl;
    }
    return 0;
}