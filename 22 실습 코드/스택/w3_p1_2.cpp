////
////  w3_p1_2.cpp
////  2023StudyLandVibe
////
////  Created by 임주민 on 2023/02/14.
////  스택 구현 - 연결 리스트 사용
//
//#include <iostream>
//using namespace std;
//
//int n;
//
//class Node {
//private:
//    int value;
//    Node *next;
//    
//public:
//    Node() {
//        value = 0;
//        next = nullptr;
//    }
//    friend class LinkedList;
//    friend class Stack; // top()함수에서 value 접근
//};
//
//class LinkedList {
//private:
//    Node *head;
//    Node *tail;
//    int size;
//    
//public:
//    LinkedList() {
//        head = nullptr;
//        tail = nullptr;
//        size = 0;
//    }
//    
//    bool empty() {
//        return size==0;
//    }
//    
//    // 스택이라서 끝에 추가하는 경우만 존재
//    void append(int x) {
//        Node *appendNode = new Node;
//        appendNode->value = x;
//        
//        if (empty()) {
//            head = tail = appendNode;
//        } else {
//            tail->next = appendNode;
//            tail = appendNode;
//        }
//        size++;
//    }
//    
//    // 스택이라서 끝을 삭제하는 경우만 존재
//    int deleteNode() {
//        int deletedValue = tail->value;
//        
//        // 한 개만 있는 경우
//        if (size == 1) {
//            delete head;
//            head = tail = nullptr;
//        } else {
//            Node *curNode = head;
//            while(curNode->next != tail) { // tail의 바로 이전 노드 탐색
//                curNode = curNode->next;
//            }
//            delete curNode->next;
//            curNode->next = nullptr;
//            tail = curNode;
//        }
//        this->size--;
//        
//        return deletedValue;
//    }
//    
//    friend class Stack;
//};
//
//class Stack{
//private:
//    LinkedList ll;
//    int size;
//
//public:
//    Stack() {
//        ll = LinkedList();
//        size = 0;
//    }
//    
//    bool empty() { // 비어있으면 1 출력
//        return size==0;
//    }
//
//    void top() { // 가장 위에 저장된 정수 출력. 비어있으면 -1 출력
//        if (empty()) {
//            cout << "-1\n";
//        } else {
//            cout << ll.tail->value << "\n";
//        }
//    }
//
//    void push(int x) { // 정수 x를 스택에 삽입 (x 범위는 1부터 10,000까지)
//        ll.append(x);
//        size++;
//    }
//
//    void pop() { // 스택 가장 위의 정수 삭제 후 수 출력. 비어있으면 -1 출력
//        if (empty()) {
//            cout << "-1\n";
//        } else {
//            cout << ll.deleteNode() << "\n";
//            size--;
//        }
//    }
//    
//    void printSize() {
//        cout << size << "\n";
//    }
//};
//
//int main() {
//    cin >> n;
//    Stack st = Stack();
//    
//    while(n--) {
//        string cmd;
//        cin >> cmd;
//        int x;
//        
//        if (cmd=="empty") {
//            cout << st.empty() << "\n";
//        } else if (cmd=="top") {
//            st.top();
//        } else if (cmd=="push") {
//            cin >> x;
//            st.push(x);
//        } else if (cmd=="pop") {
//            st.pop();
//        } else if (cmd=="size") {
//            st.printSize();
//        }
//    }
//}
//
///*
// - 노드의 구조
// - 링리의 구조
// - 스택의 구조
// - 링리 사용한 스택의 구조
// - 설계
// 
// - friend 클래스는 friend로 선언된 다른 클래스의 private 및 protected 멤버에 접근할 수 있습니다. 특정 상황에서 클래스 내에 접근하지 못하도록 private 제한을 두었는데, 필요의 경우 해당 클래스나 함수에서 접근 가능하도록 사용하는것이 friend 클래스 및 함수
// 
// - 보통 empty함수는 다른 함수에서 리턴값을 쓸 수 있기 때문에 void보다 bool로 선언해주는게 좋음
// 
// - 매개 변수와 객체 자신이 가지고 있는 변수의 이름이 같은 경우 이를 구분하기 위해 자신의 변수에 this를 사용한다.
// 
// 보통 생각할 경우는 1. 빈 경우 2. 한 개만 있는 경우 3. 두 개인 경우 4. 세 개 이상인 경우
// 
// 노드 객체 생성과 다른 클래스 생성 방법 왜 차이나는거임?
// */
