//
//  22_w5_p4.cpp
//  LandVibeWeek5
//
//  Created by 임주민 on 2023/03/31.
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
    
    void solving(Iterator &p) {
        int max, min;
        
        if (p.node == head->next) { // head의 next(첫번째 노드인 경우) 2개수 중 max, min 구하기
            int a = p.node->value;
            int b = p.node->next->value;
            
            max = (a>b) ? a : b;
            min = (a>b) ? b : a;
        } else if (p.node == tail->prev) { //tail의 prev(마지막 노드인 경우) 2개수 중 max, min 구하기
            int a = p.node->value;
            int b = p.node->prev->value;
            
            max = (a>b) ? a : b;
            min = (a>b) ? b : a;
        } else { // 그냥 중간에 있는 노드인 경우 (3개수 중 max, min 구하기)
            int a = p.node->prev->value;
            int b = p.node->value;
            int c = p.node->next->value;
            
            if (a > b && a > c) {
                max = a;
                min = (b < c) ? b : c;
            } else if (b > a && b > c) {
                max = b;
                min = (c < a) ? c : a;
            } else {
                max = c;
                min = (a < b) ? a : b;
            }
        }
        cout << max-min << " ";
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t, n;
    cin >> t;
    
    while (t--) {
        Sequence seq = Sequence();
        Iterator p = Iterator(seq.begin());
        
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            
            seq.insert(p, num);
        }
        
        p = seq.begin();
        
        for(int i = 0; i < n; i++) {
            seq.solving(p);
            ++p;
        }
        
        cout << "\n";
    }
}
