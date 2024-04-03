//
// Created by newbi on 2024-04-03.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl '\n'
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N;
int input[1000001];
int input_idx [1000001];
vector<int> vec;

void print(){

    For(i,0,N){
        cout << input[i] <<" ";
    }
    cout << endl;

    For(i,0,N){
        cout << input_idx[i] <<" ";
    }
    cout << endl;

}

void backTrace(){
    stack<int> stk;
    int nxt = vec.size()-1;
    for(int i =N-1; i>=0; i--){
        if(nxt < 0) break;
        if(input_idx[i] == nxt){
            stk.push(i);
            nxt--;
        }

    }
    while(stk.size()){
        cout << input[stk.top()] <<" ";
        stk.pop();
    }

}


void solve() {

    For(i, 0, N) {
        cin >> input[i];

        if (vec.empty() || vec.back() < input[i]) {	//벡터가 비어있거나 뒤에 보다 큰 경우
            //cout << "크거나 비어있다" << endl;
            vec.push_back(input[i]);	//집어넣는다.
            input_idx[i] =vec.size()-1;
        }
        else {
            //cout << "작다" << endl;
            int lb = lower_bound(vec.begin(), vec.end(), input[i]) - vec.begin();
            //cout << lb << endl;
            vec[lb] = input[i];
            input_idx[i] = lb;
        }
        //print();
    }


}

int main() {
    fastIO();
    cin >> N;

    solve();
    cout << vec.size() << endl;
    backTrace();
    return 0;
}