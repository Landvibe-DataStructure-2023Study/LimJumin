//
//  w2_p2.cpp
//  2023StudyLandVibe
//
//  Created by 임주민 on 2023/02/09.
//  단일 연결 리스트

#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node *next;
    
public:
    Node() {
        this->value = 0;
        this->next = nullptr;
    }
    
    ~Node() {
        this->value = 0;
        this->next = nullptr;
    }
    
    friend class LinkedList;
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    int size;
    
public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    
    ~LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    
    bool empty() {
        return (this->size == 0);
    }
    
    void addFront(int x) {
        Node *addNode = new Node;
        addNode->value = x;
        
        if (empty()) {
            this->head = addNode;
        } else {
            addNode->next = this->head;
            this->head = addNode;
        }
        
        this->tail = addNode;
        this->size++;
    }
    
    void removeFront() {
        if (empty()) {
            cout << "-1\n";
            return;
        }
        
        Node *deleteNode = this->head;
        
        if (this->size == 1) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            this->head = deleteNode->next;
        }
        
        int deleteValue = deleteNode->value;
        delete deleteNode;
        this->size--;
        cout << deleteValue << "\n";
    }
    
    void front() {
        if (empty()) {
            cout << "-1\n";
            return;
        }
        
        cout << this->head->value << "\n";
    }
};

int main() {
    int m;
    cin >> m;
    
    LinkedList *ll = new LinkedList; // 동적 생성
    
    while(m--) {
        int x;
        string cmd;
        cin >> cmd;
        
        if (cmd == "addFront") {
            cin >> x;
            ll->addFront(x);
        } else if (cmd == "removeFront") {
            ll->removeFront();
        } else if (cmd == "front") {
            ll->front();
        } else if (cmd == "empty") {
            cout << ll->empty() << "\n";
        }
    }
}
