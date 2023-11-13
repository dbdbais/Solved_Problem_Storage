//
// Created by newbi on 2023-11-12.
//
#include <iostream>
#include <queue>
using namespace std;
int N;
int main(){
    deque<pair<int,int>> dq;    //풍선 안의 수, 인덱스
    int tmp;

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        dq.push_back({tmp,i+1});
    }
    while (dq.size()){
        int mov = dq.front().first;
        cout << dq.front().second <<" ";
        dq.pop_front();
        if(mov >0 ){    //양수라면
            for(int i=0;i<mov-1;i++){   //pop이 먼저 일어나기 때문에 -1
                dq.push_back(dq.front());   // 맨 뒤에 맨 앞에 내용 push
                dq.pop_front();     //맨 앞 제거
            }
        }
        else{   //음수라면
            mov = -mov;
            for(int j=0;j<mov;j++){
                dq.push_front(dq.back());   //맨 뒤의 내용을 맨 앞에 push
                dq.pop_back();  //뒤의 내용 제거
            }
        }

    }
    cout <<'\n';

    return 0;
}
