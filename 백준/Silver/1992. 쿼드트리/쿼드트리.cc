//
// Created by newbi on 2023-10-08.
//
#include <iostream>
#include <vector>
using namespace std;
int N;

vector<vector<int>> vec(102,vector<int>(102,0));


void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool check(int x, int y, int range,int val){    //모두 1인지 0인지 체크하는 함수
    for(int i=x;i<x+range;i++){
        for(int j=y;j<y+range;j++){
            if(vec[i][j] != val){
                return false;
            }
        }
    }
    return true;
}

string DFS(int x, int y ,int n){
    if(n == 1) return to_string(vec[x][y]);
    string ans = "";
    if(check(x,y,n,vec[x][y])){
        ans += to_string(vec[x][y]);
    }
    else{
        int half = n/2;
        ans += "(";
        ans += DFS(x,y,half);   //1사분면
        ans += DFS(x,y+half,half);  //2사분면
        ans += DFS(x+half,y,half);  //3사분면
        ans += DFS(x+half,y+half,half); //4사분면
        ans += ")";

    }
    return ans;
}

int main(){

    string st;

    fastIO();

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> st;
        for(int j=0;j<N;j++){
            vec[i][j] = st[j]-'0';
        }
    }
    cout << DFS(0,0,N);



    return 0;
}