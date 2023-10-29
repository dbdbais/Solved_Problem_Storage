//
// Created by newbi on 2023-08-14.
//
#include <iostream>

#include<string>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    string temp= "";
    bool minus = false;
    int result = 0;
    cin >> input;
    for(int i=0;i<=input.size();i++){
        if(input[i]=='+' || input[i] == '-' || input[i]=='\0'){
            if(minus){ //마이너스 만났을 시
                result -= stoi(temp);
            }
            else{
                result += stoi(temp);
            }
            temp = "";
            if (input[i]=='-')
                minus = true;
        }
        else
        {
        temp+= input[i];
        }
    }
    cout << result;
    return 0;
}