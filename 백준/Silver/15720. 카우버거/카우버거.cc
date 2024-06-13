//
// Created by newbi on 2024-06-13.
//
#include <iostream>
#include <algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int B,C,D, sm;
int mScore[1001];
int sScore[1001];
int dScore[1001];

int calc(){
    int ret = sm;
    //최종
    int disCount = 0;
    int idx = 0;
    while(true){
        if(idx >= B || idx >= C || idx >= D) break;
        int tSm = mScore[idx] + sScore[idx] + dScore[idx];
        //cout << tSm << endl;
        disCount += tSm/10;
        idx++;
    }

    return ret - disCount;
}

int main(){
    fastIO();
    cin >> B >> C >> D;
    For(i,0,B){
        cin >> mScore[i];
        sm += mScore[i];
    }
    sort(&mScore[0],&mScore[0]+B,greater<int>());

    For(i,0,C){
        cin >> sScore[i];
        sm += sScore[i];
    }
    sort(&sScore[0],&sScore[0]+C,greater<int>());
    For(i,0,D){
        cin >> dScore[i];
        sm += dScore[i];
    }
    sort(&dScore[0],&dScore[0]+D,greater<int>());

    cout << sm << endl;
    cout << calc() << endl;

    return 0;
}