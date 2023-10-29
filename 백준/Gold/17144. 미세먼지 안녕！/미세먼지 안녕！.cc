//
// Created by newbi on 2023-09-12.
//
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> vec (51,vector<int>(51,0)); //처음 자리
vector<vector<int>> orgin (51,vector<int>(51,0)); //미세먼지 처음 장소 마킹
vector<vector<int>> after (51,vector<int>(51,0)); // 청정기 이후 자리
int dx[] ={1,-1,0,0};
int dy[] = {0,0,-1,1};

int ax[] = {0,-1,0,1};  //윗 청정기 방햑벡터
int ay[] = {1,0,-1,0};
int bx[] = {0,1,0,-1};  //아랫 청정기 방향벡터
int by[] = {1,0,-1,0};
int R,C,T,answer;
vector<pair<int,int>> upper;
vector<pair<int,int>> lower;


void BFS(int x,int y){  //미세먼지 BFS
    after[x][y] +=vec[x][y];
    vector<pair<int,int>> temp;
    for(int i=0;i<4;i++){
            int qx = x + dx[i];
            int qy = y + dy[i];
            if(qx < 1 || qx > R || qy <1 || qy > C || vec[qx][qy] == -1 ) continue;
            temp.push_back(make_pair(qx,qy));
    }
    int div = int(vec[x][y]/5);
    for(auto elem : temp){
        after[elem.first][elem.second] += div;
        after[x][y] -= div;
    }
}
void diffusion(){   //청정기 확산 함수
    upper.clear();
    lower.clear();
    int top,bottom,x,y,cnt=0;
    for(int i=1;i<=R;i++){
        if(after[i][1] == -1){
            top = i;
            break;
        }
    }
    bottom = top+1;
    x = top;
    y = 1;
    while(true){
        int nx = x + ax[cnt];
        int ny = y + ay[cnt];
        if(nx == top && ny == 1) break;   //다시 원점으로 돌아오면 break
        if(nx < 1 || nx > R || ny <1 || ny > C){ //나간다면
            cnt++;
            nx = x + ax[cnt];
            ny = y + ay[cnt];
        }
        if(nx == top && ny == 1) break;   //다시 원점으로 돌아오면 break
        x= nx;
        y= ny;
        upper.push_back(make_pair(nx,ny));
    }
    x = bottom;
    y = 1;
    cnt =0;
    while(true){
        int nx = x + bx[cnt];
        int ny = y + by[cnt];
        if(nx == bottom && ny == 1) break;   //다시 원점으로 돌아오면 break
        if(nx < 1 || nx > R || ny <1 || ny > C){ //나간다면
            cnt++;
            nx = x + bx[cnt];
            ny = y + by[cnt];
        }
        if(nx == bottom && ny == 1) break;   //다시 원점으로 돌아오면 break
        x= nx;
        y= ny;
        lower.push_back(make_pair(nx,ny));
    }
    // 윗 부분 하나씩 이동
    for(int i = upper.size()-1;i>0;i--){
        after[upper[i].first][upper[i].second] = after[upper[i-1].first][upper[i-1].second];
    }
    after[upper[0].first][upper[0].second] = 0; //맨 처음 자리 0으로
    //아랫 부분 하나씩 이동
    for(int i = lower.size()-1;i>0;i--){
        after[lower[i].first][lower[i].second] = after[lower[i-1].first][lower[i-1].second];
    }
    after[lower[0].first][lower[0].second] = 0; //맨 처음 자리 0으로



}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;
    for(int i=1;i<=R;i++){  //입력
        for(int j=1;j<=C;j++){
            cin >> vec[i][j];
        }
    }

    for(int k = 0; k< T;k++) {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if(vec[i][j]){
                    orgin[i][j]=1; //확산될 좌표 체크
                }
            }
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if(orgin[i][j]){
                    BFS(i,j);   //확산 진행
                }
            }
        }
        diffusion();    //벡터 이동 진행
        copy(after.begin(),after.end(),vec.begin()); //끝난 작업을 원본 배열에 COPY
        for (int i = 1; i <= R; i++) {  //원복 작업
            for (int j = 1; j <= C; j++) {
                orgin[i][j]=0;
                after[i][j]=0;
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if(vec[i][j]>0) {   //값이 있을 경우
                answer += vec[i][j];    //정답 연산
            }
        }
    }

    cout << answer <<'\n';

    return 0;
}