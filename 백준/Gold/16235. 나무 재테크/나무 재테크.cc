//
// Created by newbi on 2023-09-24.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M,K,ans;
vector<vector<int>> soil(12,vector<int>(12,5)); //초기 양분
vector<vector<int>> A(12,vector<int>(12,0));   //S2D2의 추가 양분
vector<int> tree[12][12];   //벡터를 원소로 가지는 2차원 배열 (이렇게 구현하지 않으면 시간초과)
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
          cin >> A[i][j];
        }
    }
    int x,y,z;
    for(int i=1;i<=M;i++){
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    while(K){
        //봄, 여름
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(tree[i][j].empty()) continue;    //트리에 값이 없다면 SKIP
                int dead = 0;
                vector<int>temp;
                sort(tree[i][j].begin(),tree[i][j].end());  //낮은 나이 부터 양분 먹게 정렬
                for(auto elem : tree[i][j]){
                    if(soil[i][j] - elem >= 0){ //양분이 충분하다면
                        soil[i][j] -= elem;
                        temp.push_back(elem+1);
                    }else{
                        dead += elem /2;    //아니라면 죽은 나무에 저장
                    }
                }
                tree[i][j] = temp;  //새로운 나무들로 대체;
                soil[i][j] += dead; //죽은 나무의 양분
            }
        }
        //가을
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(tree[i][j].empty()) continue;
                for(auto elem : tree[i][j]){
                    if(elem % 5 == 0){
                        for(int a=0;a<8;a++){
                            int qx = i + dx[a];
                            int qy = j + dy[a];
                            if(qx < 1 || qx >N || qy <1 || qy >N) continue; //맵을 벗어나면 SKIP
                            tree[qx][qy].push_back(1);  //새로운 나무가 자람
                    }
                }
                }
            }
        }

            //겨울
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    soil[i][j] += A[i][j];
                }
            }

        K--;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(tree[i][j].empty()) continue;
                ans += tree[i][j].size();
        }
    }
    cout << ans <<'\n';
    return 0;
}

