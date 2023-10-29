//
// Created by newbi on 2023-10-27.
//
#include <iostream>

using namespace std;
int T,sm;
bool isOdd(int n){
    return n % 2;
}
void reset(){
    sm = 0;
}
int main(){
    cin >> T;
    for(int i=0;i<T;i++){
        int tmp;
        for(int j=0;j<10;j++){
            cin >> tmp;
            if(isOdd(tmp)) sm += tmp;
        }
        cout << "#"<<i+1<<" "<<sm<<'\n';
        reset();
    }

    return 0;
}