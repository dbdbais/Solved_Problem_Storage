//
// Created by newbi on 2023-10-30.
//
#include <iostream>
#include <cstring>
using namespace std;
int T,change,ans;
string st;
bool visited[999999][10];   // 현재 문자열, 몇번 째 SWAP인지
void reset(){
    change = 0;
    st = "";
    ans = 0;
    memset(visited,0,sizeof(visited));
}

void swap(char &x,char &y){
    int tmp = x;
    x = y;
    y = tmp;
}


void solve(int n){  //백트래킹을 통해 모든 케이스 중 가장 큰 값 출력
    int curNum = stoi(st);
    if(n == change){
        ans = max(curNum,ans);
        return;
    }
    for(int i=0;i<st.size();i++){
        for(int j=i+1;j<st.size();j++){
                swap(st[i], st[j]);
                int nextNum = stoi(st);
                if(!visited[nextNum][n]) {  //방문 하지 않은 곳 이라면
                    solve(n + 1);   //DFS
                    visited[nextNum][n] = true; //중요! 리턴 후 방문 처리 (State Pruning)
                }
                swap(st[i], st[j]);
        }
    }
    return;
}


int main(){

    cin >> T;

    for(int i=1;i<=T;i++){
        cin >> st >> change;
        solve(0);

        cout <<"#"<<i<<" "<<ans<<'\n';
        reset();
    }

    return 0;
}