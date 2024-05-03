//
// Created by newbi on 2024-05-03.
//
#include <iostream>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int N;
int input[100004];

int solve(){
    int left = 0;
    int right = N-1;
    int dist = 2e9;
    int retVal;
    while(left<right){
        //cout << left << ", " << right << endl;
        int lVal = input[left];
        int rVal = input[right];
        int tmp = lVal + rVal;   //도중의 값
        //cout << tmp << endl;
        if(abs(tmp) < dist){ //최소 라면
            dist = abs(tmp);  //최소라면 갱신
            retVal = tmp;
            //cout<<"updated : " << retVal << endl;
        }
        //if(dist == 0) break;
        if(tmp <0){
            left++;
        }
        else{
            right--;
        }
    }
    return retVal;
}
int main(){
    fastIO();
    cin >> N;
    For(i,0,N){
        cin >> input[i];
    }
    cout << solve() << endl;
    return 0;
}