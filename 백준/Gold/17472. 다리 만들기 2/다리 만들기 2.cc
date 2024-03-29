//
// Created by newbi on 2024-03-29.
//
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

const int dx [] ={0,0,-1,1};
const int dy [] ={-1,1,0,0};

int N,M;
int arr [12][12];
int island[12][12];
bool visited[12][12];
int parents[7]; //부모
int colIdx = 0;
struct Edge{
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight):from(from),to(to),weight(weight){}

    bool operator <(Edge e){
        return weight < e.weight;
    }
    void print(){
        cout << from << " -> " << to << "  W : "<<weight <<endl;
    }
};
vector<Edge> edgeList;

void makeSet(){
    for(int i=1;i<=colIdx;i++){
        parents[i] = i;
    }
}

int find(int target){
    if(target == parents[target]) return target;
    return parents[target] = find (parents[target]);
}

bool unio(int a,int b){
    int aRoot = find(a);
    int bRoot = find(b);

    if(aRoot == bRoot) return false;

    parents[bRoot] = aRoot;
    return true;
}

bool out(int x,int y){
    return x< 0 || y <0 || x >= N || y >= M;
}

void input(){
    For(i,0,N){
        For(j,0,M){
            cin >> arr[i][j];
        }
    }
}


void BFS(int x,int y){
    colIdx++;
    queue<pair<int,int>> q;
    q.push({x,y});
    island[x][y] = colIdx;
    visited[x][y] = true;
    while(q.size()){
        auto cur = q.front(); q.pop();
        x = cur.first;
        y = cur.second;

        For(i,0,4){
            int qx = x + dx[i];
            int qy = y + dy[i];

            if(out(qx,qy) || arr[qx][qy] == 0 || visited[qx][qy]) continue;
            island[qx][qy] = colIdx;
            visited[qx][qy] = true;
            q.push({qx,qy});
        }
    }
}
void color(){
    For(i,0,N){
        For(j,0,M) {
            if(visited[i][j] || arr[i][j] == 0) continue;
            BFS(i,j);
        }
    }
}

void connectEdge(int x,int y){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    int val = island[x][y]; //현재 값 저장
    For(i,0,4){
        q.push({{i,0},{x,y}});
    }
    visited[x][y] = true;

    while(q.size()){
        int qSize = q.size();
        For(i,0,qSize){
            auto cur = q.front(); q.pop();
            int dir = cur.first.first;
            int cnt = cur.first.second;
            x = cur.second.first;
            y = cur.second.second;

            int qx = x + dx[dir];
            int qy = y + dy[dir];

            if(out(qx,qy)|| island[qx][qy] == val || visited[qx][qy]) continue;

            if(island[qx][qy] != 0){
                if(cnt > 1){
                    edgeList.push_back(Edge(val,island[qx][qy],cnt));
                }
                else{
                    continue;
                }
            }
            else{
                q.push({{dir,cnt+1},{qx,qy}});
            }
            visited[qx][qy] = true;
        }
    }


}

void findEdge(){
    For(i,0,N){
        For(j,0,M){
            if(island[i][j] == 0) continue;
            memset(visited,false,sizeof(visited));
            connectEdge(i,j);
        }
    }
}

void output(){
    For(i,0,N){
        For(j,0,M){
            cout << island[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    fastIO();
    cin >> N >> M;
    input();
    color();
    //output();
    findEdge();

    sort(edgeList.begin(),edgeList.end());
    makeSet();

    bool found = false;
    int ans =0;
    int eCount =0;
    for(Edge e : edgeList){
        if(!unio(e.from,e.to)) continue;
        ans += e.weight;
        if(++eCount == colIdx-1) {
            found = true;
            break;
        }
    }
    if(found){
        cout << ans << endl;
    }
    else{
        cout << -1 <<endl;
    }

    return 0;
}