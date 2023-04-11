//
//  22_w7_p2.cpp
//  week7Tree2
//
//  Created by 임주민 on 2023/04/09.
//

/*
 특정 폴더에 속한 파일의 개수(자신의 하부에 존재하는 모든 파일(리프노드)의 개수)를 계산하는 프로그램 작성
 */

#include <iostream>
#include <vector>

using namespace std;

int numOfFiles;

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
     용량 계산 함수
     용량 : 자신의 하부에 존재하는 모든 파일(리프노드)의 개수
     */
    void countFiles(Node* node) {
        if(node->childList.empty()) {
            numOfFiles++;
        }

        for(Node* child : node->childList) { // 자식 노드들을 전위 순회 (재귀)
            countFiles(child);
        }
    }
};

/*
 메인 함수
 최초 빈 트리에 루트인 폴더 1이 항상 가장 먼저 삽입되어 있다.
 모든 폴더와 파일 번호는 중복되지 않는다.
 */
int main() {
    /*
     <입력>
     첫째 줄에는 전체 폴더와 파일의 개수 N(2≤N≤1000)과 파일의 개수를 계산할 폴더의 수 M(1≤M≤1000)이 공백으로 구분되어 주어진다.
       - N-1개의 줄에 걸쳐 부모 노드의 값, 자식 노드의 값이 주어진다.
       - M개의 줄에 걸쳐 용량을 계산할 폴더의 번호 x(트리에 반드시 존재)가 주어진다.
     */
    int N, M, par, chd, x;
    Tree* tree = new Tree();

    cin >> N >> M;
    for(int i=0; i<N-1; i++) {
        cin >> par >> chd;
        tree->insertNode(par, chd);
    }

    for(int i=0; i<M; i++) {
        numOfFiles = 0;
        cin >> x;
        Node* node = tree->findNode(x);
        tree->countFiles(node);
        cout << numOfFiles << "\n";
    }
}
