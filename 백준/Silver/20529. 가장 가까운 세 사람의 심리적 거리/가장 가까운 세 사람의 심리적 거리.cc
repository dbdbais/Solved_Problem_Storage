//
// Created by newbi on 2023-08-14.
//
#include <iostream>
#include <vector>
using namespace std;

int calcDistance(string a, string b){   // MBTI 거리 반환
    int distance = 0;
    for(int i=0;i<4;i++){
        if(a[i] != b[i])
            distance++;
    }
    return distance;
}

int main(){

    int T, N;
    cin >> T;
    vector<vector<string>> vec;
    for (int i=0;i<T;i++){
        vector<string> tempRow;
        cin >> N;
        for(int j=0;j<N;j++){
            string temp;
            cin >> temp;
            tempRow.push_back(temp);
        }
        vec.push_back(tempRow);
        if(N>32){       //비둘기집 원리로 32를 넘어가면 3개이상의 같은 MBTI가 하나 이상 생긴다.
            cout<< 0<<'\n';
        }
        else{
            int answer = 9999;
            for(int a=0;a<N-2;a++){
                for(int b=a+1;b<N-1;b++){
                    for(int c= b+1; c<N;c++){
                        answer = min(answer, calcDistance(vec[i][a],vec[i][b])+ calcDistance(vec[i][b],vec[i][c])
                        +calcDistance(vec[i][c],vec[i][a]));
                    }
                }
            }
            cout << answer<<'\n';
        }
    }
    return 0;
}