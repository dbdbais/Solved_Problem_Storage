//
// Created by newbi on 2024-04-22.
//
#include <iostream>
#include <queue>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

struct log{
    pair<int,int> cxy;
    pair<int,int> lxy;
    pair<int,int> rxy;

    int pos = -1;
    log(){}

    log(pair<int,int> cxy,pair<int,int> lxy,pair<int,int> rxy): cxy(cxy),lxy(lxy),rxy(rxy){

    }
    void setC(int x,int y){
        cxy.first = x;
        cxy.second = y;
    }
    void setL(int x,int y){
        lxy.first = x;
        lxy.second = y;
    }
    void setR(int x,int y){
        rxy.first = x;
        rxy.second = y;
    }

    void setPos(){
        //  수평일 경우
        if(cxy.first == lxy.first && cxy.first == rxy.first){
            pos = 0;
        }
        else{   //수직일 경우
            pos =1;
        }
    }

    void turn(){
        if(pos == 0){   //수평
            pos = 1;    //수직
            lxy.first =cxy.first-1;
            lxy.second = cxy.second;
            rxy.first =cxy.first+1;
            rxy.second = cxy.second;
        }
        else{
            pos = 0;    //수평
            lxy.first =cxy.first;
            lxy.second = cxy.second-1;
            rxy.first =cxy.first;
            rxy.second = cxy.second+1;
        }
    }

    void printInfo(){
        cout << pos << endl;
        cout << lxy.first <<", "<< lxy.second << endl;
        cout << cxy.first <<", "<< cxy.second << endl;
        cout << rxy.first <<", "<< rxy.second << endl;
    }
};
const int INF = 1e9;
const int dx[] = {0,0,-1,1,1,1,-1,-1};
const int dy[] = {-1,1,0,0,1,-1,1,-1};
const int rx[] = {0,0,-1,1};
const int ry[] = {-1,1,0,0};
int N;
char arr[52][52];
int visited[52][52][2];

log sl,el;
bool out(int x,int y){
    return x < 0 || y < 0 || x >= N || y >=N;
}

void input(){
    string s;
    int scnt =0;
    int ecnt=0;
    For(i,0,N){
        cin >> s;
        For(j,0,N){
            arr[i][j] = s[j];
            if(arr[i][j] == 'B'){
                if(scnt == 0){
                    sl.setL(i,j);
                }
                else if(scnt == 1){
                    sl.setC(i,j);
                }
                else{
                    sl.setR(i,j);
                }
                scnt++;
            }
            else if(arr[i][j] =='E'){
                if(ecnt == 0){
                    el.setL(i,j);
                }
                else if(ecnt == 1){
                    el.setC(i,j);
                }
                else{
                    el.setR(i,j);
                }
                ecnt++;
            }
        }
    }
}

bool treeAround(int x,int y){

    For(i,0,8){
        int qx = x + dx[i];
        int qy = y + dy[i];
        if(out(qx,qy)|| arr[qx][qy] =='1') return true;
    }
    return false;

}

bool canGo(pair<int,int>lxy,pair<int,int>cxy,pair<int,int>rxy){
    if(out(lxy.first,lxy.second)||out(cxy.first,cxy.second)||out(rxy.first,rxy.second)
    ||arr[lxy.first][lxy.second] == '1' || arr[cxy.first][cxy.second] == '1' || arr[rxy.first][rxy.second] == '1'){
        return false;
    }
    else{
        return true;
    }

}

void output(int pos){
    cout<<"P : " << pos << endl;
    For(i,0,N){
        For(j,0,N){
            if(visited[i][j][pos] == INF){
                cout << "I ";
            }
            else{
                cout << visited[i][j][pos] <<" ";
            }

        }
        cout << endl;
    }
    cout << endl;
}

void solve(){
    fill(&visited[0][0][0],&visited[0][0][0] + 52 * 52 * 2,INF);
    queue<pair<int,log>> q; //현재 위치값, 통나무 값
    visited[sl.cxy.first][sl.cxy.second][sl.pos] = 0;

    q.push({0,sl});

    while(q.size()){
        auto cur = q.front(); q.pop();
        int val = cur.first;
        log curL = cur.second;
        auto cxy = curL.cxy;
        auto lxy = curL.lxy;
        auto rxy = curL.rxy;
        int curPos = curL.pos;
        //curL.printInfo();
        //output(curPos);

        For(i,0,4){
            pair<int,int> ltxy;
            pair<int,int> ctxy;
            pair<int,int> rtxy;
            ltxy.first = lxy.first + rx[i];
            ctxy.first = cxy.first + rx[i];
            rtxy.first = rxy.first + rx[i];

            ltxy.second = lxy.second + ry[i];
            ctxy.second = cxy.second + ry[i];
            rtxy.second = rxy.second + ry[i];

            if(canGo(ltxy,ctxy,rtxy) && visited[ctxy.first][ctxy.second][curPos] > val + 1){

                visited[ctxy.first][ctxy.second][curPos] = val + 1;
                log nxt = log(ctxy,ltxy,rtxy);
                nxt.pos = curPos;
                q.push({val+1, nxt });

            }
        }
        if(!treeAround(cxy.first,cxy.second)){  //주위에 나무가 없다면
            curL.turn();
            if(visited[curL.cxy.first][curL.cxy.second][curL.pos] > val+1) {
                visited[curL.cxy.first][curL.cxy.second][curL.pos] = val + 1;
                q.push({val + 1, curL});
            }
        }
    }

}

int main(){
    fastIO();
    cin >> N;
    input();
    sl.setPos();
    el.setPos();
    solve();
    if(visited[el.cxy.first][el.cxy.second][el.pos] == INF){
        cout << 0 << endl;
    }
    else{
        cout << visited[el.cxy.first][el.cxy.second][el.pos] << endl;
    }

    return 0;
}