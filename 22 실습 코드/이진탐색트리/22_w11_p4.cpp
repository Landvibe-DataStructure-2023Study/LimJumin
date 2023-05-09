//
//  22_w11_p4.cpp
//  week11BinarySearchTree
//
//  Created by 임주민 on 2023/05/09.
//

/*
 이진 탐색 트리 구현 후,
 주어진 명령어를 수행하는 프로그램 구현
 insert x, delete x, max x, height x
 */

#include <iostream>
using namespace std;

int c, k;

class Node {
private:
    int data;
    Node *par;
    Node *left;
    Node *right;

public:
    Node(int d) {
        data = d;
        par = left = right = nullptr;
    }
    friend class BST;
};

class BST {
public:
    Node *root = nullptr;

    /*
     인자값을 가진 노드를 찾는 탐색 함수
     */
    Node *search(int data) {
        Node *curNode = root;
        while(curNode != nullptr) {
            if(data == curNode->data) {
                return curNode;
            } else if (data < curNode->data) {
                curNode = curNode->left;
            } else if (data > curNode->data) {
                curNode = curNode->right;
            }
        }
        return nullptr;
    }
    
    /*
     depth를 구해주는 함수
     */
    void depth(Node* node) {
        Node *curNode = node;
        int depth = 0;
        
        while(curNode != root) {
            curNode = curNode->par;
            depth++;
        }
        cout << depth << "\n";
    }

    /*
     인자값을 가진 노드를 BST에 추가하는 함수
     */
    void insert(int data) {
        // 1. 새로운 노드 생성
        Node *newNode = new Node(data);

        // 2. 삽입할 위치 탐색
        if(root == nullptr) { // 트리가 비어있던 경우, 루트로 설정해주고 리턴
            root = newNode;
            return;
        }

        Node *curNode = root; // 루트부터 탐색 시작
        Node *parNode = root->par;

        while(curNode != nullptr) {
            if (data < curNode->data) { // 왼쪽 서브트리로 이동
                parNode = curNode;
                curNode = curNode->left;
            } else { // 오른쪽 서브트리로 이동
                parNode = curNode;
                curNode = curNode->right;
            }
        }

        // 3. 위치(curNode)에 노드 삽입; 부모와 자식 서로 연결해주기
        newNode->par = parNode;
        if (data < parNode->data) {
            parNode->left = newNode;
        } else {
            parNode->right = newNode;
        }
    }

    /*
     인자값을 가진 노드를 BST에서 찾아서 삭제하는 함수
     */
    void remove(int data) {
        // 1. 삭제할 노드의 위치를 찾기
        Node *node = search(data);
        Node *parNode = node->par;

        // 2-1. 자식 0개인 경우; 그냥 삭제
        if(node->left == nullptr && node->right == nullptr) {
            if (node == root) { // 루트 삭제하는 경우 루트 nullptr로 설정
                this->root = nullptr;
            } else {
                if (node == parNode->left) {
                    parNode->left = nullptr;
                } else {
                    parNode->right = nullptr;
                }
            }
        // 2-2. 자식 1개인 경우; 삭제할 노드의 자식 노드를 삭제할 노드의 위치로 이동
        } else if (node->left == nullptr || node->right == nullptr) {
            Node *child = (node->left != nullptr) ? node->left : node->right;

            if (node == root) { // 루트 삭제하는 경우 루트를 자식으로 새로 설정
                this->root = child;
            } else {
                if (node == parNode->left) {
                    parNode->left = child;
                    child->par = parNode;
                } else {
                    parNode->right = child;
                    child->par = parNode;
                }
            }
        // 2-3. 자식 2개인 경우; 오른쪽 서브트리에서 min값 노드를 삭제할 노드의 위치로 이동
        } else if (node->left != nullptr && node->right != nullptr) {
            Node *succ = node->right;
            Node *succPar = node;

            while (succ->left != nullptr) { // 오른쪽 서브트리에서 min값 = 가장 왼쪽 하단에 있는 노드
                succPar = succ; // 왼쪽 서브트리로 계속 이동
                succ = succ->left;
            }

            if (succ == succPar->left) {
                succPar->left = nullptr;
            } else {
                succPar->right = nullptr;
            }

            node->data = succ->data;
            node = succ;
        }
        delete node;
    }
    
    /*
     k번째로 큰 정수를 출력
     */
    void max(Node* node){
        if (node == nullptr) return;
        
        max(node->right);
        c++;
        if(c == k) {
            cout << node->data << "\n";
            return;
        }
        max(node->left);
    }
    
    /*
     인자값을 루트로 하는 서브트리의 높이(리프의 깊이 중 최대값)를 출력
     */
    int height(Node* node) {
        if (node == nullptr)
            return -1;
        
        if (height(node->left) < height(node->right))
            return height(node->right)+1;
        else
            return height(node->left)+1;
    }
    
};

int main() {
    int numOfCmd;
    cin >> numOfCmd;
    
    BST *bst = new BST();
    
    while(numOfCmd--) {
        string cmd;
        int x;
        
        cin >> cmd >> x;
        
        if (cmd=="insert") {
            bst->insert(x);
            bst->depth(bst->search(x));
        } else if (cmd=="delete") {
            bst->depth(bst->search(x));
            bst->remove(x);
        } else if (cmd=="max") {
            k = x;
            c = 0;
            bst->max(bst->root);
        } else if (cmd=="height") {
            cout << bst->height(bst->search(x)) << "\n";
        }
    }
}

