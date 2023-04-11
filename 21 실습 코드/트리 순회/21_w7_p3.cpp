//
//  21_w7_p3.cpp
//  week7Tree2
//
//  Created by 임주민 on 2023/04/08.
//

/*
 트리를 후위 순회하며 방문 된 노드의 부모 노드가 가지는 값을 출력하는 프로그램
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 1. 노드 클래스 구현
 */
class Node {
public:
    Node *parent; // 부모 노드의 포인터
    vector<Node *> childList; // 자식 노드들의 포인터를 담고 있는 벡터
    int value; // 값을 담을 변수

    Node(Node* p, int v) { // 부모 노드 p의 자식으로 v값을 가진 노드를 생성하는 생성자
        parent = p; // 부모 할당
        value = v; // 값 할당
    }
};

/*
 2. 트리 클래스 구현
 */
class Tree {
public:
    Node *root; // 루트 노드의 포인터
    vector<Node *> nodeList; // 트리의 노드들의 위치를 담고 있는 벡터

    Tree() { // 생성자
        root = new Node(nullptr, 1); // 부모 없고 1값을 가지는 root 노드 생성(문제에 제시됨)
        nodeList.push_back(root); // 트리에 루트 노드 넣어주기
    }

    Node *findNode(int v) { // 인자값에 해당하는 노드의 포인터 반환
        for (int i=0; i<nodeList.size(); i++) { // 트리의 노드 리스트 순회하면서
            if (nodeList[i]->value == v) { // 인자값을 가진 노드 찾으면
                return nodeList[i]; // 포인터값 반환
            }
        }
        return nullptr; // 없으면 nullptr 반환
    }

    /*
     삽입 함수
     1. y값을 가진 노드를 x값을 가진 노드의 자식으로 삽입한다
     2. y는 중복으로 들어오는 경우가 없다. (트리에 같은 값을 가진 노드가 존재할 경우는 없다.)
     */
    void insertNode(int x, int y) { // 삽입 연산(트리에 노드 추가)
        Node *parentNode = findNode(x);  // 부모가 될 노드의 포인터
        Node *newNode = new Node(parentNode, y); // y값을 가지는 노드 생성
        parentNode->childList.push_back(newNode); // 부모노드의 '자식 리스트'에 새 노드 추가
        nodeList.push_back(newNode); // '트리'에 새 노드 추가
    }

    /*
     후위 순회하며 방문 된 노드의 '부모 노드'가 가지는 값을 출력
     선 재귀 후 출력
     */
    void postOrderTraversal(Node* node) {
        for(Node* child : node->childList) {
            postOrderTraversal(child);
        }

        if (node == root) { // 루트 노드의 경우 부모 노드가 없으므로 0 출력
            cout << "0 ";
        } else { // 부모 노드의 값 출력
            cout << node->parent->value << " ";
        }
    }
};

/*
 메인 함수
 후위 순회하며 각 부모 노드가 가지는 값을 공백으로 구분하여 출력한다.
 각 트리에는 노드를 삽입하기 전부터 이미 루트 노드 1이 존재한다고 가정한다.
 각 트리에는 입력되는 노드 값이 중복되는 경우가 없다.
 */
int main() {
    /*
     <입력>
     첫째 줄에는 테스트 케이스의 개수 T(1≤T≤100)가 주어진다. 그 후 T회에 걸쳐 다음과 같이 반복되어 주어진다.
       - 하나의 트리에 삽입될 노드의 수 N(1≤N≤1000)이 주어진다.
       - N개의 줄에 걸쳐 부모 노드의 값, 자식 노드의 값이 주어진다.
     */
    int T, N, par, chd;
    cin >> T;
    while(T--) {
        Tree* tree = new Tree();

        cin >> N;
        while(N--) {
            cin >> par >> chd;
            tree->insertNode(par, chd);
        }

        tree->postOrderTraversal(tree->root);
        cout << "\n";
    }
}
