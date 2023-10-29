//
// Created by newbi on 2023-09-13.
//
#include <iostream>
#include <vector>
using namespace std;
int op[4];  //0 덧셈, 1 뺄셈 2 곱셈 3 나눗셈
vector<int> vec(12,0);
int N,mx = -1000000000,mn = 1000000000;

void DFS(int idx, int tmp){
    if(idx == N-1){ //끝 점 도달 시
        mx = max(mx,tmp);
        mn = min (mn,tmp);
        return;
    }
    for(int i=0;i<4;i++){
        if(op[i]){  //연산자가 있다면
            op[i]--;    //빼고 다음 연산 수행
            if(i==0){ //덧셈
                DFS(idx+1,tmp+vec[idx+1]);
            }
            else if(i==1){ //뻴셈
                DFS(idx+1,tmp-vec[idx+1]);
            }
            else if(i==2){  //곱셈
                DFS(idx+1,tmp*vec[idx+1]);
            }
            else if(i==3){  //나눗셈
                DFS(idx+1,int(tmp/vec[idx+1]));
            }
            op[i]++;    //원복
        }
    }
    return;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0;i<N;i++){
        cin >> vec[i];
    }
    for(int i=0;i<4;i++){
        cin >> op[i];
    }
    DFS(0,vec[0]);

    cout << mx <<'\n';
    cout << mn <<'\n';
    return 0;
}