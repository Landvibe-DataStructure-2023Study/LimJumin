//
//  21_w2_p1.cpp
//  2023StudyLandVibe
//
//  Created by 임주민 on 2023/03/09.
//  단일 연결 리스트 LL

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
    
    void print() {
        if (empty()) {
            cout << "empty";
            return;
        }
        
        Node *curNode = this->head;
        while (curNode != nullptr) {
            cout << curNode->value << " ";
            curNode = curNode->next;
        }
    }
    
    void append(int x) {
        Node *appendNode = new Node;
        appendNode->value = x;
        
        if (empty()) {
            this->head = appendNode;
        } else {
            this->tail->next = appendNode;
        }
        
        this->tail = appendNode;
        this->size++;
        print();
    }
    
    int deleteNode(int index) {
        if (index >= this->size) {
            return -1;
        }
        
        Node *deleteNode = this->head;
        
        if (index == 0) {
            if (this->size == 1) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->head = deleteNode->next;
            }
        } else {
            Node *prevNode = this->head;
            for (int i=0; i<index; i++) {
                prevNode = deleteNode;
                deleteNode = deleteNode->next;
            }
            prevNode->next = deleteNode->next;
            if(deleteNode == this->tail) {
                this->tail = prevNode;
            }
        }
        
        int deleteValue = deleteNode->value;
        delete deleteNode;
        this->size--;
        return deleteValue;
    }
    
    void insert(int index, int x) {
        if (index > this->size) {
            cout << "Index Error";
            return;
        }
        
        if (index == 0) {
            Node *insertNode = new Node;
            insertNode->value = x;
            insertNode->next = this->head;
            this->head = insertNode;
            print();
        } else if (index == this->size) {
            append(x);
        } else {
            Node *insertNode = new Node;
            insertNode->value = x;
            
            Node *curNode = this->head;
            for (int i=1; i<index; i++) {
                curNode = curNode->next;
            }
            insertNode->next = curNode->next;
            curNode->next = insertNode;
            print();
        }
        this->size++;
    }
    
    void sum() {
        if(empty()) {
            cout << "0";
            return;
        }
        
        int sum = 0;
        Node *curNode = this->head;

        while(curNode != nullptr) {
            sum += curNode->value;
            curNode = curNode->next;
        }
        cout << sum;
    }
};

int main() {
    LinkedList *ll = new LinkedList;
    
    int m;
    cin >> m;
    
    while(m--) {
        string cmd;
        int index;
        int x;
        cin >> cmd;
        
        if (cmd == "Print") {
            ll->print();
        } else if (cmd == "Append") {
            cin >> x;
            ll->append(x);
        } else if (cmd == "Delete") {
            cin >> index;
            cout << ll->deleteNode(index);
        } else if (cmd == "Insert") {
            cin >> index >> x;
            ll->insert(index, x);
        } else if (cmd == "Sum") {
            ll->sum();
        }
        cout << "\n";
    }
}
