//
// Created by newbi on 2024-06-19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int N,M,K,ans;
vector<int> ipt[102];
bool selected[102];
vector<int> keyboard;

void combi(int start, int idx){
    if(idx == N){
        /*
        For(i,1,11){
            if(selected[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
         */
        int cnt = 0;
        For(i,0,M){
            bool isOk = true;
            for(auto sKey : ipt[i]){
                if(!selected[sKey]){
                    isOk = false;
                    break;
                }
            }
            if(isOk) cnt++;
        }
        if(ans < cnt) ans = cnt;

        return;
    }
    /*
    For(i,start+1,keyboard.size()){
        selected[keyboard[i]] = true;
        combi(i,idx+1);
        selected[keyboard[i]] = false;
    }
     */
    for(int i=start+1;i<= 2*N+1;i++){
        selected[i] = true;
        combi(i,idx+1);
        selected[i] = false;
    }

}

int main(){
    fastIO();
    cin >> N >> M >> K;
    int tmp;
    For(i,0,M){
        For(j,0,K){
            cin >> tmp;
            ipt[i].push_back(tmp);
            keyboard.push_back(tmp);
        }
    }
    sort(keyboard.begin(),keyboard.end());
    keyboard.erase(unique(keyboard.begin(),keyboard.end()),keyboard.end());
    //중복 삭제

    combi(0,0);
    //각자 조합 만들어서 확인

    cout << ans << endl;

    return 0;
}