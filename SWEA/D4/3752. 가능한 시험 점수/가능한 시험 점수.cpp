//
// Created by newbi on 2023-11-02.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T,N;
int arr[100];   //들어오는 값
vector<int> ans;    //실제 숫자
bool dp[10001]; //생성되는 숫자 체크

void input(){
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
}

void solve(){

    for(auto elem : arr){   //입력된 값들
        int tSize = ans.size(); //지금 사이즈 기억
        for(int i=0;i<tSize;i++){
            if(!dp[ans[i]+elem]){   //새로운 값이면
                dp[ans[i]+elem] = true; //생성 처리
                ans.push_back(ans[i]+elem); //결과 배열에 push
            }
        }
    }

}
void reset(){
    memset(arr,0,sizeof(arr));
    memset(dp,false,sizeof(dp));
    ans.clear();
}


int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
        ans.push_back(0);
        dp[0]= true;
        cin >> N;
        input();
        solve();
        cout <<"#"<<i<<" "<<ans.size()<<'\n';
        reset();
    }
    return 0;
}