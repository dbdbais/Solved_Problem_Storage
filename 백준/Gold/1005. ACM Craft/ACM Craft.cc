//
// Created by newbi on 2024-05-01.
//
#include <iostream>
#include <cstring>
#include <vector>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int T, N, K, M, W;

int bTime [1002];
int count[1002];
bool canBuild [1002];
int dp[1002];
vector<int> adj[1002];
vector<int> radj[1002];

void print(){
    For(i,1,N+1){
        cout << dp[i]<< " ";
    }
    cout << endl;

}

void solve(){
    bool found = false;

    while(!found){
        For(i,1,N+1){
            if(count[i] == 0 && !canBuild[i]){  //차수가 0이고 빌드하지 않았다면
                int val = 0;
                for(int rad : radj[i]){   //이전 연결된 요소들 꺼내서
                    val = max(dp[rad],val);  //가장 오래 걸린 값으로 갱신
                }
                for(int ad : adj[i]){
                    count[ad]--;    //연결 끊어줌
                }

                dp[i] = val + bTime[i]; // 값 갱신
                canBuild[i] = true;
            }
        }
        //print();
        if(canBuild[W]){
            found = true;
        }
    }
    cout << dp[W] << endl;
}

void reset(){
    memset(count,0,sizeof(count));
    memset(canBuild,false,sizeof(canBuild));
    memset(dp,0,sizeof(dp));
    For(i,1,N+1){
        radj[i].clear(); //비워버림
        adj[i].clear(); //비워버림
    }
}

void input(){
    cin >> T;
    For(z,0,T){
        cin >> N >> K;
        For(i,1,N+1){
            cin >> bTime[i];
        }
        //건물 걸리는 시간
        int a,b;
        For(i,0,K){
            cin >> a >> b;
            adj[a].push_back(b); //연결된거 저장
            radj[b].push_back(a); //역으로 연결된거 저장
            count[b]++; //연결 차수 증가
        }
        cin >> W;   //건물의 번호
        solve();
        reset();
    }
}


int main(){
    fastIO();
    input();
    return 0;
}