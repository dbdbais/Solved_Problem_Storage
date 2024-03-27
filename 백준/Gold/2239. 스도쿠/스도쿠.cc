//
// Created by newbi on 2024-03-27.
//
#include <iostream>
#include <vector>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
bool found;

int arr[10][10];
vector<pair<int,int>> zeros;
bool check(int x,int y,int val){
    For(i,0,9){
        if(arr[i][y] == val) return false;
        if(arr[x][i] == val) return false;
    }
    int ltx = x / 3;
    int lty = y / 3;
    ltx *= 3;
    lty *= 3;
    for (int i = ltx; i < ltx + 3; i++) {
        for (int j = lty; j < lty + 3; j++) {
            if (arr[i][j] == val) return false;
        }
    }

    return true;
}

void print(){
    For(i,0,9){
        For(j,0,9){
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void DFS(int idx){

    if(idx == zeros.size()){
        found = true;
        print();
        return;
    }

    auto cur = zeros[idx];
    int x = cur.first;
    int y = cur.second;

    for(int i=1;i<=9;i++){
        if(check(x,y,i)){
            arr[x][y] = i;
            DFS(idx+1);
            if(found) return;
        }
        arr[x][y] =0;   //원복
    }


}

void input(){
    string s;
    For(i,0,9){
        cin >> s;
        For(j,0,9){
            arr[i][j] = s[j]-'0'; //정수 대입
            if(arr[i][j] == 0) zeros.push_back({i,j});  //0인 지점 전부 집어넣는다.
        }
    }
}


int main(){
    fastIO();
    input();

    DFS(0);

    return 0;
}