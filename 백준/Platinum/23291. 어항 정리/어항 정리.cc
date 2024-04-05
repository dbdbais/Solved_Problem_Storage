//
// Created by newbi on 2024-04-05.
//
#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int N,K;
deque<int> dq[102];


void print(){
    for(int i=5;i>=0;i--){
        for(auto elem : dq[i] ){
            cout << elem <<" ";
        }
        cout << endl;
    }
    cout <<endl;
}

void pushFish(){
    int mn = *min_element(dq[0].begin(), dq[0].end());
    //최소값 찾아서
   for(int i=0;i<dq[0].size();i++){
       if(dq[0][i] == mn){
           dq[0][i]++; //하나 증가한다.
       }
   }
}
int height;
void stackFish(){
    dq[1].push_front(dq[0].front());
    dq[0].pop_front();
    height = 1;
    //초기 설정
    queue<int> q[101];
   // print();

    while(height+1 <= (int)dq[0].size() - (int)dq[1].size()){    //맨 밑이 클 때 까지

        int tSize = dq[1].size();   //첫번째 행의 길이 가져온다.

        int floor =0;
        for(int j=tSize-1;j>=0;j--){   //j층 만큼 옮긴다.
            floor++;
            for(int k = height;k>=0;k--){   //큐에 집어 넣는다.
                q[floor].push(dq[k][j]);
            }
        }

        //큐에 들어있는 만큼 제거한다.
        for(int k = height;k>=0;k--){
            for(int a =0;a<tSize;a++){
                dq[k].pop_front();
            }
        }

        //층마다 큐에 있는 걸 넣는다.
        for(int j=1;j<=tSize;j++){
            while(q[j].size()){
                dq[j].push_front(q[j].front());
                q[j].pop();
            }
        }
        height = tSize;
        //print();
    }
}
void moveFish(){
    deque<int> tmp[102];
    for(int i=0;i<100;i++){
        for(auto elem : dq[i]){
            tmp[i].push_back(elem);
        }
    }   //tmp에 복사

    for(int i = height;i>=0;i--){   //행
        for(int j=0;j<tmp[i].size();j++){   //열
            if(i != 0){
                //밑에 검사
                int d = abs(tmp[i][j] - tmp[i-1][j]) / 5;
                if(d >0){
                    if(tmp[i][j] > tmp[i-1][j]){
                        dq[i][j] -= d;
                        dq[i-1][j] += d;
                    }
                    else{
                        dq[i][j] += d;
                        dq[i-1][j] -= d;
                    }
                }
            }
            if(j!= tmp[i].size()-1){    //오른쪽 검사
                int d = abs(tmp[i][j] - tmp[i][j+1]) / 5;
                if(d >0){
                    if(tmp[i][j] > tmp[i][j+1]){
                        dq[i][j] -= d;
                        dq[i][j+1] += d;
                    }
                    else{
                        dq[i][j] += d;
                        dq[i][j+1] -= d;
                    }
                }
            }
        }

    }
}

void makeRow(){
    int tSize = dq[1].size();
    queue<int> q;

    for(int i=0;i<tSize;i++){
        for(int j=0;j<=height;j++){
            q.push(dq[j][i]);
        }
    }
    for(int i= tSize;i<dq[0].size();i++){
        q.push(dq[0][i]);
    }
    for(int i = height;i>=0;i--){
        dq[i].clear();
    }
    while(q.size()){
        dq[0].push_back(q.front());
        q.pop();
    }

    height = 0; //높이 초기화
}

void stackFish2(){
    int n = dq[0].size() / 2;
    queue<int> q[2];

    for(int i=0;i<n;i++){
        q[0].push(dq[0][i]);
    }
    for(int i=0;i<n;i++){
        dq[1].push_front(q[0].front());
        q[0].pop();
        dq[0].pop_front();
    }

    n /=2;
    for(int i=0;i<=1;i++){
        for(int j=0;j<n;j++){
            q[i].push(dq[i].front());
            dq[i].pop_front();
        }
    }

    for(int i=0;i<n;i++){
        dq[2].push_front(q[1].front());
        q[1].pop();
        dq[3].push_front(q[0].front());
        q[0].pop();
    }
    height = 3;
}

bool check(){
    int mn = *min_element(dq[0].begin(), dq[0].end());
    int mx = *max_element(dq[0].begin(), dq[0].end());
    return (mx -mn) <= K;
}

void solve(){
    int ans = 0;
    while(!check()){
        pushFish();
        stackFish();
        moveFish();
        makeRow();
        stackFish2();
        moveFish();
        makeRow();
        //print();
        ans++;
    }
    cout << ans << endl;

}

int main(){
    fastIO();
    cin >> N >> K;
    int tmp;
    For(i,0,N){
        cin >> tmp;
        dq[0].push_back(tmp);  //0번째 어항에 다 집어넣는다.
    }

   solve();
    return 0;
}