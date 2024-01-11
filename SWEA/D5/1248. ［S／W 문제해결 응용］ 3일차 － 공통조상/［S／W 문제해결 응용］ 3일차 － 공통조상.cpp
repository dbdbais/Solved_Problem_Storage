#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
int T, V ,E ,V1, V2 ,A ,B;
int parentV1[10004], parentV2[10004];
int index1 = 0, index2 = 0, cnt = 0;
 
struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
};
 
Node nodes[10004];
 
Node* newNode(int x) {
    nodes[x].key = x;
    nodes[x].left = nullptr;
    nodes[x].right = nullptr;
    nodes[x].parent = nullptr;
    return &nodes[x];
}
 
 
 
void reset() {
    memset(parentV1, 0, sizeof(parentV1));
    memset(parentV2, 0, sizeof(parentV2));
    memset(nodes, 0, sizeof(nodes));
    index1 = 0;
    index2 = 0;
    cnt = 0;
}
 
void parentSearch1(Node* node) {
    if (node->key == NULL || node->key == 1) return;
    parentV1[index1++] = node->parent->key;
    if (node->parent != nullptr) parentSearch1(node->parent);
}
 
void parentSearch2(Node* node) {
    if (node->key == NULL || node->key == 1) return;
    parentV2[index2++] = node->parent->key;
    if (node->parent != nullptr) parentSearch2(node->parent);
}
 
int equalElementSearch() {
    for (int i = 0; i < index1; i++) {
        for (int j = 0; j < index2; j++) {
            if (parentV1[i] == parentV2[j]) return parentV1[i];
        }
    }
    return 0;
}
 
void countSubTree(Node* node) {
    cnt += 1;
    if (node->left != nullptr) countSubTree(node->left);
    if (node->right != nullptr) countSubTree(node->right);
}
 
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
int main() {
 
    fastIO();
 
    cin >> T;
 
    for (int idx = 1; idx <= T; idx++){
 
        reset();
 
        cin >> V >> E >> V1 >> V2;
        for (int i = 0; i < E; i++) {
            cin >> A >> B;
            if (nodes[A].key == NULL) newNode(A); // A 노드 저장
            if (nodes[B].key == NULL) newNode(B); // B 노드 저장
 
            if (nodes[A].left == nullptr) nodes[A].left = &nodes[B]; // 왼쪽 연결
            else if (nodes[A].right == nullptr) nodes[A].right = &nodes[B]; // 오른쪽 연결
            nodes[B].parent = &nodes[A]; // 부모 연결
        }
 
 
        parentSearch1(&nodes[V1]); // 첫번째 노드 부모 저장
        parentSearch2(&nodes[V2]); // 두번째 노드 부모 저장
 
        int LCA = equalElementSearch(); // 가장 가까운 공통 조상 찾기
        countSubTree(&nodes[LCA]); // 공통 조상을 기준으로 한 SubTree 개수 세기
        cout << '#' << idx << ' ' << LCA << ' ' << cnt << "\n";
 
    }
}