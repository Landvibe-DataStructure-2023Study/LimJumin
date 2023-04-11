//
//  22_w7_p1.cpp
//  week7Tree2
//
//  Created by 임주민 on 2023/04/09.
//

/*
 트리를 전위순회로 방문한 순서대로 각 노드의 깊이를 출력하는 프로그램
 */

#include <iostream>
#include <vector>

using namespace std;

int depth;
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
     전위 순회 함수
     전위 순회 하면서 방문된 노드의 '깊이' 출력
     전위 순회 : 선 출력 후 재귀
     */
    void preOrderTraversal(Node* node) {
        cout << depth << " "; // 선 출력
        
        for(Node* child : node->childList) {
            depth++; // 재귀 들어갈 때마다 depth 증가
            preOrderTraversal(child);
        }
        depth--; // 리턴될 때마다 depth 감소
    }
};

/*
 메인 함수
 트리를 전위순회로 방문한 순서대로 각 노드의 깊이를 공백으로 구분하여 출력한다.
 최초 빈 트리에 루트인 노드 1이 가장 먼저 삽입되어 있다.
 트리를 구성하는 노드 번호는 중복되지 않는다.
 만약 노드의 자식이 여러 개일 경우, 자식들에 대해 삽입된 순서대로 방문한다.
 */
int main() {
    /*
     <입력>
     첫째 줄에는 테스트 케이스의 개수 T(1≤T≤100)가 주어진다. 그 후 T회에 걸쳐 다음과 같이 반복되어 주어진다.
       - 트리의 노드의 수 N(2≤N≤1000)이 주어진다.
       - N-1개의 줄에 걸쳐 부모 노드의 값, 자식 노드의 값이 주어진다.
     */
    int T, N, par, chd;
    cin >> T;
    while(T--) {
        depth = 0;
        Tree* tree = new Tree();

        cin >> N;
        for(int i=0; i<N-1; i++) {
            cin >> par >> chd;
            tree->insertNode(par, chd);
        }
        
        tree->preOrderTraversal(tree->root);
        cout << "\n";
    }
}
