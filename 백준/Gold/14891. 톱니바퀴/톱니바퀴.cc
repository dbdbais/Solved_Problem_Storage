//
// Created by newbi on 2024-03-02.
//
#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

vector<int> gear[4];    //0부터 반시계 방향으로

void rotateClock(int idx){  //시계 방향 회전
    gear[idx] = {gear[idx][7],gear[idx][0],gear[idx][1],gear[idx][2],gear[idx][3],gear[idx][4],gear[idx][5],gear[idx][6]};
}

void rotateDeClock(int idx){  //시계 방향 회전
    gear[idx] = {gear[idx][1],gear[idx][2],gear[idx][3],gear[idx][4],gear[idx][5],gear[idx][6],gear[idx][7],gear[idx][0],};
}


int T,K,rIdx,dir;
int rArr[4];
bool visited[4];
bool out(int x){
    return x <0 || x >=4;
}

void check(int idx,int way){
    visited[idx] = true;
    rArr[idx] = way;
    for(int elem : {-1,1}){
        int nxt = idx +elem;
        if(out(nxt)||visited[nxt]) continue;    //나갔거나 이미 방문이라면

        if(elem == -1){ //왼쪽에 위치한 기어라면
            if(gear[idx][6] != gear[nxt][2]){
                check(nxt,way * -1);
            }
            else{
                visited[nxt] = true;    //방문처리
            }
        }
        else{   //오른쪽에 위치한 기어라면
            if(gear[idx][2] != gear[nxt][6]){
                check(nxt,way * -1);
            }
            else{
                visited[nxt] = true;    //방문처리
            }
        }
    }
return;
}
void rotate(){
    For(i,0,4){
        if(rArr[i] == 1){
            rotateClock(i);
        }
        else if(rArr[i] == -1){
            rotateDeClock(i);
        }
    }
}
int count(){
    int cnt = 0;
    int m = 1;
    For(i,0,4){
        if(gear[i][0] == 1){
            cnt = cnt + m;
        }

        m*=2;
    }
    return cnt;
}


int main(){
    fastIO();
    string s;
    For(i,0,4){
        cin >> s;
        For(j,0,8){
            gear[i].push_back(s[j]-'0');
        }
    }
    cin >> K;
        For(i,0,K){
            cin >> rIdx >> dir;
            check(rIdx-1,dir);
            rotate();
            memset(rArr,0,sizeof(rArr));
            memset(visited,false,sizeof(visited));
        }
        cout << count()<<endl;

    return 0;
}

