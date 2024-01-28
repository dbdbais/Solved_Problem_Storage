//
// Created by newbi on 2024-01-28.
//
#include <iostream>

using namespace std;

int n;

void solve(){
    for(int i=0;i<n;i++){
        if( !(i % 2) ){
            for(int j=0;j<n;j++){
                cout << "* ";
            }
        }
        else{
            for(int j=0;j<n;j++){
                cout << " *";
            }
        }
        cout <<'\n';
    }
}

int main(){

    cin >> n;
    solve();

    return 0;
}
