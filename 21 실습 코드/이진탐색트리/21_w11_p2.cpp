//
//  21_w11_p2.cpp
//  week11BinarySearchTree
//
//  Created by 임주민 on 2023/05/06.
//

/*
 이진 탐색 트리 구현 후,
 특정 노드의 서브 트리의 노드 개수 출력
 insert x, delete x, sub x
 */

#include <iostream>
using namespace std;

int countSubTree;

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
private:
    Node *root = nullptr;
public:
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
                succPar->left = succ->right;
            } else {
                succPar->right = succ->right;
            }

            node->data = succ->data;
            node = succ;
        }
        delete node;
    }

    /*
     서브트리의 수(전역변수로 선언한 countSubTree)를 계산하기 위한 재귀함수
     */
    void countSubTreeNodes(Node *node) {
        if (node == nullptr) return;

        countSubTreeNodes(node->left);
        countSubTree++;
        countSubTreeNodes(node->right);
    }
};

int main() {
    int numOfCmd;
    cin >> numOfCmd;

    BST *bst = new BST();

    while(numOfCmd--) {
        string cmd;
        int x;

        cin >> cmd;

        if (cmd=="insert") {
            cin >> x;
            bst->insert(x);
        } else if (cmd=="delete") {
            cin >> x;
            bst->remove(x);
        } else if (cmd=="sub") {
            cin >> x;
            countSubTree = 0;
            bst->countSubTreeNodes(bst->search(x));
            cout << countSubTree << "\n";
        }
    }
}

