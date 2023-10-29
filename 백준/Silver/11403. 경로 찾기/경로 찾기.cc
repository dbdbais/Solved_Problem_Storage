//
// Created by newbi on 2023-08-12.
//
#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >>n;
    vector<vector<int>> vec (n,vector<int>(n));
    vector<vector<int>> ans (n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cin>> vec[i][j];
    }

//플로이드 워셜 알고리즘 사용

    for(int k=0;k<n;k++){ //경유할 노드 k
        for(int i=0;i<n;i++){ //시작 노드 i
            for(int j=0;j<n;j++){ //최종 노드 j
                if(vec[i][k] && vec[k][j])  //i -> k -> j가 존재한다면
                    vec[i][j] = 1; //경로가 존재
            }
        }
    }

    for(auto row : vec){
        for(auto elem: row)
            cout<< elem << " ";
        cout<<'\n';
    }

    return 0;
}