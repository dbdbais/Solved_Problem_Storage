//
// Created by newbi on 2024-04-03.
//
#include <iostream>
#include <queue>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int cmd[1000001];
deque<int> ans;
int main(){
    fastIO();
    cin >> N;
    For(i,0,N){
        cin >> cmd[i];
    }
    int card =1;
    for(int i=N-1;i>=0;i--){
        if(cmd[i] == 1){    //뒤에서 뺸다.
            ans.push_front(card);
        }
        else if(cmd[i] == 2){
                int tmp = ans.front();
                ans.pop_front();
                ans.push_front(card);
                ans.push_front(tmp);
        }
        else{
            ans.push_back(card);
        }
        card++;
    }
    while(ans.size()){
        cout << ans.front() <<" ";
        ans.pop_front();
    }
    cout <<endl;



    return 0;
}