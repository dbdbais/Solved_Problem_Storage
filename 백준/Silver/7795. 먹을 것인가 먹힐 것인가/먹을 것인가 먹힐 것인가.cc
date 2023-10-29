//
// Created by newbi on 2023-09-15.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A,B,T;
vector<int> aVec(20004,0);
vector<int> bVec(20004,0);
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i=0;i<T;i++){
        aVec.clear();   //다음 테스트케이스를 위해 벡터 클리어
        bVec.clear();
        int sm =0;
        cin >> A >> B;
        for(int j =0;j<A;j++){
            cin >> aVec[j];
        }
        for(int k =0;k<B;k++){
            cin >> bVec[k];
        }
        sort(aVec.begin(),aVec.begin()+A);  //정렬
        sort(bVec.begin(),bVec.begin()+B);  //정렬

        for(int a=0;a < A;a++){
            sm += lower_bound(bVec.begin(),bVec.begin()+B,aVec[a])- bVec.begin(); // A보다 작은 B sum에 덧셈
        }

        cout << sm <<'\n';
    }
    return 0;
}