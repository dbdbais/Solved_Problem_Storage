//
// Created by newbi on 2024-01-16.
//
#include <iostream>
using namespace std;

int N;

struct node{
    char val;
    node * left;
    node * right;
};

node nodes[27];

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void preorder(node n){     //전위 순회
    cout << n.val;

    if(n.left != nullptr){
        preorder(*n.left);
    }
    if(n.right != nullptr){
        preorder(*n.right);
    }
    return;
}

void postorder(node n){    //후위순회

    if(n.left != nullptr){
        postorder(*n.left);
    }
    if(n.right != nullptr){
        postorder(*n.right);
    }
    cout << n.val;
    return;
}

void inorder(node n){  //중위 순회
    if(n.left != nullptr){
        inorder(*n.left);
    }
    cout << n.val;
    if(n.right != nullptr){
        inorder(*n.right);
    }

    return;
}

int main(){
    char _root,_left,_right;
    fastIO();
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> _root >> _left >> _right;
        if(!nodes[_root-'A'].val){   //노드 값이 없다면
            nodes[_root-'A'].val = _root;   //루트 대입
        }
        if(_left !='.'){
            nodes[_left-'A'].val = _left;
            nodes[_root-'A'].left = &nodes[_left-'A'];
        }
        if(_right != '.'){
            nodes[_right-'A'].val = _right;
            nodes[_root-'A'].right = &nodes[_right-'A'];
        }
    }

    preorder(nodes[0]);
    cout<<'\n';
    inorder(nodes[0]);
    cout<<'\n';
    postorder(nodes[0]);
    return 0;
}
