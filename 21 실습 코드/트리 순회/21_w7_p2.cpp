//
//  21_w7_p2.cpp
//  week7Tree2
//
//  Created by 임주민 on 2023/04/08.
//

/*
 트리를 전위 순회하며 노드의 저장된 값과 깊이를 출력한 결과가 주어질 때,
 후위 순회한 결과를 출력하는 프로그램.
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
     후위 순회 함수
     선 재귀 후 출력
     */
    void postOrderTraversal(Node* node) {
        for(Node* child : node->childList) {
            postOrderTraversal(child);
        }
        
        cout << node->value << " ";
    }
};

/*
 3. 메인 함수 구현
 각 트리에 대해 후위 순회한 결과를 출력한다.
 각 트리에는 입력 전에 이미 루트 노드 1이 존재하며 노드 값이 중복되는 경우는 없다.
 */
int main() {
    /*
     <입력>
     첫째 줄에는 테스트 케이스의 개수 T(1≤T≤100)가 주어진다. 그 후 T회에 걸쳐 각 트리의 전위순회한 결과가 아래와 같이 주어진다.
       - 트리의 '노드의 수' N(1≤N≤1000)이 주어진다.
       - 각 노드의 '저장된 값' X(1≤X≤100000)가 전위 순회 순서에 맞춰 공백으로 구분하여 주어진다.
       - 각 노드의 '깊이'가 전위 순회 순서에 맞춰 공백으로 구분하여 주어진다.
     */
    int T, N;
    cin >> T;
    while(T--) {
        Tree* tree = new Tree();
        int value[1000];
        int depth[1000];

        // 1. 입력
        cin >> N;
        for(int i=0; i<N; i++) { // 노드의 저장된 값들이 공백으로 구분되어 주어짐
            cin >> value[i];
        }
        for(int i=0; i<N; i++) { // 노드의 깊이들이 공백으로 구분되어 주어짐
            cin >> depth[i];
        }
        
        // 2. 트리 생성
        for(int i=0; i<N-1; i++) {
            if(depth[i+1] > depth[i]) { // depth가 이전보다 증가하면 (Ex. 2->3, depth 2이상 차이나는 경우는 일어날 수 없다.)
                tree->insertNode(value[i], value[i+1]); // 현재 노드의 자식으로 추가
            } else if(depth[i+1] < depth[i]) { // depth가 이전보다 감소하면 (Ex. 3->2, 3->1, depth가 2이상 차이날 수 있다. -> 반복문 사용)
                Node* cur = tree->findNode(value[i]); // 현재 노드의 포인터값 얻기
                // 이전 노드의 조상 중 현재 노드와 같은 depth를 가진 조상을 찾은 뒤(계속 부모로 올라가기) 형제로 연결
                int count = depth[i] - depth[i+1];
                while(count != 0) {
                    cur = cur->parent;
                    count--;
                }
                Node* par = cur->parent; // 현재 노드의 부모 노드의 부모노드의 포인터값 얻기
                tree->insertNode(par->value, value[i+1]); // 현재 노드의 부모 노드의 부모노드의 자식으로 추가
            } else { // 동일할 때
                Node* cur = tree->findNode(value[i]); // 현재 노드의 포인터값 얻기
                Node* par = cur->parent; // 현재 노드의 부모 노드의 포인터값 얻기
                tree->insertNode(par->value, value[i+1]); // 현재 노드의 부모 노드의 자식으로 추가
            }
        }

        // 3. 후위 순회
        tree->postOrderTraversal(tree->root);
        cout << "\n";
    }
}
