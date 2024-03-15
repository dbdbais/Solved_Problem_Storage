//
// Created by newbi on 2024-03-15.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

struct Date{
    int startMonth;
    int startDay;
    int endMonth;
    int endDay;

    Date(int startMonth,int startDay,int endMonth,int endDay):startMonth(startMonth),startDay(startDay),endMonth(endMonth),endDay(endDay){
    }

    bool operator<(const Date d){
        if(endMonth == d.endMonth){
            return endDay > d.endDay;
        }
        else{
            return endMonth > d.endMonth;
        }
    }

};

int N;
vector<Date> vec;
int main(){
    fastIO();
    cin >> N;
    int sm,sd,em,ed;
    For(i,0,N){
        cin >> sm >> sd >> em >>ed;
        vec.push_back(Date(sm,sd,em,ed));
    }
    sort(vec.begin(),vec.end());

//    for(Date d : vec){
//        cout << d.startMonth <<" ~ " <<d.startDay <<" : " << d.endMonth <<" ~ " <<d.endDay <<endl;
//    }
    int cnt =0;
    int cursM =3;
    int cursD = 1;

    bool found;
    while(true){
        found = false;
        for(Date d : vec){
            if( d.endMonth < cursM ||(cursM == d.endMonth && d.endDay<=cursD)) continue;    //자기보다 낮은 건 보지 않는다.
            if((d.startMonth < cursM ) || (d.startMonth == cursM && d.startDay <= cursD)){
                cursM = d.endMonth;
                cursD = d.endDay;   //끝나는 날 갱신
                //cout << cursM <<", "<< cursD << " updated"<<endl;
                cnt++;
                found = true;
                break;
            }
        }
        if(!found || cursM >= 12) break;
    }
    if(!found){
        cnt =0;
    }
    cout << cnt <<endl;
    
    return 0;
}