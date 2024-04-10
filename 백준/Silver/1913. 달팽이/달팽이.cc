//
// Created by newbi on 2024-04-10.
//
#include <iostream>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,fn;
const int dx[] = {-1,0,1,0};    //상, 우, 하, 좌
const int dy[] = {0,1,0,-1};
pair<int,int> ans;
int arr[1004][1004];


void print(){
    For(i,0,N){
        For(j,0,N){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
}

void makeSnail(){
    int sX = N / 2;
    int sY = N / 2;
    int cnt =1;
    int dir = 0;
    int width = 1;

    arr[sX][sY] = cnt;
    if(fn == 1){
        ans.first = sX +1;
        ans.second = sY +1;
    }
    while(cnt < N * N){
        For(i,0,width) {
            cnt++;  //회수 증가하고
            //cout << cnt << endl;
            int qx = sX + dx[dir];
            int qy = sY + dy[dir];
            if(cnt > N*N){
                break;
            }
            arr[qx][qy] = cnt;
            if(cnt == fn){
                ans.first = qx +1;
                ans.second = qy + 1;
            }
            sX = qx;
            sY = qy;
        }
        dir= (dir+1) % 4;   //방향 증가
        if(dir % 2 == 0){   //짝수라면
            width++;    //폭 증가
        }
    }



}


int main(){
    fastIO();
    cin >> N >> fn;
    makeSnail();
    print();
    cout << ans.first <<" "<<ans.second << endl;
    return 0;
}