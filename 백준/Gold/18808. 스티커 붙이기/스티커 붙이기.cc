//
// Created by newbi on 2024-05-30.
//
#include <iostream>
#include <vector>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int N,M,K,a,b,ans;

vector<vector<int>> vec[101];

bool visited[41][41];

void output(){
    For(z,0,K){
        cout << z<<" : th" << endl;
        for(auto row : vec[z]){
            for(auto elem : row){
                cout << elem <<" ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

bool out(int x,int y){
    return x < 0 || y <0 || x >= N || y >= M;
}
void print(){
    For(i,0,N){
        For(j,0,M){
            cout << visited[i][j] <<" ";
        }
        cout << endl;
    }
    cout <<endl;
}

void rotate(int idx){
    auto &ret = vec[idx];
    int row = ret.size();
    int col = ret[0].size();
    vector<vector<int>> cpy (col,vector<int>(row,0));

    For(i,0,col){
        For(j,0,row){
            cpy[i][j] = ret[row-j-1][i];
        }
    }
    ret = cpy;
//    For(i,0,col){
//        For(j,0,row){
//            cout << ret[i][j] <<" ";
//        }
//        cout << endl;
//    }
}

bool isOK(int x,int y, vector<vector<int>> &v){
    int r = v.size();
    int c = v[0].size();
    For(i,x,x+r){
        For(j,y,y+c){
            if(out(i,j)) return false;
            if(v[i-x][j-y] == 1 && visited[i][j]) return false;
        }
    }

    For(i,x,x+r){
        For(j,y,y+c){
            if(v[i-x][j-y]) {
                ans++;
                visited[i][j] = true;
            }
        }
    }
    //대입
    return true;
}

void solve(){
    For(idx,0,K){
        bool found = false;
        int rotCnt = 0;
        while(!found){

            For(i,0,N){
                For(j,0,M){
                    if(isOK(i,j,vec[idx])){
                        found = true;
                        //print();
                        break;
                    }
                }
                if(found) break;
            }

            if(!found){
                rotCnt++;
                if(rotCnt > 3) break;
                else{
                    rotate(idx);
                }
            }
        }

    }
}

void input(int idx){
    int tmp;
    cin >> a >> b;
    For(i,0,a){
        vector<int> ipt;
        For(j,0,b){
            cin>>tmp;
            ipt.push_back(tmp);
        }
        vec[idx].push_back(ipt);
    }
}

int main(){
    fastIO();
    cin >> N >> M >> K;
    For(z,0,K){
        input(z);
    }
    solve();
    //output();
    cout << ans << endl;
    return 0;
}