//
// Created by newbi on 2024-05-25.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

using namespace std;

int N;
vector<int> vec;
vector<int> sm;

bool search(int num){
    int _left = 0;
    int _right = (int) sm.size()-1;
    bool found = false;
    while(_left <= _right){
        int mid = (_left + _right) / 2;

        if(sm[mid] == num){
           found = true;
           break;
        }
        else if(sm[mid] > num){
            _right = mid -1;
        }
        else{
            _left = mid +1;
        }

    }
    return found;
}

int main(){
    fastIO();
    cin >> N;
    int tmp;
    For(i,0,N){
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    For(i,0,N){
        For(j,i,N){
            sm.push_back(vec[j]+vec[i]);
        }
    }
    sort(sm.begin(),sm.end());
    bool stop = false;
   for(int i = N-1;i>0;i--){
       for(int j= 0;j<N;j++){
           if(binary_search(sm.begin(),sm.end(),vec[i]-vec[j])){
               cout << vec[i] << endl;
               stop = true;
               break;
           }
       }
       if(stop) break;
   }



    return 0;
}