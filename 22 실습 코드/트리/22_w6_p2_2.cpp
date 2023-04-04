//
//  22_w6_p2_2.cpp
//  Week6TreeLandVibe
//
//  Created by 임주민 on 2023/04/01.
//

/*
 특정 depth에 속하는 노드 중 가장 큰 노드를 출력하는 프로그램 (*약간 어렵)
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
        root = new Node(nullptr, 1); // 부모 없고 1값을 가지는 root 노드 생성(문제에서 항상 루트 노드 1이 존재한다고 나와있기 때문에)
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
     1. y값을 가진 노드를 x값을 가진 노드의 자식으로 삽입한다
     2. x값을 가진 노드가 없으면 -1 출력하고 무시한다.
     3. y가 중복으로 들어오는 경우는 테스트 케이스에 없다.
     */
    void insertNode(int x, int y) { // 삽입 연산(트리에 노드 추가)
        Node *parentNode = findNode(x);  // 부모가 될 노드의 포인터
        
        if (parentNode == nullptr) { // x값을 가진 노드가 없을 경우(이상한 경우)
            cout << "-1\n"; // 에러 처리(이 문제에서는 굳이 안해줘도 됨)
        } else { // 올바르게 추가하는 경우
            Node *newNode = new Node(parentNode, y); // y값을 가지는 노드 생성
            parentNode->childList.push_back(newNode); // 부모노드의 '자식 리스트'에 새 노드 추가
            nodeList.push_back(newNode); // '트리'에 새 노드 추가
        }
    }
    
    /*
     특정 depth 내 가장 큰 노드 값 출력 연산
     : 재귀 사용, 루트부터 시작해서 자식 노드로 내려가면서 해당하는 depth에 있는 노드들만 최대값 검
     */
    void printLargestAtDepth(Node* node, int depth, int& maxNodeValue) {
        if (depth == -1) {
            return;
        }
        if (depth == 0) { // 해당하는 depth에 있는 노드들만 이부분이 실행됨
            if (node->value > maxNodeValue) { // 최대값변수(maxNodeValue) 업데이트
                maxNodeValue = node->value;
            }
        }
        for (Node* child : root->childList) { // 자식 노드로 내려가면서 모든 자식 다 재귀함수 호출
            printLargestAtDepth(child, depth-1, maxNodeValue); // 자식노드, depth-1한 함수 호출
        }
    }
};


/*
 3. 메인 함수 구현
 첫째 줄에는 트리의 노드 삽입문 개수 N(1≤N≤10000)과 질문 수 M(0≤M≤N)이 주어짐
 둘째 줄부터 N개의 줄에 걸쳐 부모 노드와 삽입될 자식 노드가 순서대로 주어져 루트 노드를 포함해 총 N+1개의 노드가 생성된다.
 이후 M개의 줄에 걸쳐 depth가 주어진다.
 */
int main() {
    int numOfInputNode, numOfQuestion;
    cin >> numOfInputNode >> numOfQuestion;
    
    Tree tree = Tree(); // 또는 Tree* tree = new Tree();

    while(numOfInputNode--) {
        int parent, child;
        cin >> parent >> child;
        tree.insertNode(parent, child);
    }
    
    while(numOfQuestion--) {
        int depth;
        cin >> depth;
        int maxNodeValue = 0; // depth가 k인 노드가 없으면 그대로 0 출력하게 된다. (문제 조건)
        tree.printLargestAtDepth(tree.root, depth, maxNodeValue);
        cout << maxNodeValue << "\n";
    }
}
