//
// Created by newbi on 2023-08-27.
//
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec(51,vector<int>(51,0));
vector<vector<int>> com;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
void combi(int idx,int M, vector<int> v){   //치킨집의 모든 인덱스 조합
    if(v.size() == M){
        com.push_back(v);
        return;
    }
    for(int i= idx+1 ; i < chicken.size();i++){
        v.push_back(i);
        combi(i,M,v);
        v.pop_back();
    }
    return;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M ;
    cin >> N >> M;
    for(int i =1;i<=N;i++){
        for(int j=1;j<=N;j++) {
            cin >> vec[i][j];
            if(vec[i][j]==1){
                house.push_back(make_pair(i,j));
            }
            else if(vec[i][j]==2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }
    vector<int> v;
    combi(-1,M,v);  // 치킨 인덱스 조합 생성
    int result = 99999999;
    for(auto cRow : com){   //조합 배열중에 M개의 idx를 가지고 있는 행을 뽑고
        int cdSum = 0;  //이 치킨집 C M 조합의 치킨거리가 저장될 변수
        for(auto homeCord: house){  //집의 좌표
            int chickenDistance = 99999999;
            for(auto idx : cRow){   //M개의 치킨집의 인덱스를 가지는 idx
                int distance = abs(homeCord.first - chicken[idx].first) + abs(homeCord.second - chicken[idx].second);
                chickenDistance = min(chickenDistance,distance);    //최소의 치킨거리 계산
            }
            cdSum += chickenDistance; //이번 조합 case 의 치킨거리의 합
        }
        result = min(result,cdSum); //가장 최소의 치킨거리 result에 저장
    }
    cout << result << '\n';
    /*
    for(int i =1;i<=N;i++){
        for(int j=1;j<=N;j++)
            cout<< vec[i][j]<<" ";
        cout << endl;
    }*/
    return 0;
}