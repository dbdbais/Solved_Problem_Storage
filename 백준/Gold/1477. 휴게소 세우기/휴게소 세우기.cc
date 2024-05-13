//
// Created by newbi on 2024-05-13.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, L;

vector<int> station;

bool check(int mid){   //되는지 체크
    int cnt =0;
    for(int i=1;i<station.size();i++){
        int dist = station[i] - station[i-1];
        cnt += dist / mid;
        if(dist % mid == 0) cnt--;  //0으로 나누어떨어지면 마지막 정류장이 포함된 것
    }
    return M < cnt;
}

int solve() {
    int _left = 1;
    int _right = L-1;
    sort(station.begin(), station.end());
    //정렬 떄리고
    int mid, ret = 0;
    while(_left <= _right){
        mid = (_left + _right) / 2;
        //cout <<_left <<", "<<_right <<" : "<< mid << endl;
        if(check(mid)){
            _left = mid +1;
            //휴게소를 덜 지을 수 있도록 mid를 늘린다.

        }
        else{
            //cout << "updated"<<endl;
            ret = mid;
            _right= mid -1;
            //휴게소를 더 지을 수 있도록 mid를 줄인다.
        }
    }
    return ret;
}

int main() {

    int dst;

    fastIO();
    cin >> N >> M >> L;
    For(i, 0, N) {
        cin >> dst;
        station.push_back(dst);
    }
    station.push_back(0);
    station.push_back(L);

    cout << solve() << endl;

    return 0;

}