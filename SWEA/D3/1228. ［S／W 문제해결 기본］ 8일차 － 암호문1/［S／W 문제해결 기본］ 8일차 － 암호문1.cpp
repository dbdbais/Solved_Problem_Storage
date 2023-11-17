//
// Created by newbi on 2023-11-18.
//
#include <iostream>
#include <vector>
using namespace std;
char c;
int x,y,N;

int main(){
    for(int i=1;i<=10;i++){
        vector<int> plain;
        vector<int> temp;
        int tmp;
        cin >> N;
        for(int j=0;j<N;j++){
            cin >> tmp;
            plain.push_back(tmp);
        }
        cin >> N;
        for(int j=0;j<N;j++){
            cin >> c >> x >> y;
            for(int k=0;k<y;k++){
                cin >> tmp;
                temp.push_back(tmp);
            }
            plain.insert(plain.begin()+x,temp.begin(),temp.end());  //삽입문 사용
            temp.clear();   //임시 벡터 초기화
        }

        cout << "#"<<i<<" ";
        for(int i=0;i<10;i++){
            cout << plain[i]<<" ";
        }
        cout <<'\n';
    }
    return 0;
}