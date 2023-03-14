//
//  21_w3_p4.cpp
//  2023StudyLandVibe
//
//  Created by 임주민 on 2023/03/14.
//
//  후위 표기식 연산
//  스택 구현 - 연결리스트 사용

#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node *next;

public:
    Node() {
        value = 0;
        next = nullptr;
    }
    friend class LinkedList;
    friend class Stack; // top()함수에서 value 접근하기 위해
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool empty() {
        return size==0;
    }

    // 스택이라 끝에 추가하는 경우만 존재
    void append(int x) {
        Node *appendNode = new Node;
        appendNode->value = x;

        if (empty()) {
            head = tail = appendNode;
        } else {
            tail->next = appendNode;
            tail = appendNode;
        }
        size++;
    }

    // 스택이라 끝을 삭제하는 경우만 존재
    int deleteNode() {
        int deletedValue = tail->value;

        // 한 개만 있는 경우
        if (size == 1) {
            delete head;
            head = tail = nullptr;
        } else {
            Node *curNode = head;
            while(curNode->next != tail) { // tail의 바로 이전 노드 탐색
                curNode = curNode->next;
            }
            delete curNode->next;
            curNode->next = nullptr;
            tail = curNode;
        }
        size--;
        
        return deletedValue;
    }

    friend class Stack;
};

class Stack{
private:
    LinkedList ll;
    int size;

public:
    Stack() {
        ll = LinkedList();
        size = 0;
    }

    bool empty() { // 비어있으면 1
        return size==0;
    }

    int top() { // 가장 위(tail)에 저장된 정수 리턴
        if (empty()) {
            return -1;
        } else {
            return ll.tail->value;
        }
    }

    void push(int x) { // 정수 x를 스택에 삽입(tail에 추가)
        ll.append(x);
        size++;
    }

    int pop() { // 스택 가장 위의 정수 삭제 후 수 리턴
        if (empty()) {
            return -1;
        } else {
            return ll.deleteNode();
        }
    }
};

int main() {
    string input;
    int numOfTestCase;
    cin >> numOfTestCase;
    
    while(numOfTestCase) {
        Stack st = Stack();
        int result = 0;
        char c;
        
        cin >> input;
        for(int i=0; i<input.length(); i++) {
            c = input[i];
            
            if (c >= '0' && c <= '9') {
                st.push(c-'0');
            } else {
                int num1 = st.pop();
                int num2 = st.pop();
                switch(c) {
                    case '+':
                        result = num2 + num1;
                        break;
                    case '-':
                        result = num2 - num1;
                        break;
                    case '*':
                        result = num2 * num1;
                        break;
                    case '/':
                        result = num2 / num1;
                        break;
                }
                st.push(result);
            }
        }
        
        // 문제 조건대로 출력
        cout << st.pop() << "\n";
    }
}
