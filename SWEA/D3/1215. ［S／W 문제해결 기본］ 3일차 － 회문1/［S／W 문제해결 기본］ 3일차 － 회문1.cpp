//
// Created by newbi on 2023-11-13.
//
#include <iostream>
#include <queue>
using namespace std;
int N,cnt;
char arr[10][10];
int dx[]= {0,0,-1,1};
int dy[]= {-1,1,0,0};

bool out(int x,int y){
    return (x <0 || x >=8 || y <0 || y >= 8);
}
bool isPal(string s){   //펠린드롬 인지?
   int sz = s.size();
   for(int i=0;i< sz/2;i++){
       if(s[i] != s[sz-1-i]) return false;
   }
    return true;
}

void DFS(int x,int y,int dir,string st){
    st += arr[x][y];

    if(st.size() == N){ //길이가 N이면
        //cout << st <<endl;
        if(isPal(st)) cnt++;    //펠린드롬인지 확인 후 카운트 증가
        return;
    }
    int qx = x + dx[dir];
    int qy = y + dy[dir];

    if(out(qx,qy)) return;  //나갔다면 리턴

    DFS(qx,qy,dir,st);  //다음 좌표로 이동
}

void solve(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(int a=0;a<4;a++){
                DFS(i,j,a,"");
            }
        }
    }


}
void reset(){
    cnt =0;
}
void input(){
    string s;
    for(int i=0;i<8;i++){
        cin >> s;
        for(int j=0;j<8;j++){
            arr[i][j] = s[j];
        }
    }
}
int main(){
    for(int i=1;i<=10;i++){
        cin >> N;
        input();
        solve();
        cout <<"#"<<i<<" "<<cnt/2 <<'\n';
        reset();
    }

    return 0;
}