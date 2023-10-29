//
// Created by newbi on 2023-08-16.
//
#include <iostream>
using namespace std;

int gcd(int a, int b){  //Greatest Common Divisor (유클리드 호제법 사용)
    while(b!=0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int lcm(int a, int b){  // Least Common Multiple
    return a * b / gcd(a,b);
}

int main(){
    int T,M,N,x,y;

    cin >> T;
    while(T != 0){
        cin >> M >> N >> x >> y;
        int maxYear = lcm(M,N);
        int answer = -1;
        for(int i =x; i<= maxYear; i+= M){
            int tempY = i % N; // 현재 i번째 수를 N으로 나누었을 때
            if(tempY == 0) //나머지가 0이라는 건 y는 최대값
                tempY = N;
            if(tempY == y){
                answer = i; //유의미한 y값이 나왔다면 답을 찾았다.
                break;
            }
        }
        cout << answer <<'\n';
        T--;
    }

    return 0;
}