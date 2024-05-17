//
// Created by newbi on 2024-05-17.
//
#include <iostream>
#include <algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<=b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

struct point{
    int r;
    int c;
    int s;
};

int N,M,K,R,C,S,ans = 1e9;
int arr[51][51];
int cpy[51][51];
int ipt[6];
bool visited[6];
vector<point> v;

void print(){
    For(i,1,N){
        For(j,1,M){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
    cout <<endl;
}

void update(){
    int res = 1e9;
    For(i,1,N){
        int sm = 0;
        For(j,1,M){
            sm += arr[i][j];
        }
        res = min(res,sm);
    }
    if(ans > res){
        ans = res;
    }
}


void rot(int x,int y,int ex,int ey){
    int k = min(abs(ex-x)+1,abs(ey-y)+1)/2;
    For(i,0,k-1){
        int cx = x + i;
        int cy = y + i;
        int qx = ex - i;
        int qy = ey - i;
        int vertical = qy-cy;
        int horizontal = qx-cx;
        //cout <<  "x: "<< x  <<  "y: "<< y <<  "ex: "<< ex <<  "ey: "<< ey <<  "horizontal: "<< horizontal <<  "vertical: "<< vertical << endl;
        int first = arr[cx][cy];  //임시저장

        For(j,1,vertical){
            cx += 1;
            arr[cx-1][cy] = arr[cx][cy];
        }

        For(j,1,horizontal){
            cy += 1;
            arr[cx][cy-1] = arr[cx][cy];
        }

        For(j,1,vertical){
            cx -= 1;
            arr[cx+1][cy] = arr[cx][cy];
        }

        For(j,1,horizontal){
            cy -= 1;
            arr[cx][cy+1] = arr[cx][cy];
        }

        arr[cx][cy+1] = first;
        //print();
    }

}

void permutaion(int idx){
    if(idx == K){
        //원복
        copy(&cpy[0][0],&cpy[0][0]+51*51,&arr[0][0]);

        For(i,0,K-1){
            int r = v[ipt[i]].r;
            int c = v[ipt[i]].c;
            int s = v[ipt[i]].s;
            rot(r-s,c-s,r+s,c+s);
        }
        //print();
        update();
        return;
    }
    For(i,0,K-1){
        if(visited[i]) continue;
        visited[i] = true;
        ipt[idx] = i;
        permutaion(idx+1);
        visited[i] = false;
    }
}

int main(){
    fastIO();
    cin >> N >> M >> K;
    For(i,1,N){
        For(j,1,M){
            cin >> arr[i][j];
        }
    }
    For(i,1,K){
        cin >> R >> C >> S;
        v.push_back({R,C,S});
    }
    copy(&arr[0][0],&arr[0][0]+51*51,&cpy[0][0]);
    permutaion(0);

    cout << ans << endl;
    return 0;
}