//
// Created by newbi on 2024-05-26.
//
#include <iostream>
#include <vector>

#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int aNum[1000004];
int aDP[2004];
int bNum[1000004];
int bDP[2004];
int ans;
int N,M,pizza,tmp;

vector<int> aVec,bVec;


void makeCount(){
    For(i,1,M){ //i만큼 검색
        For(j,0,M){ //j 부터
            aNum[aDP[j+i] - aDP[j]]++;
        }
    }
    int aSM =0;
    For(i,0,M){
        aSM += aVec[i];
    }
    aNum[aSM]++;

    For(i,1,N){ //i만큼 검색
        For(j,0,N){ //j 부터
            bNum[bDP[j+i] - bDP[j]]++;
        }
    }
    int bSM =0;
    For(i,0,N){
        bSM += bVec[i];
    }
    bNum[bSM]++;
}
void solve(){
    int _left = 1;
    int _right = pizza-1;

    while(_left <= _right){
        //같은 값으로 만들 때 유의
        if(_left == _right){
            ans += (aNum[_left] * bNum[_right]);
        }
        else{
            ans += (aNum[_left] * bNum[_right]);
            ans += (bNum[_left] * aNum[_right]);
        }
        _left++;
        _right--;
    }
    ans += aNum[pizza];
    ans += bNum[pizza];
}

void input(){
    For(i,0,M){
        cin >> tmp;
        aVec.push_back(tmp);
    }
    For(i,0,M){
        aVec.push_back(aVec[i]);
    }
    For(i,1,2*M){
        aDP[i] = aDP[i-1] + aVec[i-1];
    }
    For(j,0,N){
        cin >> tmp;
        bVec.push_back(tmp);
    }
    For(j,0,N){
        bVec.push_back(bVec[j]);
    }
    For(j,1,2*N){
        bDP[j] = bDP[j-1] + bVec[j-1];
    }
}


int main(){
    fastIO();
    cin >> pizza >> M >> N;
    input();
    makeCount();
    solve();
    
    cout << ans << endl;
    return 0;
}