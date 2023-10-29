//
// Created by newbi on 2023-09-11.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,arrival,_end;
vector<pair<int,int>> room;
vector<pair<int,int>> ans;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arrival >> _end;
        room.push_back(make_pair(_end,arrival));
    }
    sort(room.begin(),room.end());
    ans.push_back(room[0]);

    for(int i=1;i<N;i++){
        if(ans[ans.size()-1].first <= room[i].second)
            ans.push_back(room[i]);
    }
    cout << ans.size() <<'\n';

    return 0;
}