//
// Created by newbi on 2024-01-23.
//
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=n;i>0;i--){
        for(int j =0;j<n-i;j++){
            cout << " ";
        }
        for(int k =0;k<2*i-1;k++){
            cout <<"*";
        }
        cout <<'\n';
    }
    for(int i=2;i<=n;i++){
        for(int j =n;j>i;j--){
            cout << " ";
        }
        for(int k =0;k<2*i-1;k++){
            cout <<"*";
        }
        cout <<'\n';
    }
    return 0;
}
