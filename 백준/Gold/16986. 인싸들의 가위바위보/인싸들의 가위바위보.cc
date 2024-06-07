//
// Created by newbi on 2024-06-06.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

using namespace std;

int N,K;
int A[11][11];
int learn[4][22];

void input(){
    cin >> N >> K;

    For(i,1,N+1){
        For(j,1,N+1){
            cin >> A[i][j];
        }
    }
    For(i,0,20){
        cin >> learn[2][i];
    }

    For(i,0,20){
        cin >> learn[3][i];
    }
}
int winCnt[4];
bool canWin;
bool isPlayed[4];
bool isSel[10];

int gCnt,mCnt;

//플레이어  앞이 이기면 1, 뒤가 이기면 -1, 무승부면 0
int play(int a,int b){
    int res = A[a][b];
    if(res == 2){
        return 1;
    }
    else if(res == 0){
        return -1;
    }
    else if (res == 1){
        return 0;
    }
}
void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
bool allUsed(){
    For(i,1,N+1){
        if(isSel[i] == false) return false;
    }
    return true;
}

void DFS(int turn,int a,int b){
    //  NonPromising 가지치기
    if(canWin || winCnt[2] >= K || winCnt[3]>=K){
        return;
    }
    //지우가 이겼다면
    if(winCnt[1] >= K ){
        //cout << "============ found ============" << endl;
        canWin = true;
        return;
    }
    if(a > b){
        swap(a,b);
    }
    //게임의 결과가 저장
    int res,winner,notPlayed;
    //게임 했다.
    //1일 경우 다음 패를 찾지 못했다면
    int tmpCnt[4];
    int tmpSel[10];
    int tgCnt,tmCnt;
    if(a == 1 ){
        copy(winCnt,winCnt+4,tmpCnt);
        copy(isSel,isSel+10,tmpSel);
        tgCnt = gCnt;
        tmCnt = mCnt;
        int aT = 0;
        For(i,1,N+1){
            isPlayed[a] = true;
            isPlayed[b] = true;
            gCnt = tgCnt;
            mCnt = tmCnt;
            copy(tmpCnt,tmpCnt+4,winCnt);
            copy(tmpSel,tmpSel+10,isSel);
            //스코어,선택 원복
            if(isSel[i]) continue;
            aT = i;
            isSel[aT] = true;
            int bT;
            if(b == 2){
                bT = learn[b][gCnt++];
            }
            else{
                bT = learn[b][mCnt++];
            }

            res = play(aT,bT);
            if(res == 1){
                winner = a;
            }
            else{
                winner = b;
            }
            For(z,1,4){
                if(isPlayed[z]) continue;
                notPlayed = z;
                break;
            }
            memset(isPlayed,false,sizeof(isPlayed));
            winCnt[winner]++;
            /*
            cout << a <<" : "<< b <<" played"<< endl;
            cout << "aT : " << aT <<" gCnt : " <<gCnt << " mCnt :" << mCnt <<  endl;
            cout <<"turn: "<< turn << endl;
            cout << "winner : "<< winner << endl;
            cout << "winCnt: " ;
            For(z,1,4){
                cout << winCnt[z] <<" , ";
            }
            cout <<endl;
            cout << "isSEL: " ;
            For(z,1,N+1){
                cout << isSel[z] << " , ";
            }
            cout << endl;
             */
            //이겼다 표시
            DFS(turn+1,winner,notPlayed);
        }
    }
    else{
        isPlayed[a] = true;
        isPlayed[b] = true;
        //해당 턴에 해당하는 패
        int aT = learn[a][gCnt++];
        int bT = learn[b][mCnt++];

        res = play(aT,bT);
        //결과
        if(res == 1){
            winner = a;
        }
        else{
            winner = b;
        }

        For(i,1,4){
            if(isPlayed[i]) continue;
            notPlayed = i;
            break;
        }

        memset(isPlayed,false,sizeof(isPlayed));
        winCnt[winner]++;
        /*
        cout << a <<" : "<< b <<" played"<< endl;
        cout <<"gCnt : " <<gCnt << " mCnt :" << mCnt <<  endl;
        cout <<"turn: "<< turn << endl;
        cout << "winner : "<< winner << endl;
        cout << "winCnt: " ;
        For(z,1,4){
            cout << winCnt[z] <<" , ";
        }
        cout <<endl;
         */
        DFS(turn+1,winner,notPlayed);
        //다음으로
    }
}

int main(){
    fastIO();
    input();
    //permutation(0);
    DFS(1,1,2);
    cout << canWin << endl;
    return 0;
}