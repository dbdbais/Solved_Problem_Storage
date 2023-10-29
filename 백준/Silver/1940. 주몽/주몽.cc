//
// Created by newbi on 2023-08-24.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> material(15001,0);
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> material[i];
    }
    int cnt =0;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(material[i]+material[j] == M){
                cnt++;
            }
        }
    }
    cout << cnt <<'\n';

    return 0;
}