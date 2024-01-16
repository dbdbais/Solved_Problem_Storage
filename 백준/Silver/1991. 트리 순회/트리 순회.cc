//
// Created by newbi on 2024-01-16.
//
#include <iostream>
using namespace std;

int N;

char tree[27][2];    // 평행이동 배열 [2] 는 자식 노드들

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void preorder(int idx){     //전위 순회
    cout << (char)(idx +'A');

    if(tree[idx][0]){
        preorder(tree[idx][0]-'A');
    }

    if(tree[idx][1]){
        preorder(tree[idx][1]-'A');
    }

    return;
}

void postorder(int idx){    //후위순회

    if(tree[idx][0]){
        postorder(tree[idx][0]-'A');
    }

    if(tree[idx][1]){
        postorder(tree[idx][1]-'A');
    }
    cout << (char)(idx +'A');
    return;
}

void inorder(int idx){  //중위 순회
    if(tree[idx][0]){
        inorder(tree[idx][0]-'A');
    }
    cout << (char)(idx +'A');
    if(tree[idx][1]){
        inorder(tree[idx][1]-'A');
    }

    return;
}

int main(){
    char _root,_left,_right;
    fastIO();
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> _root >> _left >> _right;
        if(_left !='.'){
            tree[_root-'A'][0] = _left;
        }
        if(_right != '.'){
            tree[_root-'A'][1] = _right;
        }

    }

    preorder(0);
    cout<<'\n';
    inorder(0);
    cout<<'\n';
    postorder(0);
    return 0;
}