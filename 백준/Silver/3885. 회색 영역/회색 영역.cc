//
// Created by newbi on 2024-06-11.
//

#include <iostream>
#include <cstring>

#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

//N 히스토그램 개수, W 구간의 크기
int N, W;

int V[101];
double height[101];
double color[101];
// 밝기

void print(int mxIdx){
    For(i,0,mxIdx+1){
        cout << height[i] << " ";
    }
    cout << endl;
    For(i,0,mxIdx+1){
        cout << color[i] << " ";
    }
    cout << endl;
}

double solve(int mxIdx){
    double ret = 0.0;
    For(i,0,mxIdx+1){
        ret += (height[i] * color[i]);
    }
    ret += 0.01;

    return ret;
}
void reset(){
    memset(V,0,sizeof(V));
    memset(height,0,sizeof(height));
    memset(color,0,sizeof(color));
}

int main(){
    fastIO();
    while(cin >> N >> W){
        if(N == 0 && W ==0) break;
        reset();
        int val;
        int mx = 0;
        int mxIdx = 0;
        For(i,0,N){
            cin >> val;
            int idx = val / W;
            //cout << idx << endl;
            V[idx]++;
            if(mxIdx < idx) mxIdx = idx;
            if(mx < V[idx]) mx = V[idx];
        }
        //int M = mxIdx-1;
        For(i,0,mxIdx+1){
            height[i] = V[i] * 1.0 / mx;
            //상대 높이로 저장
            color[i] = (mxIdx-i)*1.0 / (mxIdx);
        }
        //print(mxIdx);
        cout << solve(mxIdx) << endl;
    }
    return 0;
}