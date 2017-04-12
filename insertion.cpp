//
// Created by 오민호 on 2017. 4. 5..
//

#include <cstdlib>
#include <utility>

template <typename T>
//트립의 한 노드
struct Node {
    //노드의 저장한 원소
    T key;
    //노드의 우선순위, 이 노드를 루트로 하는 서브트리의 크기
    int priority, size;
    //두 자식 노드의 포인터
    Node *left, *right;
    Node(const T& key ): key(key), priority(rand()),size(1),
                         left(nullptr), right(nullptr) {}
    void setLeft(Node* newLeft) {
        left = newLeft;
        calcSize();
    }

    void setRight(Node* newRight) {
        right = newRight;
        calcSize();
    }

    void calcSize() {
        if(left) size += left->size;
        if(right) size += right->size;
    }
};

using std::pair;

typedef pair<Node*, Node*> NodePair;

//root를 루트로 갖는 트립을 key미만의 값과 이상의 값을 갖는
//두 개의 트립으로 분리 한다.
template <typename T>
NodePair split(Node* root, T key) {
    if(root == nullptr) return NodePair(nullptr, nullptr);
    if(root->key < key) {
        NodePair splitted = split(root->right, key);
        root->setRight(splitted.first);
        return NodePair(root, splitted.second);
    }

    NodePair splitted = split(root->left, key);
    root->setLeft(splitted.second);
    return NodePair(splitted.first, root);
}

//root를 루트로 갖는 트립에 node 를 삽입
Node* insert(Node* root, Node* node) {
    if(root == nullptr) return node;
    if(root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    } else if(root->key < node->key)
        root->setRight(insert(root->right, node));
    else
        root->setLeft(insert(root->left, node));
    return root;
}

//두개의 트립 a, b가 있을때 max(a) < min(b) 일 때 이 둘을 합치는 함수
Node* merge(Node* a, Node* b) {
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    if(a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
}

//root를 루트로 갖는 트립에 key의 원소값을 가진 node를 삭제한 트립의 루트값 반환
template <typename T>
Node* erase(Node* root, T key) {
    if(root == nullptr) return nullptr;
    if(root->key == key) {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if(root->key < key) root->setRight(erase(root->right, key));
    else root->setLeft(erase(root->left, key));
    return root;
}