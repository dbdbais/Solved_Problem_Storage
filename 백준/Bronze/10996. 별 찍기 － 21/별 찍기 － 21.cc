//
// Created by newbi on 2024-01-28.
//
#include <iostream>

using namespace std;

int n;

void solve(){
    for(int i=0;i<2*n;i++){
        if( !(i % 2) ){
            for(int j=0;j<n;j++){
                if(!(j%2)){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(!(j%2)){
                    cout << " ";
                }
                else{
                    cout << "*";
                }
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
