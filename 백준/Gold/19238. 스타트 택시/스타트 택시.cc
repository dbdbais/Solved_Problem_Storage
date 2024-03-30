//
// Created by newbi on 2024-03-31.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

struct Customer{
    int x;
    int y;
    int endX;
    int endY;
    int dist;
    bool life = true;

    Customer(int x,int y,int endX,int endY):x(x),y(y),endX(endX),endY(endY){}

    bool operator <(Customer c){
        if(dist == c.dist){
            if(x == c.x){
                return y < c.y;
            }
            else{
                return x < c.x;
            }
        }
        else {
            return dist < c.dist;
        }
    }

    void setDitance(int dis){
        dist = dis;
    }
    void turnOff(){
        life =false;
    }

};

vector<Customer> customers;

int N,M,fuel,startX,startY,cusCnt;

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

bool out(int x,int y){
    return x <1 || y <1 || x > N || y > N;
}
int arr[22][22];
int visited[22][22];

void input(){
    For(i,1,N+1){
        For(j,1,N+1){
            cin >> arr[i][j];
        }
    }
}

void print(){
    For(i,1,N+1){
        For(j,1,N+1){
            cout << visited[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(int x,int y){
    memset(visited,0,sizeof(visited));

    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;

    while(q.size()){
        auto cur = q.front(); q.pop();
        x = cur.first;
        y = cur.second;

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy)||arr[qx][qy] == 1 || visited[qx][qy] > 0) continue;
            visited[qx][qy] = visited[x][y] +1;
            q.push({qx,qy});
        }

    }

}
void distUpdate(){
    for(Customer &c : customers){
        if(!c.life) continue;
        int val;
        if(visited[c.x][c.y] != 0 ){
            val = visited[c.x][c.y]-1;
        }
        else{
            val = 1e9;
        }
        c.setDitance(val); //최단 거리로 업데이트
    }
}
bool drive(){
    sort(customers.begin(),customers.end());
    for(Customer &c : customers){
        if(!c.life) continue;
        if(c.dist<= fuel){
            fuel -= c.dist; //연료 뺴고
            //cout << fuel << endl;
            startX = c.x;
            startY = c.y;   //택시 이동
            BFS(startX,startY); //이동한 점 기준으로 위치 갱신
            //print();
            int dest;
            if(visited[c.endX][c.endY] != 0 ){
                dest = visited[c.endX][c.endY]-1;
            }
            else{
                dest = 1e9;
            }
            if(fuel >= dest){
                fuel -= dest;
                //cout << fuel << endl;
                startX = c.endX;
                startY = c.endY;
                c.turnOff();
                fuel += (dest * 2); //2배를 채워준다.
                cusCnt++;
                return true;
            }
            else{
                return false;
            }

        }
        else{
            return false;
        }
    }
}

void solve(){
    bool notPossible = false;
    while(cusCnt < M){
        BFS(startX,startY); //현재 시점으로 모든 최단 거리 갱신
        //cout << fuel << endl;
        //print();
        distUpdate();   //고객의 거리 갱신
        if(!drive()){
            notPossible = true;
            break;
        }
    }
    if(notPossible){
        cout << -1 << endl;
    }
    else{
        cout << fuel << endl;
    }
}

int main(){
    fastIO();
    cin >> N >> M >> fuel;
    input();
    cin >> startX >> startY;

    int a,b,c,d;
    For(i,0,M){
        cin >> a >> b >> c >> d;
        customers.push_back(Customer(a,b,c,d));
    }
    solve();


    return 0;
}