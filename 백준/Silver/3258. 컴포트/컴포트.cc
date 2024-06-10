//
// Created by newbi on 2024-06-10.
//
#include <iostream>
#include <cstring>
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

using namespace std;
int N,Z,M;
bool fool[1002];
bool visited[1002];

int solve(){
    int K;
    bool found = false;
    For(i,1,Z){
        K = i;
        //뛰어넘을 개수
        //cout << "K : "<< K << endl;
        memset(visited,false,sizeof(visited));
        int _start = 1;
        visited[_start] = true;
        while(true){
            _start += K;
            if(_start > N){
                _start %= N;
            }
            //cout << _start << endl;
            if(_start == Z){
                found = true;
                break;
            }
            if(fool[_start] || visited[_start]) break;
            //장애물이거나 이미 방문한 곳이라면 break
            visited[_start] = true;
        }
        if(found) break;
    }
    return K;

}

int main(){
    fastIO();
    cin >> N >> Z >> M;
    int tmp;
    For(i,0,M){
        cin >> tmp;
        fool[tmp] = true;
    }
    cout << solve() << endl;

    return 0;
}