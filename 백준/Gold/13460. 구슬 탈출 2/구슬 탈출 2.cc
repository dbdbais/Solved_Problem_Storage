//
// Created by newbi on 2024-03-25.
//
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M;

char arr[10][10];
const int dx[]={0,0,1,-1};  //좌우 하상
const int dy[] = {-1,1,0,0};
int rx,ry,bx,by,ans = 11;
bool rfound,bfound;

void print(){
    For(i,0,N){
        For(j,0,M){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void rMove(int dir){
    while(true){
        int qx = rx + dx[dir];
        int qy = ry + dy[dir];
        if(arr[qx][qy] =='#' || arr[qx][qy]=='B') break;

        arr[rx][ry] ='.';   //원복

        rx = qx;
        ry = qy;
        if(arr[rx][ry] =='O'){
            rfound = true;
            break;
        }
        arr[rx][ry] = 'R';
    }
}

void bMove(int dir){

    while(true){
        int qx = bx + dx[dir];
        int qy = by + dy[dir];
        if(arr[qx][qy] =='#' || arr[qx][qy]=='R') break;

        arr[bx][by] ='.';   //원복

        bx = qx;
        by = qy;

        if(arr[bx][by] =='O'){
            bfound = true;
            break;
        }
        arr[bx][by] = 'B';
    }
}

void solve(int cnt){
    if(ans <= cnt){  //ans와 같거나 크가면 리턴
        return;
    }

    int t_rx = rx;
    int t_ry = ry;
    int t_bx = bx;
    int t_by = by;
    char tempArr [10][10];

    copy(&arr[0][0],&arr[0][0]+10*10,&tempArr[0][0]);   //임시저장

    //cout << cnt <<endl;
    For(i,0,4){

        if(i<2){    //수평이동
            if(rx == bx){
                if(i ==0){  //좌
                    if(ry < by){    //빨간 구슬이 왼쪽에 있따면
                        rMove(i);
                        bMove(i);
                    }
                    else{
                        bMove(i);
                        rMove(i);
                    }
                }
                else{   //우
                    if(ry < by){    //빨간 구슬이 왼쪽에 있따면
                        bMove(i);
                        rMove(i);
                    }
                    else{
                        rMove(i);
                        bMove(i);
                    }
                }
            }
            else{
                rMove(i);
                bMove(i);
            }
        }
        else{   //수직이동
            if(ry == by){   //같은 열에 있다면
                if(i == 2){ //하
                    if(rx < bx){    //빨간 공이 위에 있다면
                        bMove(i);
                        rMove(i);
                    }
                    else{
                        rMove(i);
                        bMove(i);
                    }
                }
                else{   //상
                    if(rx < bx){    //빨간 공이 위에 있다면
                        rMove(i);
                        bMove(i);
                    }
                    else{
                        bMove(i);
                        rMove(i);
                    }
                }
            }
            else{
                rMove(i);
                bMove(i);
            }
        }
        //cout << i <<": i move"<<endl;
        //cout <<"rx :" << rx << " ry :" <<ry <<endl;
        //cout <<"bx :" << bx << " by :" <<by <<endl;
        //print();
        if(bfound||(rx == t_rx && ry == t_ry && bx == t_bx && by == t_by)){  //파란공이 들어갔다면
            //cout << "same or blue ball"<<endl;
            copy(&tempArr[0][0],&tempArr[0][0]+10*10,&arr[0][0]);
            rx = t_rx;
            ry = t_ry;
            bx = t_bx;
            by = t_by;
            bfound = false;
            rfound = false;
            continue;
        }
        if(rfound && !bfound){  //빨간공은 들어가고, 파란공은 들어가지 않았을 경우
            //cout << "red ball got in"<<endl;
            if(ans > cnt) ans = cnt;
            break;
        }
        solve(cnt+1);   //다음 경우의 수로 넘어간다.
        //다음 탐색을 위해 원복
        copy(&tempArr[0][0],&tempArr[0][0]+10*10,&arr[0][0]);
        rx = t_rx;
        ry = t_ry;
        bx = t_bx;
        by = t_by;
        bfound = false;
        rfound = false;
    }
}



void input(){
    For(i,0,N){
        For(j,0,M){
            cin >> arr[i][j];
            if(arr[i][j] =='R'){
                rx = i;
                ry = j;
            }
            else if(arr[i][j] =='B'){
                bx = i;
                by = j;
            }
        }
    }
}

int main(){
    fastIO();
    cin >> N >>M;
    input();

    solve(1);
    if(ans >10) ans = -1;
    cout << ans << endl;



    return 0;
}