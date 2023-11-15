//
// Created by newbi on 2023-11-14.
//
#include <iostream>
using namespace std;
int n,ans;
char arr[104][104];

int dx[]= {0,0,-1,1};
int dy[]= {-1,1,0,0};

bool out(int x,int y){
    return (x <0 || x >=100 || y <0 || y >= 100);
}

bool isPal(string s){   //펠린드롬 인지?
    int sz = s.size();
    for(int i=0;i< sz/2;i++){
        if(s[i] != s[sz-1-i]) return false;
    }
    return true;
}

void input(){
    string s;
    for(int i=0;i<100;i++){
        cin >> s;
        for(int j=0;j<100;j++){
            arr[i][j] = s[j];
        }

    }
}

void DFS(int x,int y,int dir,string st){
    st += arr[x][y];

    if(isPal(st)){
        ans = max(ans,(int)st.size());
    }

    int qx = x + dx[dir];
    int qy = y + dy[dir];

    if(out(qx,qy)) return;  //나갔다면 리턴

    DFS(qx,qy,dir,st);  //다음 좌표로 이동
}

void solve(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int a=0;a<4;a++){
                DFS(i,j,a,"");
            }
        }
    }

}
void reset(){
    ans =0;
}

int main(){

    for(int i=1;i<=10;i++){
        cin >> n;
        input();
        solve();
        cout <<"#"<<i<<" "<<ans <<'\n';
        reset();
    }

    return 0;
}