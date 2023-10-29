//
// Created by newbi on 2023-09-22.
//
#include <iostream>
#include <vector>
using namespace std;
int N, K, ans;
vector<int> dp(100004,0);
/*
vector<pair<int,int>> item(100001,{0,0});

void DFS(int idx, int val,int weight){
    cout <<"idx: "<<idx <<" val: "<< val <<" weight: "<< weight <<endl;
    if(idx == N) return;
    if(weight+item[idx].first <= K){    //K보다 무게가 작다면
        weight += item[idx].first;
        val += item[idx].second;
        ans = max(ans,val);
        DFS(idx+1,val,weight);
        weight -= item[idx].first;
        val -= item[idx].second;
    }
    DFS(idx+1,val,weight);
    return;
}
    백트래킹 실패*/
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    int weight,value;

    for(int i=0;i<N;i++){
        cin >> weight >> value;
        for(int j = K;j>= weight;j--){  //유한한(한정된) 물건을 냅색에 집어 넣으므로 우측에서 돈다
            dp[j] = max(dp[j],dp[j-weight]+value);  //메모제이션
            /*
            for(int a = 0; a<= K;a++){
                cout << dp[a]<<" ";
            }
            cout<<endl;
             DEBUG CODE */
        }
    }
    /*for(int i=0;i<N;i++){
        cin >> weight >> value;
        item[i] = make_pair(weight,value);
    }
    DFS(0,0,0);
    cout << ans <<'\n';     백트래킹 코드*/

    cout << dp[K] << '\n';
    return 0;
}