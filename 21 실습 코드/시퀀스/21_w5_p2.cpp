//
//  21_w5_p2.cpp
//  LandVibeWeek5
//
//  Created by 임주민 on 2023/03/28.
//

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    Node *next;
    Node *prev;
    int value;
    
    Node() {
        next = prev = nullptr;
        value = 0;
    }
};

class Iterator {
public:
    Node *node;
    
    Iterator() {
        node = nullptr;
    }
    
    Iterator(Node *n) {
        node = n;
    }
    
    Iterator *operator++() {
        node = node->next;
        return this;
    }
    Iterator *operator--() {
        node = node->prev;
        return this;
    }
};

class Sequence {
public:
    Node *head;
    Node *tail;
    int size;
    
    Sequence() {
        head = new Node;
        tail = new Node;
        
        head->next= tail;
        tail->prev = head;
        size = 0;
    }
    
    Node *begin() {
        return head->next;
    }
    
    Node *end() {
        return tail;
    }
    
    void insert(Iterator &p, int e) {
        Node *newNode = new Node();
        newNode->value = e;
        
        p.node->prev->next = newNode;
        newNode->prev = p.node->prev;
        
        newNode->next = p.node;
        p.node->prev = newNode;
        
        size++;
    }
    
    void print() {
        if (size == 0) {
            cout << "Empty\n";
        } else {
            Node *curNode = head->next;
            
            while (curNode != tail) {
                cout << curNode->value << " ";
                curNode = curNode->next;
            }
            
            cout << "\n";
        }
    }
    
    void find(int e) {
        if (size == 0) {
            cout << "Empty\n";
        } else {
            Node *curNode = head->next;
            int index = 0;
            
            while (curNode != tail) {
                if (curNode->value == e) {
                    cout << index << "\n";
                    return;
                } else {
                    curNode = curNode->next;
                    index++;
                }
            }
            cout << "-1\n";
        }
    }
    
    void maxPooling(Iterator &p) {
        int num1 = p.node->prev->value;
        int num2 = p.node->value;
        int num3 = p.node->next->value;
        
        /*
         문제 조건에 맞춰서 이부분 구현
         -> 이 문제는 세 수 비교해서 max 값 출력
         */
        if (num1 > num2 && num1 > num3) {
            cout << num1 << " ";
        } else if (num2 > num1 && num2 > num3) {
            cout << num2 << " ";
        } else if (num3 > num1 && num3 > num2) {
            cout << num3 << " ";
        }
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t, n;
    cin >> t;
    
    while(t--) {
        Sequence seq = Sequence();
        Iterator p = Iterator(seq.begin());
        
        cin >> n;
        for (int i=0; i<n; i++) {
            int num;
            cin >> num;
            
            seq.insert(p, num);
        }
        
        p = seq.begin();
        
        for(int i=0; i<n; i++) {
            seq.maxPooling(p);
            ++p;
        }
        cout<<"\n";
    }
}
