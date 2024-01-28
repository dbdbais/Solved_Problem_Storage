//
// Created by newbi on 2024-01-28.
//
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            cout<<" ";
        }
        if(i == 0)cout <<"*";
        else if(i==n-1){
            for(int k=0;k<2*(i+1)-1;k++){
                cout <<"*";
            }
        }
        else{
            cout <<"*";
            for(int k =0;k<1+2*(i-1);k++){
                cout <<" ";
            }
            cout <<"*";
        }
        cout <<'\n';
    }



    return 0;
}
