//
// Created by newbi on 2024-02-20.
//
#include <iostream>
#include <vector>
#include <cmath>

#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n';

using namespace std;

int N,T,M,C,ans;

int honey[13][13];
bool visited[13][13];

int tmpSm;

void partial(int idx, vector<int> v,int sm,vector<int> vec) {

    if (idx == vec.size()) {
        if(sm <= C){
            int t =0;
            for(auto elem :v){
                t += pow(elem,2);
            }
            tmpSm = max(tmpSm, t );
        }
        return;
    }

    v.push_back(vec[idx]);
    partial(idx + 1,v,sm + vec[idx],vec);
    v.pop_back();
    partial(idx + 1,v,sm,vec);
}
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool out(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= N;
}

void ipt() {
    For(i, 0, N) {
        For(j, 0, N) {
            cin >> honey[i][j];
        }
    }
}

void print(){
    For(i,0,N){
        For(j,0,N){
            cout << visited[i][j] <<" ";
        }
        cout <<endl;
    }
    cout << endl;
    For(i,0,N) {
        For(j, 0, N) {
            cout << honey[i][j] << " ";
        }
        cout <<endl;
    }
        cout << endl;
}
void collect(){
    int temp =0;
    vector<int> avec;
    vector<int> bvec;

    int cnt =0;
    int asum=0, bsum =0;
    For(i,0,N){
        For(j,0,N){
            if(visited[i][j]){
                cnt++;
                if(cnt <= M){
                    asum += honey[i][j];
                    avec.push_back(honey[i][j]);
                }
                else{
                    bsum += honey[i][j];
                    bvec.push_back(honey[i][j]);
                }
            }
        }
    }
    if(asum <= C){
        for(int h : avec){
            temp += pow(h,2);
        }
    }
    else{   //부분 조합
        tmpSm = 0;
        vector<int>v;
        partial(0,v,0,avec);
        temp += tmpSm;
    }

    if(bsum <= C){
        for(int h : bvec){
            temp += pow(h,2);
        }
    }
    else{   //부분조합
        tmpSm = 0;
        vector<int>v;
        partial(0,v,0,bvec);
        temp += tmpSm;
    }
    /*
    cout << "avec : ";
    for(auto elem : avec){
        cout <<elem <<" ";
    }
    cout <<endl;
    cout << "bvec : ";
    for(auto elem : bvec){
        cout <<elem <<" ";
    }
    cout <<endl;
    cout << temp <<endl;
     */
    ans = max(ans,temp);

}

void solve(int cnt,int row) {
    if (cnt == 2) {	//2명의 일 꾼이 다 했을 경우
        collect();
        //print();
        return;
    }
    For(i,row,N) {
        For(j, 0, N) {
            if(out(i,j+M-1) || visited[i][j]) continue; 	//맵 밖으로 나가거나 방문 했다면
            bool found = false;
            For(k,0,M){
                if(visited[i][j+k]) found = true;
            }
            if(found) continue;

            For(k, 0, M) {
                visited[i][j + k] = true;	//방문 처리
            }
            solve(cnt + 1,i);
            For(k, 0, M) {
                visited[i][j + k] = false;	//원상 복구
            }
        }
    }

}


int main() {
    fastIO();

    cin >> T;
    For (t, 1, T + 1) {
        cin >> N >> M >> C;
        ipt();
        solve(0,0);
        cout <<"#"<<t<<" "<<ans <<endl;
        ans = 0;
    }



    return 0;
}


/*
N * N개의 벌통 정사각형으로 배치

각 칸의 숫자는 꿀의 양을 나타내지만 양이 다를 수 있다.

16개의 벌통

각 벌통에 있는 꿀의 양이 주어질 때,

두명의 일꾼 = > 가로로 연속되도록 M개의 벌통 선택 후 채취

두 명의 일꾼이 선택한게 겹치면 안됨

용기에 담는다.하나의 벌통->하나의 용기에 담는다

모든 꿀을 한방에 채취한다.

C = 일꾼이 채취할 수 있는 최대 양이고, 초과하면 하나만 채취

하나의 용기에 있는 꿀의 양이 많을 수록 가치 높아 제곱만큼 수익이 생긱ㄴ다.

두 일 꾼이 얻을 수 있는 수익의 합이 최대가 되는 경우 찾고, 최대 수익 출력


꿀 C M 의 조합을 생성한 후에->C가 크면 전부 채취해 각자 저장 후 최대 값 갱신
C가 충분히 크지 않다면 벌통의 부분조합을 생성해 추출 후 비교
*/

