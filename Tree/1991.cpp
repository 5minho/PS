//
// Created by 오민호 on 2017. 4. 20..
//

#include <iostream>
#include <vector>

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char d): data(d) {
        left = nullptr;
        right = nullptr;
    }

    void setLeft(Node* l) {
        left = l;
    }

    void setRight(Node* r) {
        right = r;
    }
};

void distroyTree(Node* node) {
    if(node != nullptr) return;
    distroyTree(node->left);
    distroyTree(node->right);
    delete node;
}

void preorder(Node* node) {
    if(node == nullptr) return;
    std::cout << node->data;
    preorder(node->left);
    preorder(node->right);
}
void inorder(Node* node) {
    if(node == nullptr) return;
    inorder(node->left);
    std::cout << node->data;
    inorder(node->right);
}
void postorder(Node* node) {
    if(node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data;
}

int main() {
    int N = 0;
    std::cin >> N; getchar();
    Node * root = new Node('A');
    std::vector<Node*> nodeList;
    nodeList.push_back(root);

    for(int i = 0 ; i < N ; ++i) {
        char node, left, right;
        scanf("%c %c %c",&node, &left, &right); getchar();
        Node* nodeNode = new Node(node);
        Node* leftNode = (left != '.') ? new Node(left) : nullptr;
        Node* rightNode = (right != '.') ? new Node(right) : nullptr;

        for(int j = 0 ; j < nodeList.size(); ++j) {
            if(nodeList[j]->data == node) {
                nodeList[j]->setLeft(leftNode);
                nodeList[j]->setRight(rightNode);

                if(leftNode != nullptr) nodeList.push_back(leftNode);
                if(rightNode!= nullptr) nodeList.push_back(rightNode);
                nodeNode = nullptr;
                break;
            }
        }

        if(nodeNode != nullptr) {
            nodeNode->setLeft(leftNode);
            nodeNode->setRight(rightNode);
        }
    }

    preorder(nodeList[0]); std::cout << std::endl;
    inorder(nodeList[0]); std::cout << std::endl;
    postorder(nodeList[0]);

    for(int i = 0 ; i < nodeList.size() ; ++i) {
        if(nodeList[i] != nullptr)
            distroyTree(nodeList[i]);
    }
}