//
// Created by newbi on 2023-09-21.
//
#include<iostream>
#include<vector>
using namespace std;
int N,K;
const int INF =9999999;     //초기 값
vector<int> vec(10004,INF);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    vec[0] = 0; //0을 만드는 동전의 개수는 0 , 초기 설정
    int temp;
    for(int i=1;i<=N;i++){
        cin >> temp;
        for(int j=temp;j<=K;j++){   //K까지 동전으로 연산을 수행 (동전이 무한대로 사용가능하므로 좌측에서 시작)
            vec[j] = min(vec[j],vec[j-temp]+1);     //입력되는 동전으로 더 간단한 연산이 이뤄지면 변경
        }
        /*
        for(int a=0;a<=K;a++)
            cout << vec[a]<<" ";
        cout<<endl;
         DEBUG  */
    }
    if(vec[K] == INF){
        cout << -1 <<'\n';
    }
    else{
        cout << vec[K]<<'\n';
    }

    return 0;
}