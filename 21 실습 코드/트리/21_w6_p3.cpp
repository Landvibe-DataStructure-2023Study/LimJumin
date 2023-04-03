//
//  21_w6_p3.cpp
//  Week6TreeLandVibe
//
//  Created by 임주민 on 2023/04/01.
//

/*
 특정 노드의 부모 노드를 출력하는 프로그램
 (insert, delete, print)
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
     삽입 연산 (insert x y)
     1. y값을 가진 노드를 x값을 가진 노드의 자식으로 삽입한다
     2. x값을 가진 노드가 없으면 -1 출력하고 무시한다.
     3. y는 중복으로 들어오는 경우가 없다. (트리에 같은 값을 가진 노드가 존재할 경우는 없다.)
     */
    void insertNode(int x, int y) { // 삽입 연산(트리에 노드 추가)
        Node *parentNode = findNode(x);  // 부모가 될 노드의 포인터

        if (parentNode == nullptr) { // x값을 가진 노드가 없을 경우(이상한 경우)
            cout << "-1\n"; // 문제조건따라 에러 처리
        } else { // 올바르게 추가하는 경우
            Node *newNode = new Node(parentNode, y); // y값을 가지는 노드 생성
            parentNode->childList.push_back(newNode); // 부모노드의 '자식 리스트'에 새 노드 추가
            nodeList.push_back(newNode); // '트리'에 새 노드 추가
        }
    }

    /*
     삭제 연산 (delete x)
     1. x값을 가진 노드를 삭제하고 x 노드의 자식 노드는 x 노드의 부모의 자식 노드가 된다.
     2. x값을 가진 노드가 없을 경우또는 루트 노드를 삭제하려고 하는 경우 -1을 출력하고 무시한다.
     */
    void deleteNode(int x) {
        Node *deleteNode = findNode(x);

        if (deleteNode == root || deleteNode == nullptr) {
            cout << "-1\n";
        } else {
            // 삭제할 해당 노드의 자식들을 부모 노드의 자식으로 변경해주기
            for (int i=0; i<deleteNode->childList.size(); i++) { // 자식 수만큼 반복
                deleteNode->parent->childList.push_back(deleteNode->childList[i]); // 자식 업데이트
                deleteNode->childList[i]->parent = deleteNode->parent; // 부모 업데이트
            }

            // 부모 노드의 자식 리스트에서 해당 노드 삭제
            for (int i=0; i<deleteNode->parent->childList.size(); i++) {
                if (deleteNode == deleteNode->parent->childList[i]) {
                    deleteNode->parent->childList.erase(deleteNode->parent->childList.begin() + i);
                    break; // 삭제하고 더이상 반복문 수행할 필요 없으면 break
                }
            }

            // 트리의 노드 리스트에서 해당 노드 삭제
            for (int i=0; i<nodeList.size(); i++) {
                if(deleteNode == nodeList[i]) {
                    nodeList.erase(nodeList.begin() + i);
                    break; // 삭제하고 더이상 반복문 수행할 필요 없으면 break
                }
            }

            delete deleteNode; // delete 해주기
        }
    }

    /*
     출력 연산 (print x)
     1. x 노드의 부모 노드를 출력한다.
     2. x가 루트 노드이거나 해당 노드가 없으면 -1 출력한다.
     */
    void printNode(int x) {
        Node *curNode = findNode(x); // 순회용 노드를 인자값에 해당하는 노드로 초기화

        if (curNode == nullptr || curNode == root) {
            cout << "-1\n";
        } else {
            cout << curNode->parent->value <<"\n";
        }
    }
};


/*
 3. 메인 함수 구현
 첫째 줄에는 함수 입력 개수 N(1≤N≤10000)이 주어진다.
 둘째 줄부터 N개의 줄에 걸쳐 함수와 정수가 순서대로 주어진다.
 항상 루트 노드 1이 존재한다고 가정한다.
 */
int main() {
    int numOfCommand;
    cin >> numOfCommand;

    Tree tree = Tree(); // 또는 Tree* tree = new Tree();

    while(numOfCommand--) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            int x, y;
            cin >> x >> y;
            tree.insertNode(x, y);
        } else if (cmd == "delete") {
            int x;
            cin >> x;
            tree.deleteNode(x);
        } else if (cmd == "print") {
            int x;
            cin >> x;
            tree.printNode(x);
        }
    }
}
