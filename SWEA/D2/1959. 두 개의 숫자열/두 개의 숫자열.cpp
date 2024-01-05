#include<iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int N,M,T,diff,lss;
 
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
}
 
int main(){
     
    fastIO();
     
    cin >> T;
     
    for(int idx =1;idx<=T;idx++){
        int ans = 0;
        vector<int> a(21,0);  //작
        vector<int> b(21,0);  //큰
        cin >> N >> M;
        if(N >= M){
        lss = M;
     
        for(int j=0;j<N;j++) {
            cin >> b[j];
        }
        for(int k=0;k<M;k++) {
        cin >> a[k];
    }
            diff = N-M;
        }
        else {  //M이 더 클때
        lss = N;
        for(int j=0;j<N;j++) {
            cin >> a[j];
        }
        for(int k=0;k<M;k++) {
        cin >> b[k];
    }
            diff = M-N;
        }
        for(int i=0;i<=diff;i++){
            int sm = 0;
            for(int j=0;j<lss;j++){
                  sm += a[j] * b[j+i];
            }
          ans = max(ans,sm);
        }
       cout <<"#"<<idx<<" "<<ans<<'\n';
    }
     
     
    return 0;
}