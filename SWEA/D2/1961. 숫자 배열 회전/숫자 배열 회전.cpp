//
// Created by newbi on 2024-01-06.
//
#include <iostream>
#include <vector>

using namespace std;
int T, N;
vector<vector<int>> vec;
vector<vector<int>> ans[7];

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void print(){
    for(int i =0;i<N;i++){
        for(auto row :ans[i]){
            for(auto elem: row){
                cout <<elem;
            }
            cout <<" ";
        }
        cout<<'\n';
    }
}
void input(int n){
    int ipt;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            cin >> ipt;
            tmp.push_back(ipt);
        }
        vec.push_back(tmp);
    }
}

void reset(){
    for(auto row : vec){
        row.clear();
    }
    for(int i=0;i<7;i++){
        for(auto row:ans[i]){
            row.clear();
        }
        ans[i].clear();
    }
    vec.clear();
}

void rotate_left(){
    int n = vec.size(); //행
    int m = vec[0].size(); //열

    vector<vector<int>> temp (m,vector<int>(n,0));  //새로운 vector

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            temp[i][j] = vec[n-j-1][i];
        }
    }
    vec.resize(m);  //새로운 배열의 행으로 resize
    vec[0].resize(n);

    vec = temp;

}
void insert(){
    for(int i=0;i<vec.size();i++){
        ans[i].push_back(vec[i]);   //행별로 삽입한다.
    }
}

int main(){

    fastIO();

    cin >>T;
    for(int idx = 1;idx <=T;idx++){
        cin >> N;
        input(N);
        rotate_left();
        insert();
        rotate_left();
        insert();
        rotate_left();
        insert();
        cout << "#"<<idx<<'\n';
        print();
        reset();
    }
    return 0;
}