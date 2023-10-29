//
// Created by newbi on 2023-08-15.
//
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void floyd( vector<vector<int>> &matrix, int n){
    int k,j,i;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int> res(n+1,0);
    vector<vector<int>> matrix(n+1,vector<int>(n+1,999));

    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }

    floyd(matrix,n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            res[i] += matrix[i][j];
        }
    }
    auto mn = min_element(res.begin()+1,res.begin()+res.size());

    for(int i=1;i<=n;i++){
        if(res[i]==*mn){
            cout << i;
            break;
        }
    }

/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << matrix[i][j]<<" ";
        }
        cout<<endl;
    }*/


    return 0;
}