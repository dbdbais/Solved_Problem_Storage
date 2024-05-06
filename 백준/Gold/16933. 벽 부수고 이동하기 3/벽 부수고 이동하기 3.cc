//
// Created by newbi on 2024-05-06.
//
#include <iostream>
#include <queue>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 1e9
using namespace std;


int N,M,K,ans = -1;
int arr[1004][1004];
int visited[1004][1004][12];

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

struct Point{
    int x;
    int y;
    int chance;
    int _time;
    bool day;

    Point(int x,int y,int chance, int _time,bool day):x(x),y(y),chance(chance),_time(_time),day(day)
    {}

    void printInfo(){
        cout << "( "<<x <<", "<< y <<" )"<<"Chan : " <<chance <<" T: "<< _time <<" Day: "<<day << endl;
    }
};

bool out(int x,int y){
    return x < 1 || y < 1 || x > N || y > M;
}

void output(int k){

cout << "DP" <<endl;
    For(i,1,N+1){
        For(j,1,M+1){
            if(visited[i][j][k] == 0){
                cout << "I ";
            }
            else{
                cout << visited[i][j][k]<<" ";
            }

        }
        cout << endl;
    }
    cout << endl;


}

void input(){
    string s;
    For(i,1,N+1){
        cin >> s;
        For(j,0,M){
            arr[i][j+1] = s[j]-'0';
        }
    }
}

void solve(){
    queue<Point> q;
    q.push(Point(1,1,K,1,true));
    visited[1][1][K] = 1;
    while(q.size()){

        Point cur = q.front(); q.pop();

        //cur.printInfo();
        int x = cur.x;
        int y = cur.y;
        int chance = cur.chance;
        int _time = cur._time;
        bool day = cur.day;
        bool wait = false;

        if(x == N && y == M){
            ans = visited[x][y][chance];
            break;
        }

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)) continue;
            if(arr[qx][qy]){    //벽을 만났다면
                if(visited[qx][qy][chance-1]) continue;

                if(day && chance>0){
                    visited[qx][qy][chance-1] = _time+1;
                    q.push(Point(qx,qy,chance-1,_time+1,!day));
                }
                else{
                    wait = true;
                }
            }
            else{
                if(visited[qx][qy][chance]) continue;
                visited[qx][qy][chance] = _time+1;
                q.push(Point(qx,qy,chance,_time+1,!day));
            }
        }


        if(day == false && chance > 0 && wait){ //밤이고 벽을 부술 수 있는 기회가 남아있다면
            q.push(Point(x,y,chance,_time+1,!day));
            //밤낮 바꿔서 집어넣는다.
        }
        //output(chance);
    }

}

int main(){
    fastIO();
    cin >> N >> M >> K;
    input();
    solve();
    cout << ans << endl;

    return 0;
}