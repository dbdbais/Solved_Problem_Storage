#include <iostream>
#include <queue>
#include <vector>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int T,N,M,C;
int arr[15][15];
int ans;
struct Honey{
    int x;
    int y;
    int profit = 0;
    Honey(int x,int y,int profit):x(x),y(y),profit(profit){
    }

    bool operator<  (const Honey h) const{
        return profit < h.profit;
    }
};

int tmpSum;
bool isSel[15];

void partial(vector<int>p,int idx){
    if(idx == p.size()){
        int t =0;
        int tsq =0;
        for(int i=0;i<p.size();i++){
            if(isSel[i]){
                t += p[i];
                tsq += p[i]*p[i];
            }
        }
        if(t <=C && tmpSum <= tsq){
            tmpSum = tsq;
        }
        return;
    }
    isSel[idx] = true;
    partial(p,idx+1);
    isSel[idx] = false;
    partial(p,idx+1);

}

priority_queue<Honey> pq;
void solve(){
    For(i,0,N){
        for(int j=0;j<N-M+1;j++){
            vector<int> tmp;
            int tmpSm = 0;
            for(int k= j;k<j+M;k++){
                //cout << arr[i][k] <<" ";
                tmp.push_back(arr[i][k]);
                tmpSm += arr[i][k];
            }
            //cout <<endl;
            if(tmpSm <= C){
                int finSum =0;
                for(auto elem : tmp){
                    finSum += (elem * elem);
                }
                pq.push(Honey(i,j,finSum));
            }
            else{
                tmpSum = 0;
                partial(tmp,0);
                pq.push(Honey(i,j,tmpSum));
            }
        }
    }

    if(pq.size()){
        Honey prv = pq.top();
        pq.pop();
        ans = prv.profit;
        while(pq.size()){
            Honey cur = pq.top();
            pq.pop();
            if(prv.x == cur.x){
                if(prv.y + M -1 >= cur.y || cur.y + M-1 >= prv.y){
                    continue;
                }
            }
            ans += cur.profit;
            break;
        }
    }

    while(pq.size()){
        pq.pop();
    }
}


int main(){
    fastIO();
    cin >> T;

    For(t,1,T+1){
        cin >> N >> M >> C;
        For(i,0,N){
            For(j,0,N){
                cin >> arr[i][j];
            }
        }
        solve();
        cout << "#" <<t<<" "<<ans <<endl;
        ans = 0;
    }

    return 0;
}