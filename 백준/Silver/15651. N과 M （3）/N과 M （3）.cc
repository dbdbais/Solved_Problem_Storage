//
// Created by newbi on 2024-03-24.
//
#include<iostream>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,M;
int input[7];
void permutation(int cnt){
    if(cnt == M){
        For(i,0,M){
            cout << input[i] <<" ";
        }
        cout <<endl;
        return;
    }
    For(i,1,N+1){
        input[cnt] = i;
        permutation(cnt+1);
    }

}

int main(){
    fastIO();

    cin >> N >> M;

    permutation(0);

    return 0;
}