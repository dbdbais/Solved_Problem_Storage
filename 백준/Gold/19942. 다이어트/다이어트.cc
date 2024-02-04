//
// Created by newbi on 2024-02-04.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

const int INF =1e9;
int N;
int minimum[4];
int table[16][5];
int ans = INF;
vector<int> combi_num;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool check(int temp[]){
    For(i,0,4){
        if(minimum[i] > temp[i]) return false;
    }
    return true;
}

void solve(){
    for(int i=0;i<(1<<N);i++){
        int tempSm[4] ={0,0,0,0};
        int priceSm =0;
        vector<int> tmVec;
        for(int j=0;j<N;j++){
            if(i & (1<<j)){ //비트마스킹 선택된 경우라면
                tmVec.push_back(j+1);
                For(k,0,4){
                    tempSm[k] += table[j][k];   //각자 영양소 더한다.
                }
                priceSm += table[j][4]; //가격 더한다.
            }
        }
        if(check(tempSm)){
            if(ans > priceSm){  //지금보다 더 최소값을 찾는다면
                ans = priceSm;  //갱신
                combi_num = tmVec;  //갱신
            }
            else if (ans == priceSm){   //동일하다면 사전 순 결정해야함
                string st1 = "";
                string st2 = "";
                for(auto elem : combi_num){
                    st1 += to_string(elem);
                }
                for(auto elem : tmVec){
                    st2 += to_string(elem);
                }
                if(st1 > st2){  //새로 들어온게 사전순으로 더 빠르다면
                    combi_num = tmVec;  //갱신
                }
            }
        }
    }
}

int main(){

    fastIO();

    cin >> N;

    For(i,0,4){
        cin >> minimum[i];
    }
    For(i,0,N){
        For(j,0,5){
         cin >> table[i][j];
        }
    }
    solve();

    if(ans != INF){
        cout << ans << endl;
        for(auto elem : combi_num){
            cout << elem <<" ";
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }



    return 0;
}