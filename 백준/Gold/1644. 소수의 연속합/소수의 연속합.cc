//
// Created by newbi on 2023-09-11.
//투 포인터 + 에라토스테네스의 체
//
#include <iostream>
using namespace std;

int che[4000004];
int N, a[2000004],p,lo,hi,ret,sum;

void era(int input){     //에라토스테네스의 체 max값 안의 소수를 전부 구한다.

    for(int i=2;i<= input;i++){
        if(che[i]) continue;
        for(int j=i+i;j<=input;j+=i){
            che[j] = 1;
        }
    }
    for(int i=2;i <=input;i++)
        if(!che[i])
            a[p++] =i;  //인덱싱 현재 소수의 값을 집어넣는다.
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    era(N);

    while(true){    //이 반복문으로 연속된 소수의 합을 구할 수 있다.
        if(sum >= N) sum -= a[lo++];    //sum이 N보다 크거나 같다면 제일 작은 소수 제거
        else if(hi == p) break;         //끝까지 도달하면 break
        else sum += a[hi++];            //sum이 N보다 작다면 제일 큰 소수 제거
        if(sum == N) ret++; //같은 sum이 되면 ret증가
    }
    cout << ret <<'\n';
    return 0;
}