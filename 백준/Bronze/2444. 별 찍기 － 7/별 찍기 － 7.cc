//
// Created by newbi on 2024-01-23.
//
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        for(int k=0;k<n-1-i;k++){
            cout <<" ";
        }
        for(int j=0;j<1+2*i;j++){
            cout <<"*";
        }
        cout <<endl;
    }
    for(int i=n-1;i>=0;i--){
        for(int k=i;k<n-1;k++){
            cout <<" ";
        }
        for(int j=0;j<1+2*i;j++){
            cout <<"*";
        }
        cout <<endl;
    }

    return 0;
}
