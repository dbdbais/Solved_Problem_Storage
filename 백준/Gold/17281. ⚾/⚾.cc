//
// Created by newbi on 2024-03-03.
//
#include <iostream>
#include <cstring>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int N,ans;
int scores [51][12] ;
bool isSel[10];
int hit_order[10];
int roo[4];
int ord[10];
void play(){
    memset(roo,0,sizeof(roo));
    int tot_score =0;
    int cur_idx =1;
    int out =0;
    int inning =1;
    while(true){
        if(inning > N) break;   //이닝이 커지면

        if(scores[inning][hit_order[cur_idx]] == 1){//안타라면
           tot_score = tot_score+ roo[3];
           roo[3] = roo[2];
           roo[2] = roo[1];
           roo[1] = 1;
        }
        else if(scores[inning][hit_order[cur_idx]] == 2){
            tot_score = tot_score + roo[3] + roo[2];
            roo[3] =roo[1];
            roo[2] = 1;
            roo[1] = 0;
        }
        else if(scores[inning][hit_order[cur_idx]] == 3){
            tot_score = tot_score + roo[3] + roo[2] + roo[1];
            roo[3] =1;
            roo[2] = 0;
            roo[1] = 0;
        }
        else if(scores[inning][hit_order[cur_idx]] == 4){
            tot_score = tot_score + roo[3] + roo[2] + roo[1] + 1;
            For(j,1,4){
                roo[j] =0;
            }
        }
        else if(scores[inning][hit_order[cur_idx]] == 0){  //out
            out++;  //아웃 증가
        }

        if(out == 3){
            inning++;//이닝증가
            memset(roo,0,sizeof(roo));
            out =0;
        }
        cur_idx = (cur_idx % 9) + 1;

    }

    if(tot_score > ans) {
        ans = tot_score;
    }
}

void permutation(int idx){

    if(idx == 9){
        hit_order[4] = 1;
        for(int i=1;i<4;i++){
            hit_order[i] = ord[i];
        }
        for(int i=5;i<=9;i++){
            hit_order[i] = ord[i-1];
        }
        play();
//        for(int i=1;i<=9;i++){
//            cout << hit_order[i]<<" ";
//        }
//        cout <<endl;
        return;
    }

    for(int i=1;i<=9;i++){
        if(isSel[i]) continue;
        ord[idx] = i;
        isSel[i] = true;
        permutation(idx+1);
        isSel[i] = false;
    }
}

int main(){
    fastIO();
    cin >> N;

    For(i,1,N+1){
        For(j,1,10){
            cin >> scores[i][j];    //야구선수 점수
        }
    }

    isSel[1] = true;
    permutation(1);

    cout << ans << endl;


    return 0;
}