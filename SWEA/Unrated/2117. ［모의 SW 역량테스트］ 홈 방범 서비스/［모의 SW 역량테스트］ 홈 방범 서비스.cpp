//
// Created by newbi on 2024-03-01.
//
#include <iostream>
#include <algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T,N,M;
int arr[22][22];
bool visited[22][22];
int ans = 0;
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool out(int x,int y){
    return x<0 || y <0 || x >= N || y >=N;
}

void print(){
    cout <<endl;
    For(i,0,N){
        For(j,0,N){
            cout << visited[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}

void setArea(int x,int y,int k){
    int cnt = 0;
    int top = x-k+1;
    int bot = x+k;
    for(int i = top;i<bot;i++){
        if(i<=x){   //증가
            for(int j=y-(i-top);j<y;j++){
                if(out(i,j))continue;
                if(arr[i][j]) cnt++;
                visited[i][j] = true;
            }
            for(int j=y;j<=y+(i-top);j++){
                if(out(i,j))continue;
                if(arr[i][j]) cnt++;
                visited[i][j] = true;
            }
        }
        else{   //감소
            for(int j=y-(bot-i-1);j<y;j++){
                if(out(i,j))continue;
                if(arr[i][j]) cnt++;
                visited[i][j] = true;
            }
            for(int j=y;j<=y+(bot-i-1);j++){
                if(out(i,j))continue;
                if(arr[i][j]) cnt++;
                visited[i][j] = true;
            }
        }
    }

    int cost = k*k+(k-1)*(k-1);
    if(cnt * M >= cost && ans < cnt){
       ans = cnt;
   }
}

void solve(){
    For(k,1,N+2){
        For(i,0,N){
            For(j,0,N){
                setArea(i,j,k);
                //print();
                //fill(visited[0],visited[N],false);
            }
        }
    }

}

int main(){
    fastIO();

    cin >> T;
    for(int t = 1; t<=T;t++){
        cin >> N >> M;
        For(i,0,N){
            For(j,0,N){
                cin >> arr[i][j];
            }
        }

        solve();

        cout << "#"<<t<<" "<<ans << endl;
        ans =0;
    }


    return 0;
}