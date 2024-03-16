//
// Created by newbi on 2024-03-16.
//
#include <iostream>
#include <vector>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long

using namespace std;

typedef vector<vector<ll>> matrix;
ll N;
const ll mod = 1000000007;

matrix origin = {{1,1},{1,0}};
matrix A= {{1,0},{0,1}};   //단위 행렬

matrix mul(matrix a, matrix b){
    matrix tmp = {{0,0},{0,0}};
    For(i,0,2){
        For(j,0,2){
            For(k,0,2){
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= mod;
        }
    }
    return tmp;
}
void print(){
    cout << "ans" <<endl;
    For(i,0,2){
        For(j,0,2){
            cout << A[i][j]<<" ";
        }
        cout << endl;
    }
    cout <<endl;
    cout << "A"<<endl;
    For(i,0,2){
        For(j,0,2){
            cout << origin[i][j]<<" ";
        }
        cout << endl;
    }
    cout <<endl;
}
int main(){
    fastIO();
    cin >> N;
    if(N != 1 && N != 0)
    {
        N--;
        while(N > 0) {
            //cout<<"N: "<< N << endl;
            //print();
            if(N % 2 == 1){ //홀 수 이면 지금까지 계산한 피보나치 값 누적한다.
            A = mul(A,origin);
            }
            origin = mul(origin,origin);    //2의 거듭제곱으로 증가해가며 계산 해야 할 피보나치 값을 log n 으로 누적
           // print();
            N /= 2;
        }
    }
    //print();
    cout << A[0][0] <<endl;
    return 0;
}