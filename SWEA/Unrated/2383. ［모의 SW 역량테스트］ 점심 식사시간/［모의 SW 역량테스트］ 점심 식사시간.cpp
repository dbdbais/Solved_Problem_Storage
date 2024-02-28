//
// Created by newbi on 2024-02-28.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

struct Person{
    int x,y,distance,stair;

    Person(int x,int y):x(x),y(y){

    }

    void setDistance(pair<int,int> p){
        distance = abs(x-p.first) + abs(y-p.second);
    }
    void setStair(int stair){
        this->stair = stair;
    }

    bool operator<(Person p){
        return distance < p.distance;
    }
};

vector<Person> pVec;
vector<pair<int,pair<int,int>>> stair;
int T,N;
int arr[12][12];
int ans = 1e8;

void solve(vector<Person> vec,vector<pair<int,pair<int,int>>> st){ //복사본 넘김
    sort(vec.begin(),vec.end());  //distance별로 정렬
    int cnt =1;
    int firstStairCnt = 3;
    int secondStairCnt  = 3;
    while(true){
        cnt++;
        if(ans <= cnt) break;   //유망하지 않으면 break
        int zeroCount =0;
        int oneCount = 0;
//        cout << cnt << endl;
//        for(auto el : vec){
//            cout << "Stair : "<<el.stair << "  Dist :" <<el.distance << endl;
//        }

        for(auto &elem : vec){
            if(elem.distance ==0 ){  //계단에 도달하면
                if(elem.stair ==  0){   //내려갈 공간이 있다면
                    if(firstStairCnt > 0 ){
                       firstStairCnt --;
                        elem.distance--;
                    }
                }
                else if(elem.stair == 1){
                    if(secondStairCnt > 0 ){
                        secondStairCnt--;
                        elem.distance--;
                    }
                }
            }
            else {
                elem.distance -= 1;  //하나씩 감소시킨다.
                if(elem.distance == stair[elem.stair].first * -1){
                    if(elem.stair == 0) zeroCount++;
                    else oneCount++;
                }
            }
        }
        vec.erase(remove_if(vec.begin(),vec.end(),[=](Person p){
            return p.distance == stair[p.stair].first* -1;  // -만큼 감소했다면 지운다.
        }),vec.end());

        firstStairCnt += zeroCount;   //원복
        secondStairCnt += oneCount;

        if(vec.empty()) break;
    }
    if(ans > cnt) ans = cnt;
}

void permutaion(vector<int>v){
    if(v.size() == pVec.size()){
        for(int a =0 ; a< v.size();a++){
            pVec[a].setDistance(stair[v[a]].second);
            pVec[a].setStair(v[a]);
        }
        solve(pVec,stair);
        return;
    }
    for(int i=0;i<=1;i++){
        v.push_back(i);
        permutaion(v);
        v.pop_back();
    }

}


void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void reset(){
    ans = 1e8;
    pVec.clear();
    stair.clear();
}

int main(){
    fastIO();
    cin >> T;

    for(int t =1; t<= T;t++){
        cin >> N;
        For(i,1,N+1){
            For(j,1,N+1){
                cin >> arr[i][j];
                if(arr[i][j] == 1){
                    pVec.push_back(Person(i,j));
                }
                else if(arr[i][j] != 0){
                    stair.push_back({arr[i][j],{i,j}});
                }
            }
        }
        vector<int> v;
        permutaion(v);
        cout << "#"<<t<< " "<<ans <<endl;

        reset();

    }

    return 0;
}