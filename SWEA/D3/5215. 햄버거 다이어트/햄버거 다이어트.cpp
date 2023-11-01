//
// Created by newbi on 2023-11-01.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T,N,L,ans,totCal,totScore;
vector<pair<int,int>> vec; //칼로리, score

void input(){
    int score,calories;
    for(int i=0;i<N;i++){
        cin >> score >> calories;
        vec.push_back({calories,score});
    }
}
void reset(){
    vec.clear();
    ans = 0;
}
void DFS(int start){
    if(totCal <= L){
        //cout << ans<<endl;
        ans = max(ans,totScore);
    }
    else{
        return;
    }

    for(int i=start+1;i<N;i++){
        totScore += vec[i].second;
        totCal += vec[i].first;
        DFS(i);
        totScore -= vec[i].second;
        totCal -= vec[i].first;
    }
    return;
}
void solve(){
    sort(vec.begin(),vec.end());
    DFS(-1);
}
int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> N >> L;
        input();
        solve();
        cout << "#"<<i<<" "<<ans<<'\n';
        reset();
    }
    return 0;
}