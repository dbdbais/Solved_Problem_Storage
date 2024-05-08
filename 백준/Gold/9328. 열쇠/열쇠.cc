//
// Created by newbi on 2024-05-08.
//
#include <iostream>
#include <string>
#include <cstring>
#include <queue>

#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int T, H, W , ans;

char arr[103][103];
bool key[26];

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

bool visited[103][103];	//열쇠랑을 체크할 배열

bool out(int x, int y) {
    return x < 1 || y < 1 || x > H || y > W;
}

/*
외곽에서 BFS돌리면서 열쇠를 잡으면 체킹 후 다시 돌리고 없다면 끝냄
문서를 잡으면 문서위치 빈공간으로 바꾸고 카운팅 후 출력
방문 배열 역시 돌릴 떄마다 초기화
*/

void print(){
    cout <<"arr" << endl;
    For(i,1,H+1){
        For(j,1,W+1){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
    cout <<"visited" << endl;
    For(i,1,H+1){
        For(j,1,W+1){
            cout << visited[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Key : " ;
    For(i,0,26){
        cout << key[i] <<" ";
    }
    cout << endl;
}

bool BFS(int x,int y){
    bool kFound = false;
    char val = arr[x][y];

    if(isupper(val)){
        if(!key[val-'A']) return kFound;
    }
    if(islower(val)){
        if(!key[val-'a']) {
            arr[x][y] ='.';
            key[val - 'a'] = true;
            kFound = true;
        }
    }
    if(val =='$'){
        ans++;
        arr[x][y] ='.';
    }
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(q.size()){
        auto cur = q.front();q.pop();
        int curX = cur.first;
        int curY = cur.second;

        For(i,0,4){
            int qx = curX + dx[i];
            int qy = curY + dy[i];
            if(out(qx,qy) || visited[qx][qy] || arr[qx][qy] == '*') continue;
            char qval = arr[qx][qy];
            if(isalpha(qval)){
                if(isupper(qval)){
                    if(!key[qval-'A']) continue;
                }
                else{
                    key[qval-'a'] = true;
                    arr[qx][qy] ='.';
                    kFound = true;
                }
            }
            else if(qval =='$'){
                ans++;
                arr[qx][qy] ='.';
            }
            visited[qx][qy] = true;
            q.push({qx,qy});

        }

    }
    return kFound;

}

bool isIn(int x,int y){
    return x == 1 || y == 1 || x ==H || y == W;
}

void reset(){
    ans = 0;
    memset(key,false,sizeof(key));
}

void solve(){
    bool going;
    do{
        going = false;
        For(i,1,H+1){
            For(j,1,W+1){
                if(isIn(i,j) && !visited[i][j] && (arr[i][j] != '*')){
                    //cout << i <<", " <<j << endl;
                    if(BFS(i,j)){
                        //cout <<"found" <<endl;
                        going = true;
                    }
                    //print();
                }
            }
        }
        memset(visited,false,sizeof(visited));
    }while(going);

    cout << ans << endl;
}


void input() {
    string k;
    string s;
    For(i, 1, H + 1) {
        cin >> s;
        For(j, 1, W + 1) {
            arr[i][j] = s[j - 1];
        }
    }
    cin >> k;
    if (k != "0") {
        for (char c : k) {
            key[c - 'a'] = true;
        }
    }
}




int main() {
    fastIO();
    cin >> T;
    For(t,0,T){
        cin >> H >> W;
        input();
        //print();
        solve();
        reset();
    }
    return 0;
}