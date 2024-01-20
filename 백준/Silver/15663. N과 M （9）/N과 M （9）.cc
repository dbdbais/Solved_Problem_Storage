//
// Created by newbi on 2024-01-20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> st;
int N,M;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    int tmp;

    fastIO();
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> tmp;
        st.push_back(tmp);
    }
    sort(st.begin(),st.end());  //정렬

    do{
        for(int i=0;i<M;i++){
            cout <<st[i] <<" ";
        }
        cout <<'\n';
        reverse(st.begin()+M,st.end());
    }while(next_permutation(st.begin(),st.end()));  //nPm

    return 0;
}