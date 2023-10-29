//
// Created by newbi on 2023-10-13.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int N,K,cnt=1;
vector<bool> rUpper(104,false);

vector<int> upper(104,0);
vector<int> lower(104,0);

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void move(){    //컨베이어 벨트 이동
    int goDown = upper[N-1];
    int goUp = lower[N-1];

    for(int i=N-1;i>0;i--){
        upper[i] = upper[i-1];
        lower[i] = lower[i-1];
        rUpper[i] = rUpper[i-1];
    }
    rUpper[0] = false;

    if(rUpper[N-1] == true) rUpper[N-1] =false;     //로봇 내린다.

    upper[0] = goUp;
    lower[0] = goDown;


}
void print(){
    cout << "upper: ";
    for(int i=0;i<N;i++){
        cout << upper[i] <<" ";
    }
    cout<< endl;
    cout << "lower: ";
    for(int i=N-1;i>=0;i--){
        cout << lower[i]<<" ";
    }
    cout <<endl;
    cout << "robot: ";
    for(int i=0;i<N;i++){
        if(rUpper[i]) cout << "R" <<" ";
        else cout <<"X" << " ";
    }
    cout<< endl;

}
void robotMove(){
    stack<int> stk;
    for(int i=0;i<N;i++){
        if(rUpper[i] == true) stk.push(i);
    }
    while(!stk.empty()){
        int rbt = stk.top(); stk.pop();

        if(rbt+1 == N-1 && upper[rbt+1] >= 1) {   //로봇이 내리는 위치 전일 때
            rUpper[rbt] =false;
            upper[rbt+1] -= 1;
        }
        else if(rUpper[rbt+1] == false && upper[rbt+1] >= 1){   // 로봇 이동
            rUpper[rbt] = false;
            rUpper[rbt+1] = true;
            upper[rbt+1] -= 1;
        }
    }

}

int find_error(){
    int errCnt = 0;
    for(int i=0;i<N;i++){
        if(upper[i] == 0) errCnt++;
        if(lower[i] == 0) errCnt++;
    }
    return errCnt;
}

int main(){

    fastIO();
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> upper[i];
    }
    for(int i=0;i<N;i++){
        cin >> lower[i];
    }

    while(true){

        move();

        robotMove();

        if(rUpper[0] == false && upper[0] >= 1) {   //로봇을 올린다.
            rUpper[0] = true;
            upper[0] -= 1;
        }
        //print();
        if(find_error() >= K) break;    //내구도가 0인 칸이 k개 이상이면 종료
        cnt++;

    }
    cout << cnt <<'\n';
    return 0;
}