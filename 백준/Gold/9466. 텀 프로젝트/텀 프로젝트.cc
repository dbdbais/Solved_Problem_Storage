//
// Created by newbi on 2024-04-26.
//
#include <iostream>
#include <cstring>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T,N;

int student[100002];
bool visited[100002];
bool tVisited[100002];
bool isGroup[100002];


void print(){
    For(i,1,N+1){
        cout <<i<<" ";
    }
    cout << endl;
    For(i,1,N+1){
        cout << student[i]<<" ";
    }
    cout << endl;

    For(i,1,N+1){
        cout << isGroup[i]<<" ";
    }
    cout << endl;
    For(i,1,N+1){
        cout << tVisited[i]<<" ";
    }
    cout << endl << endl;
}

void DFS(int cur){
    if(isGroup[cur]) return;

    isGroup[cur] = true;
    DFS(student[cur]);

}

void findGroup(int cur){

    if(isGroup[cur]||tVisited[cur]) return; //이미 그룹인 곳이면 제낌

    if(visited[cur]){   //방문한 곳 만났다면
        DFS(cur);
        return;
    }

    visited[cur] = true;
    findGroup(student[cur]);    //다음으로 이동
    visited[cur] = false;
    tVisited[cur] = true;

}

int solve(){
    For(i,1,N+1){
        if(isGroup[i] || visited[i]) continue;
        findGroup(i);
        //cout << i <<" turn"<<endl;
        //print();

    }
    int cnt =0;
    For(i,1,N+1){
        if(!isGroup[i]) {
            cnt++;
        }
        else{
            isGroup[i] = false;
        }
    }
    memset(tVisited,false,sizeof(visited));
    return cnt;
}

int main(){
    fastIO();
    cin >> T;
    For(t,0,T){
        cin >> N;
        For(i,1,N+1){
            cin >> student[i];
        }
        cout <<solve() << endl;
    }

    return 0;
}