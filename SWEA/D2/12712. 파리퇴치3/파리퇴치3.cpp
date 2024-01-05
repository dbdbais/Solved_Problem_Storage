//
// Created by newbi on 2024-01-05.
//
#include<iostream>

using namespace std;

int T,N,M,ans;
int arr[17][17];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int bx[] = {1,1,-1,-1};
int by[] = {1,-1,1,-1};

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool out(int x,int y){
    return (x < 0 || x > N || y <0 || y > N );
}
void solve(int x,int y){
    int dsum =arr[x][y];

    for(int i=0;i<4;i++){
        for(int j=1;j<M;j++){
            if(out(x+dx[i]*j,y+dy[i]*j)) continue;
            dsum += arr[x+dx[i]*j][y+dy[i]*j];
        }
    }
    int bsum =arr[x][y];
    for(int i=0;i<4;i++){
        for(int j=1;j<M;j++){
            if(out(x+bx[i]*j,y+by[i]*j)) continue;
            bsum += arr[x+bx[i]*j][y+by[i]*j];
        }
    }
    int sm = max(dsum,bsum);
    ans = max(sm,ans);

}

void reset(){
    ans = 0;
}

int main(){

    fastIO();

    cin >> T;
    for(int idx = 1;idx <= T;idx++){
        cin >> N >> M;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> arr[i][j];
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                solve(i,j);
            }
        }
        cout <<"#"<<idx <<" "<<ans<<'\n';
        reset();
    }

    return 0;
}