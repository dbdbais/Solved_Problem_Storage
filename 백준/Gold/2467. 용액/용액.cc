//
// Created by newbi on 2024-04-09.
//
#include <iostream>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int N;
int input[100004];
pair<int,int> ans;

void solve(){
    int left = 0;
    int right = N-1;
    int dist = 2e9;
    while(left<right){
        //cout << left << ", " << right << endl;
        int lVal = input[left];
        int rVal = input[right];
        int tmp = lVal + rVal;   //도중의 값
       // cout << tmp << endl;
        if(abs(tmp) < dist){ //최소 라면
            dist = abs(tmp);  //최소라면 갱신
            //cout<<"updated : " << dist << endl;
            ans.first = input[left];
            ans.second = input[right];
        }
        //if(dist == 0) break;
        if(tmp <0){
            left++;
        }
        else{
            right--;
        }

    }

}
int main(){
    fastIO();
    cin >> N;
    For(i,0,N){
        cin >> input[i];
    }
    solve();
    cout << ans.first << " "<<ans.second << endl;
    return 0;
}