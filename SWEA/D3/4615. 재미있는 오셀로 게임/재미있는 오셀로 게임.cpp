//
// Created by newbi on 2023-11-17.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int T,N,M;
int arr[10][10];

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

bool out(int x,int y){  //나갔다면
    return (x<1 || x >N || y <1 || y >N);
}
void init(){    //초기화
    int ix = N/2;
    int iy = N/2;
    arr[ix][iy] = 2;
    arr[ix+1][iy] = 1;
    arr[ix+1][iy+1] = 2;
    arr[ix][iy+1] = 1;
}

void solve(int x,int y, int color){

    for(int i=0;i<8;i++){
        vector<pair<int,int>> v;
        int qx = x;
        int qy = y;
        while(true){
            qx = qx + dx[i];
            qy = qy + dy[i];
            if(out(qx,qy) ) {
                v.clear();
                break;
            }   //나갔다면 루프 끊고 나간다.

            if(arr[qx][qy] == color){   //같은 컬러라면
                break;
            }
            else if(arr[qx][qy] ==0){   //공란이라면
                v.clear();
                break;
            }
            else{   //다른 컬러라면
                v.push_back({qx,qy});
            }
        }

        for(auto elem: v){
            arr[elem.first][elem.second] =color;    //거쳐왔던 다른 돌들을 본인의 색으로 바꾼다
        }
    }
    return;
}
void print(){
    int b=0,w=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j] == 1) b++; //흑돌 카운트
            else if(arr[i][j] == 2) w++;    //백돌 카운트
        }
    }
    cout << b <<" "<<w<<'\n';
}

int main(){
    int x,y,color;
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> N >> M;
        init();
        for(int j=0;j<M;j++){
            cin >> x >> y >> color;
            arr[x][y] =color;
            solve(x,y,color);
        }
        cout<<"#"<<i<<" ";
        print();
        memset(arr,0,sizeof(arr));  //바둑판 초기화


    }

    return 0;
}