//
// Created by newbi on 2023-08-08.
//

#include <iostream>
#include <vector>
#include<string>
using namespace std;

void VPS(string text){
    vector<char> vec;
    bool suc = true;
    for(auto ch: text){
        if(ch == '('){
            vec.push_back(ch);
        }
        else if(ch ==')'){
            if(vec.empty()){
                suc = false;
                cout<<"NO"<<"\n";
                break;
            }
            vec.pop_back();
        }
    }

    if(suc){
        if(vec.empty()){
            cout<<"YES\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }

}

int main(){
    int n;
    string text;
    cin>>n;
    for(int i=0;i<n;i++){
        cin >>text;
        VPS(text);
    }
    return 0;
}