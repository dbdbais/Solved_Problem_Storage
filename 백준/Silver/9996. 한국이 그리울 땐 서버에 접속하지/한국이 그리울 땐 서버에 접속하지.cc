//
// Created by newbi on 2023-08-23.
//
#include<iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long pos;
    int N;
    string pattern;
    cin >> N >> pattern;
    pos = pattern.find('*');
    string pre = pattern.substr(0,pos);
    string suf = pattern.substr(pos+1);
    for(int i=0;i< N;i++){
        string input;
        cin >> input;
        if(input.length() < pre.length()+ suf.length() ){
            cout << "NE\n";
        }
        else{
            if( pre==input.substr(0,pre.length()) && suf == input.substr(input.length() - suf.length()))
                cout<< "DA\n";
            else{
                cout << "NE\n";
            }
        }
    }
    return 0;
}