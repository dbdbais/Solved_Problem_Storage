//
// Created by newbi on 2023-10-13.
//
#include <iostream>
#include <vector>

using namespace std;
int N,K,ans = 1e8;
bool selected[22];
vector<vector<int>> vec (24,vector<int>(24,0));

void combi(int idx,vector<int> v){  //조합
    if(v.size() == K){  //nCk
        vector<int> start;
        vector<int> link;

        for(int i=0;i<N;i++){
            if(selected[i]){    //선택된 K개 스타트
                start.push_back(i);
            }
            else{       //선택되지 않는 n-k개는 링크
                link.push_back(i);
            }
        }
        int asum =0;
        int bsum =0;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){       //모든 경우의 수 조합해 누적합 구한다.
                asum += vec[start[i]][start[j]];
                bsum += vec[link[i]][link[j]];
            }
        }
        ans = min(ans,abs(asum-bsum));  //결과 값 업데이트

        return;
    }
    for(int i=idx+1;i<N;i++){
        v.push_back(i);
        selected[i] = true;

        combi(i,v);

        v.pop_back();
        selected[i] = false;
    }
    return;
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    fastIO();

    cin >> N;
    K = N/2;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> vec[i][j];
        }
    }
    vector<int>v;
    combi(-1,v);    //  nCk개의 조합 생성

    cout << ans <<'\n';

    return 0;
}
