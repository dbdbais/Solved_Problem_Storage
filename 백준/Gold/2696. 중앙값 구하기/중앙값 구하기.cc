//
// Created by newbi on 2024-05-31.
//
#include <iostream>
#include <queue>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int M,T;

int arr[1001][10001];

void solve(int tc){
    priority_queue<int> npq; //최소 힙
    priority_queue<int,vector<int>,greater<int>> xpq;   //최대 힙
    int mid = arr[tc][0];
    if(M % 2 == 0){
        cout << M/2 << endl;
    }
    else{
        cout << M /2 +1 << endl;
    }

    cout << mid << " ";
    int cnt = 0;
    For(i,1,M){
        int val = arr[tc][i];

        if(val >= mid){
            xpq.push(val);
        }
        else if(val < mid){
            npq.push(val);
        }

        if(i% 2 == 0){
            cnt++;
            if(cnt % 10 == 0){
                cout << endl;
            }

            if(xpq.size() > npq.size()){
                npq.push(mid);
                mid = xpq.top();
                xpq.pop();
            }
            else if(xpq.size() < npq.size()){
                xpq.push(mid);
                mid = npq.top();
                npq.pop();
            }

            cout << mid << " ";
        }
    }
    cout << endl;


}

int main(){
    fastIO();
    cin >>T;
    For(a,0,T){
        cin >> M;
        For(i,0,M){
            cin >> arr[a][i];
        }
        solve(a);
    }

    return 0;
}