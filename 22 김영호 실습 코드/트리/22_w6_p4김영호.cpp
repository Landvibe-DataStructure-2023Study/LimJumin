//
//  22_w6_p4김영호.cpp
//  Week6TreeLandVibe
//
//  Created by 임주민 on 2023/04/01.
//

/*
 해당 노드의 깊이(depth)를 출력하는 프로그램
 (21년도 6주차 2번 문제, 22년도 6주차 2-1문제와 동일)
 */

#include <iostream>
#include <vector> // STL vector 사용

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
        root = new Node(nullptr, 1); // 부모 없고 1값을 가지는 root 노드 생성(문제에서 항상 루트 노드 1이 존재한다고 가정하라고 나와있기 때문에)
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
     삽입 연산
     */
    void insertNode(int x, int y) { // 삽입 연산(트리에 노드 추가)
        Node *parentNode = findNode(x);  // 부모가 될 노드의 포인터

        if (parentNode == nullptr) { // x값을 가진 노드가 없을 경우
            cout << "-1\n";
        } else { // 올바르게 추가하는 경우
            Node *newNode = new Node(parentNode, y); // y값을 가지는 노드 생성
            parentNode->childList.push_back(newNode); // 부모노드의 '자식 리스트'에 새 노드 추가
            nodeList.push_back(newNode); // '트리'에 새 노드 추가
        }
    }

    /*
     depth 출력 연산
     */
    void printDepth(int x) {
        Node *curNode = findNode(x);

        if (curNode == nullptr) { // 트리에 없는 노드일 경우 에러처리
            cout << "-1\n";
        } else {
            int depth = 0;
            while(curNode != root) {
                curNode = curNode->parent;
                depth++;
            }
            cout << depth << "\n";
        }
    }
};


/*
 3. 메인 함수 구현
 첫째 줄에는 트리의 노드 개수 N(1≤N≤1000)과 특정 노드의 depth를 묻는 질문 수 M(1≤M≤N)이 주어짐
 둘째 줄부터 'N-1'개의 줄에 걸쳐 부모 노드와 삽입될 자식 노드가 순서대로 주어진다.
 이후 'M'개의 줄에 걸쳐 depth를 출력할 노드의 data가 주어진다.
 */
int main() {
    int numOfInputNode, numOfQuestion;
    cin >> numOfInputNode >> numOfQuestion;

    Tree tree = Tree(); // 또는 Tree* tree = new Tree();

    for(int i=0; i<numOfInputNode-1; i++) {
        int parent, child;
        cin >> parent >> child;
        tree.insertNode(parent, child);
    }

    while(numOfQuestion--) {
        int node;
        cin >> node;
        tree.printDepth(node);
    }
}
