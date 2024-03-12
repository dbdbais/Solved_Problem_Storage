//
// Created by newbi on 2024-03-12.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

struct FireBall{
    int x;
    int y;
    int mass;
    int dir;
    int speed;

    FireBall(int x,int y,int mass,int dir,int speed):x(x),y(y),mass(mass),dir(dir),speed(speed){
    }
};

using namespace std;

int N,M,K,r,c,m,s,d;
bool visited[52][52];

const int dx[] = {-1,-1,0,1,1,1,0,-1};
const int dy[] = {0,1,1,1,0,-1,-1,-1};

int restrict(int num){
    if(num >= N){
        num = num % N;
    }
    else if(num < 0){
        num = (num % N + N) % N;
    }
    return num;
}

vector<FireBall> vec;
set<pair<int,int>> same;

void print(){
    For(i,0,N){
        For(j,0,N){
            cout << visited[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}

void solve(){
    while(K){
        same.clear();   //같은 지점 초기화
        memset(visited,false,sizeof(visited));

        for(FireBall &f : vec){  //모든 파이어볼이 이동한다.
            int qx = restrict(f.x + dx[f.dir] *f.speed);
            int qy = restrict(f.y + dy[f.dir] *f.speed);

            f.x = qx;
            f.y = qy;   //실제로 파이어 볼이 이동
            if(visited[qx][qy]){  //이미 누군가 있다면
                same.insert({qx,qy});
            }
            visited[qx][qy] =true;  //방문 처리
            //print();
        }


        for(auto cord : same){
            int totMass =0;
            int totNum = 0;
            int totSpeed = 0;
            set<int> st;
            for(FireBall &f : vec){
                if(f.x == cord.first && f.y == cord.second){
                    totNum++;
                    totMass += f.mass;
                    totSpeed += f.speed;
                    if(f.dir % 2 ==0){
                        st.insert(0);
                    }
                    else{
                        st.insert(1);
                    }
                    f.mass =0;  //없애기 위해 질량 초기화
                }
            }

            totMass = totMass/ 5;

            vec.erase(remove_if(vec.begin(),vec.end(),[=](FireBall f){
                return f.mass == 0;
            }),vec.end());  //질량 0 인 파이어 볼 삭제


            if(totNum == 0 || totMass == 0){
                continue;   //넘버가 없다면 다음 꺼로
            }
            totSpeed = totSpeed/ totNum;


            if(st.size() == 1){ //홀수나 짝수 중 하나만 있었다면
                for(int i : {0,2,4,6}){
                    vec.push_back(FireBall(cord.first,cord.second,totMass,i,totSpeed));
                }
            }
            else{
                for(int i : {1,3,5,7}){
                    vec.push_back(FireBall(cord.first,cord.second,totMass,i,totSpeed));
                }
            }

        }
        K--;
    }
    int sm =0;
    for(FireBall f : vec){
        sm += f.mass;
    }
    cout << sm << endl;

}

int main(){
    fastIO();
    cin >> N >> M >> K;
    For(i,0,M){
        cin >> r >> c >> m >> s >>d;
        vec.push_back(FireBall(r-1,c-1,m,d,s));
    }
    solve();

    return 0;
}
