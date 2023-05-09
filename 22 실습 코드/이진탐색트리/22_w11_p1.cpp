//
//  22_w11_p1.cpp
//  week11BinarySearchTree
//
//  Created by 임주민 on 2023/05/09.
//

/*
 이진 탐색 트리 구현 후,
 특정 노드의 '왼쪽' 서브 트리의 크기 출력
 */

#include <iostream>
using namespace std;

int countSubTree;

class Node {
public:
    int data;
    Node *par;
    Node *left;
    Node *right;
    
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
    int numOfNode, data, numOfM, m;
    cin >> numOfNode >> numOfM;
    
    BST *bst = new BST();
    
    while(numOfNode--) {
        cin >> data;
        bst->insert(data);
    }
    while(numOfM--) {
        cin >> m;
        countSubTree = 0;
        // 주어진 노드의 왼쪽 노드의 서브트리 개수 구하기
        bst->countSubTreeNodes(bst->search(m)->left);
        cout << countSubTree << "\n";
    }
}
