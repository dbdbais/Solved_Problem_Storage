//
// Created by newbi on 2024-02-18.
//
#include <iostream>
#include <cstring>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int T, day,month,triple,year;
int plan[13] ;
int dp [13];

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    fastIO();

    cin >>T;
    For(t,1,T+1){
        cin >> day >> month >> triple >> year;

        For(i,1,13){    //계획 입력 받음
            cin >> plan[i];
        }

        For(i,1,13){    //메모제이션을 이용한 계산
            if(plan[i] == 0){
                dp[i] = dp[i-1];    //이전 상태 가져옴
            }
            else{   //값이 있다면
                int dayPay = dp[i-1]+plan[i]*day;  //1일치로 결제 했을 때
                int monthPay =dp[i-1]+month;
                dp[i] = min(dayPay,monthPay);   //둘 중에 작은거 넣고

                if(i>=3){   //3보다 크다면
                    int triplePay = dp[i-3]+triple;
                    dp[i] = min(dp[i],triplePay);   //3개월치랑 비교 해서 작은 값 넣음
                }

            }
            if(i == 12){    //1년 비용과 지금까지 계산한 값 비교
                dp[i] = min(year,dp[i]);
            }
        }
        /*
        cout <<endl;
        For(i,0,13){
            cout << i<<" ";
        }
        cout <<endl;
        For(i,0,13){
            cout << plan[i]<<" ";
        }
        cout <<endl;
        For(i,0,13){
            cout << dp[i]<<" ";
        }
        */
        cout << "#"<<t <<" "<<dp[12]<<endl;

        memset(dp,0,sizeof(dp));

    }

    return 0;
}