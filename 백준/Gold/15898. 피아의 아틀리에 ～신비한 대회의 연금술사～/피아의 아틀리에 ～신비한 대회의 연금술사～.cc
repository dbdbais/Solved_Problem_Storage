//
// Created by newbi on 2024-06-09.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;

int N,ans;
//가마순서
int cArr[3];
//돌리는 순서
int pArr[3];
//좌표 순서
int coArr[4];
//순서 있는 순열
bool isSel[10];

const pair<int,int> cord[4] = {{0,0},{0,1},{1,0},{1,1}};

//재료와 색깔
int vec [11][4][4];
char color[11][4][4];

//최종 계산할 곳
int aVec[5][5];
char cVec[5][5];

void reset(){
    memset(aVec,0,sizeof(aVec));
    fill(&cVec[0][0],&cVec[0][0]+5*5,'W');
}

void output(){
    cout << "AVEC" << endl;
    For(i,0,5){
        For(j,0,5){
            cout << aVec[i][j]<<" ";
        }
        cout << endl;
    }
    cout <<endl;
    cout << "CHAR" << endl;
    For(i,0,5){
        For(j,0,5){
            cout << cVec[i][j]<<" ";
        }
        cout << endl;
    }
    cout <<endl;
}

void calc(){
    int R = 0,B = 0,G = 0,Y = 0;
    For(i,0,5){
        For(j,0,5){
            if(cVec[i][j] == 'R'){
                R += aVec[i][j];
            }
            else if(cVec[i][j] == 'B'){
                B += aVec[i][j];
            }
            else if(cVec[i][j] == 'G'){
                G += aVec[i][j];
            }
            else if(cVec[i][j] == 'Y'){
                Y += aVec[i][j];
            }
        }
    }
    int score = R * 7 + B * 5 + G * 3 + Y * 2;
    if(ans < score) ans = score;
}

// 좌표, 몇번째 재료, 몇번 돌릴건지
void rotateNplus(pair<int,int> co,int c,int rn){
    int temp[4][4];
    int rotTemp[4][4];
    char cTemp[4][4];
    char rotC[4][4];

    copy(&vec[c][0][0],&vec[c][0][0]+4*4,&temp[0][0]);
    copy(&color[c][0][0],&color[c][0][0]+4*4,&cTemp[0][0]);
    copy(&vec[c][0][0],&vec[c][0][0]+4*4,&rotTemp[0][0]);
    copy(&color[c][0][0],&color[c][0][0]+4*4,&rotC[0][0]);



    For(a,0,rn){
        For(i,0,4){
            For(j,0,4){
                rotTemp[i][j] = temp[3-j][i];
                rotC[i][j] = cTemp[3-j][i];
            }
        }
        copy(&rotTemp[0][0],&rotTemp[0][0]+4*4,&temp[0][0]);
        copy(&rotC[0][0],&rotC[0][0]+4*4,&cTemp[0][0]);

    }
    //원하는 만큼 돌리고
    int dx = co.first;
    int dy = co.second;

    For(i,0,4){
        For(j,0,4){
            int qx = i+dx;
            int qy = j+dy;
            //보정값 더하고
            int qVal = aVec[qx][qy] + rotTemp[i][j];
            //더한다.
            if(qVal < 0){
                qVal = 0;
            }
            else if(qVal >9){
                qVal =9;
            }
            aVec[qx][qy] = qVal;
            //대입
            if(rotC[i][j] !='W'){
                cVec[qx][qy] = rotC[i][j];
            }
            //흰색이 아니라면 원하는 색깔로 덮어씌움.
        }
    }



}

void cPermutation(int idx){
    if(idx == 3){
        reset();
        //결과 배열 초기화
        For(i,0,3){
            //cout << coArr[i] <<", " << cArr[i] <<", " << pArr[i] <<", "<<endl;
            rotateNplus(cord[coArr[i]],cArr[i],pArr[i]);
            //output();
        }
        //각자 배열 돌리고 aVec에 더한 후에 값 계산해서 최대값 갱신
        calc();

        return;
    }
    For(i,0,4){
        coArr[idx] = i;
        cPermutation(idx+1);
    }
}

void rPermutation(int idx){
    if(idx == 3){
        cPermutation(0);
        //좌표 중복 순열
        return;
    }
    For(i,0,4){
        pArr[idx] = i;
        rPermutation(idx+1);
     }

}

//N개중에 3개 순서 있이 선택 어떻게 가마에 적용할건지
void perm(int idx){
    if(idx == 3){
        //어떻게 돌릴건지 (중복 순열)
        rPermutation(0);
        return;
    }
    For(i,0,N){
        if(isSel[i]) continue;
        cArr[idx] = i;
        isSel[i] = true;
        perm(idx+1);
        isSel[i] = false;
    }

}

void input(){
    For(a,0,N){
        For(i,0,4){
            For(j,0,4){
               cin >> vec[a][i][j];
            }
        }
        For(i,0,4){
            For(j,0,4){
                cin >> color[a][i][j];
            }
        }
    }
}



int main(){
    fastIO();
    cin >> N;
    reset();
    input();
    perm(0);
    cout << ans << endl;
    return 0;
}