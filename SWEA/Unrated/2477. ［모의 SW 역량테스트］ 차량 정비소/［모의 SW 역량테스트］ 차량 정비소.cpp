//
// Created by newbi on 2024-02-29.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;

struct Customer{
    int no; //그냥 번호
    int bno; //부스 번호
    int time;

    Customer(int no,int time):no(no),time(time){}
    void setBno(int num){
        bno = num;
    }
    bool operator< (const Customer c) const{
        if(time == c.time){
            return bno > c.bno;
        }
        return time > c.time;
    }
};

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int T,N,M,K,A,B;
int an[11];
bool aUsed[11];
int bn[11];
bool bUsed [11];
int tim[1002];
queue<Customer> q;
pair<int,int> ans[1002];

void solve(){
    int t =0;
    priority_queue<Customer> pq ;
    vector<Customer> cus;
    vector<Customer> rep;
    while(true){

        for(Customer & c : cus){
            c.time--;
            if(c.time == 0){    //대기 시간이 끝났다면
                aUsed[ans[c.no].first-1] = false;    //이용 초기화
                Customer temp(c.no,t);
                temp.setBno(ans[c.no].first);
                pq.push(temp);  //우선순위 큐에 현재시간 푸쉬
            }
        }

        cus.erase(remove_if(cus.begin(),cus.end(),[&](Customer c){
            return c.time == 0;
        }),cus.end());  //0인거 벡터에서 지워버림

        while(q.size()){    //지금 시간에 나오는 고객 cus에 넣어준다.
            int wait =q.front().time;    //맨 앞의 요소를 본다
            if(wait > t) break;    // 맨 앞의 요소가 지금 시간과 다르면
            Customer cur = q.front();
            bool isFull =true;
            for(int i =0;i<N;i++){
                if(aUsed[i]) continue;
                aUsed[i] = true;
                ans[cur.no].first = i+1;  //어느 부스 이용했는디
                cus.push_back(Customer(cur.no,an[i]));   //사용 중인 부스
                q.pop();
                isFull =false;
                break;
            }
            if(isFull) break;
        }

        for(Customer & c : rep){
            c.time--;
            if(c.time == 0){    //대기 시간이 끝났다면
                bUsed[ans[c.no].second-1] = false;    //이용 초기화
            }
        }
        rep.erase(remove_if(rep.begin(),rep.end(),[&](Customer c){  //지워 준다.
            return c.time == 0;
        }),rep.end());


        for (int i = 0; i < M; i++) {
            if(pq.empty()) break;
            if (bUsed[i]) continue;
            bUsed[i] = true;
            Customer cur = pq.top();
            pq.pop();
            ans[cur.no].second = i+1;   //두번째 부스 어디
            rep.push_back(Customer(cur.no, bn[i]));
            }


//        cout << "T : "<<t <<endl;
//        cout << "customer"<<endl;
//        for(auto elem : cus){
//            cout <<"No: "<< elem.no << " time: "<<elem.time <<endl;
//        }
//
//        for(int i=0;i<N;i++){
//            cout << aUsed[i] <<" ";
//        }
//        cout <<endl;
//        cout << "repair"<<endl;
//        for(auto elem : rep){
//            cout <<"No: "<< elem.no << " time: "<<elem.time <<endl;
//        }
//
//        for(int i=0;i<M;i++){
//            cout << bUsed[i] <<" ";
//        }
//        cout <<endl;


        t++;
        if(cus.empty() && rep.empty() && q.empty() && pq.empty()) break;
    }

}

int count(){
    int sm=0;
    for(int i=1;i<=K;i++){
        if(ans[i].first == A && ans[i].second == B){
            sm += i;
        }
    }
    if(sm == 0) sm = -1;
    return sm;
}
void reset(){
    memset(ans,0,sizeof(ans));
}

int main() {
    fastIO();
    cin >> T;
    for(int t= 1; t<=T ; t++){
        cin >> N >> M >> K >> A >> B;
        For(i,0,N){
            cin >> an[i];
        }
        For(i,0,M){
            cin >> bn[i];
        }
        For(i,0,K){
            cin >> tim[i];
            q.push(Customer(i+1,tim[i]));
        }

        solve();

//        for(int i=1;i<=K;i++){
//            cout << ans[i].first <<", "<<ans[i].second <<endl;
//        }
        cout <<"#"<<t<<" "<<count()<<endl;
        reset();
    }

    return 0;

}