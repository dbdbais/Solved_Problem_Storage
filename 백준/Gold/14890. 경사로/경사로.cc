//
// Created by newbi on 2024-03-15.
//
#include <iostream>
#include <cstring>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,X;
int arr[101][101];
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool out(int x){
    return x < 0 || x >= N;
}
int cnt =0;

void rSearch(int idx,int row){

    bool visited[N];
    memset(visited,false,sizeof(visited));

    int prev;
    if(row == 0){
        prev = arr[idx][0];
    }
    else{
        prev = arr[0][idx];
    }

    For(i,1,N){
        int cur;
        if(row == 0){
            cur = arr[idx][i];
        }
        else{
            cur = arr[i][idx];
        }


        if(prev == cur){

        }
        else if(prev +1 == cur){    //1차이가 나며 위로 올라갔을 경우
            if(out(i-X)) return;  //장외 처리
            for(int j= i-X;j<i;j++){
                if(visited[j]) return;
                visited[j] = true;  //경사로가 있다.
            }
        }
        else if(prev - 1 == cur){    //1차이가 나며 아래로 내려 갔을 때
            if(out(i+X-1)) {
                return;
            }    //장외 처리
            for(int j=i;j<i+X;j++){
                if(visited[j]) return;
                visited[j] = true;
            }
        }
        else{   //못 만든다.
            return;
        }
//        cout << "i: "<< i<<" prev: "<<prev<<"  ,  cur: "<<cur<<endl;
//        for(int k =0;k<N;k++){
//            cout << visited[k] <<" ";
//        }
//        cout <<endl;
        prev = cur; //이전껄 현재에 넣는다.
    }
    cnt++;
}

void solve(){
    For(i,0,2){
        For(j,0,N){
            rSearch(j,i);
        }
    }
}

int main(){
    fastIO();
    cin >> N >> X;
    For(i,0,N){
        For(j,0,N){
            cin >> arr[i][j];
        }
    }
    solve();
    cout << cnt << endl;

    return 0;
}