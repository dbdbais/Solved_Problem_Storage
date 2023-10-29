//
// Created by newbi on 2023-09-14.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,lo=1,hi,mid,ans=1e9;
vector<int> jewel(300004,0);    //보석 저장 vector

bool check(int val){    //질투심을 val로 설정했을 때 보석들을 무사히 나누어줄 수 있는지 check
    int tmp = 0;
    for(int i=0;i<M;i++){
        tmp += jewel[i]/val;    //몫
        if(jewel[i] % val) tmp++;   //나머지
    }
    return N >= tmp;    //나누어 줄 수 있냐?
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> jewel[i];
        hi = max(hi,jewel[i]);  //보석 중에 가장 많은 것 찾는다
    }
    while(lo <= hi){
        mid = (lo + hi)/ 2;
        if(check(mid)){   //mid가 성립했다면
            ans = min(ans,mid); //가장 작은 값을 갱신
            hi = mid-1;     // 왼쪽 이분 탐색
        }
        else{   //성립하지 않았다면
            lo = mid+1; //오른쪽 이분탐색
        }
    }
    cout << ans <<'\n';
    return 0;
}
