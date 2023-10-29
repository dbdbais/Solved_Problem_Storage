//
// Created by newbi on 2023-09-14.
//
#include <iostream>
#include <vector>
using namespace std;
int N, M , lo ,hi,mid,ans = 1e9;
vector<int> movie(100004,0);

bool check(int val){
    int temp = val;
    int cnt =0; //사용된 블루레이 수
    for(int i=0;i<N;i++){
        temp -= movie[i];
        if(temp < 0){   //뺀 결과가 음수라면
            cnt++;  //블루레이 추가
            temp =val;  //원복
            temp -= movie[i];   //다시 뺀다
        }
    }
    if(temp != val) cnt++;  //마지막 요소가 temp에 쓰였다면 추가 블루레이 연산
    //cout <<"cnt: " <<cnt << endl;
    return cnt <= M;    //강의가 M개의 블루레이로 담기는 지 T/F
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> movie[i];
        hi += movie[i]; //블루레이의 최대 값
        lo = max(lo,movie[i]);  //블루레이의 최소 값
    }
    while(lo <=hi){
        mid = (hi+lo)/2;    //블루레이 수용량
        //cout << mid <<endl;
        if(check(mid)){
            ans = min(ans,mid);
            hi= mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    cout << ans <<'\n';
    return 0;
}