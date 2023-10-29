//
// Created by newbi on 2023-09-07.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k;
vector<string> ans; //정답의 집합
vector<char> vec(9,' ');    //부등호 들어가는 벡터
vector<bool> visited(9,false);  //알파벳의 방문 체크

bool oper(char op, int a, int b ){  //부등호에 따라 불린 값 출력
    if (op=='<')
        return a < b;
    else
        return a > b;
}

void DFS(int idx,string res){   //백트래킹 함수
    if (idx == k+1){
        ans.push_back(res); //정답 배열에 추가
        return;
    }
    for(int i=0;i<=9;i++) {
        if(visited[i]) continue;    //이미 방문 한 숫자라면 SKIP
        if (idx == 0 || oper(vec[idx-1],res[idx-1]-'0',i)){
            visited[i]  = true; //방문했다고 가정
            DFS(idx+1,res+ to_string(i));   //DFS로 다음 값 찾음
            visited[i] = false; //방문 안했을 경우 찾기 위해 원복
        }
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    char tmp;
    for(int i=0;i<k;i++){
        cin >> tmp;
        vec[i] = tmp;
    }
    DFS(0,"");

    sort(ans.begin(),ans.end());
    cout << ans[ans.size()-1] <<'\n'<< ans[0]<<'\n';
    return 0;
}