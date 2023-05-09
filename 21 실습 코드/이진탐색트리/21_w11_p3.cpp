//
//  21_w11_p1.cpp
//  week11BinarySearchTree
//
//  Created by 임주민 on 2023/05/06.
//

/*
 이진 탐색 트리 구현 후,
 오름차순으로 노드 값들을 출력
 */

#include <iostream>
using namespace std;

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
     오름차순으로 출력
     */
    void print(Node *node) {
        if (node == nullptr) return;

        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }
};

int main() {
    int numOfTest, numOfNode, x, m;
    cin >> numOfTest;

    BST *bst = new BST();

    while(numOfTest--) {
        cin >> numOfNode;
        while(numOfNode--) {
            cin >> x;
            bst->insert(x);
        }
        cin >> m;
        bst->print(bst->root);
    }
}
