//
// Created by newbi on 2024-03-22.
//
#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int ans = 0;
int board[21][21];
void print(){
    For(i,0,N){
        For(j,0,N){
            cout << board[i][j] <<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}


void move(int dir){ //  상, 우, 하, 좌
    if(dir == 0){   //상
        For(i,0,N){
            deque<int>dq;
            bool cont = false;

            For(j,0,N){
                int cur = board[j][i];  //현재 위치
                if(cur == 0){
                    continue;
                }

                if(dq.size()){ //이전 값이 있다면
                    if(dq.back() == cur && !cont){  //이전값 같고, 연속적이지 않았다면
                        cont = true;
                        dq.pop_back();
                        dq.push_back(cur*2);    //2배해서 넣는다.
                    }
                    else{
                        if(cont) cont =false;
                        dq.push_back(cur);
                    }
                }
                else{   //이전값 없으면 그냥 넣는다.
                    if(cont) cont =false;
                    dq.push_back(cur);
                }
                board[j][i] =0; //초기화
            }
            int idx =0;
            while(dq.size()){
                board[idx++][i] = dq.front();
                dq.pop_front();
            }

        }
    }
    else if(dir == 1){  //우
        For(i,0,N){
            deque<int>dq;
            bool cont = false;

            for(int j= N-1;j>=0;j--){
                int cur = board[i][j];  //현재 위치
                if(cur == 0){
                    continue;
                }

                if(dq.size()){ //이전 값이 있다면
                    if(dq.back() == cur && !cont){  //이전값 같고, 연속적이지 않았다면
                        cont = true;
                        dq.pop_back();
                        dq.push_back(cur*2);    //2배해서 넣는다.
                    }
                    else{
                        if(cont) cont =false;
                        dq.push_back(cur);
                    }
                }
                else{   //이전값 없으면 그냥 넣는다.
                    if(cont) cont =false;
                    dq.push_back(cur);
                }
                board[i][j] =0; //초기화
            }
            int idx =N-1;
            while(dq.size()){
                board[i][idx--] = dq.front();
                dq.pop_front();
            }

        }
    }
    else if (dir == 2){ //하
        For(i,0,N){
            deque<int>dq;
            bool cont = false;

            for(int j= N-1;j>=0;j--){
                int cur = board[j][i];  //현재 위치
                if(cur == 0){
                    continue;
                }

                if(dq.size()){ //이전 값이 있다면
                    if(dq.back() == cur && !cont){  //이전값 같고, 연속적이지 않았다면
                        cont = true;
                        dq.pop_back();
                        dq.push_back(cur*2);    //2배해서 넣는다.
                    }
                    else{
                        if(cont) cont =false;
                        dq.push_back(cur);
                    }
                }
                else{   //이전값 없으면 그냥 넣는다.
                    if(cont) cont =false;
                    dq.push_back(cur);
                }
                board[j][i] =0; //초기화
            }
            int idx =N-1;
            while(dq.size()){
                board[idx--][i] = dq.front();
                dq.pop_front();
            }

        }
    }
    else{   //좌
        For(i,0,N){
            deque<int>dq;
            bool cont = false;

            For(j,0,N){
                int cur = board[i][j];  //현재 위치
                if(cur == 0){
                    continue;
                }

                if(dq.size()){ //이전 값이 있다면
                    if(dq.back() == cur && !cont){  //이전값 같고, 연속적이지 않았다면
                        cont = true;
                        dq.pop_back();
                        dq.push_back(cur*2);    //2배해서 넣는다.
                    }
                    else{
                        if(cont) cont =false;
                        dq.push_back(cur);
                    }
                }
                else{   //이전값 없으면 그냥 넣는다.
                    if(cont) cont =false;
                    dq.push_back(cur);
                }
                board[i][j] =0; //초기화
            }
            int idx =0;
            while(dq.size()){
                board[i][idx++] = dq.front();
                dq.pop_front();
            }

        }
    }

}

void findMax(){
    For(i,0,N){
        For(j,0,N){
            if(board[i][j] > ans) ans = board[i][j];
        }
    }

}


void DFS(int cnt){
    if(cnt == 5){
        //print();
        findMax();
        return;
    }

    int temp[21][21];

    copy(&board[0][0],&board[0][0]+ 21*21,&temp[0][0]);     //임시저장

    For(i,0,4){
        move(i);
        DFS(cnt+1);
        copy(&temp[0][0],&temp[0][0]+ 21*21,&board[0][0]); //원복
    }
}

void input(){
    For(i,0,N){
        For(j,0,N){
            cin >> board[i][j];
        }
    }
}

int main(){
    fastIO();
    cin >> N;
    input();
    DFS(0);

    cout <<ans <<endl;

    return 0;
}