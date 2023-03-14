//
//  w3_p1.cpp
//  2023StudyLandVibe
//
//  Created by 임주민 on 2023/03/14.
//

#include <iostream>
using namespace std;

int t, n;

const int MAX_SIZE = 10;

class Stack {
private:
    int arr[MAX_SIZE];
    int size;
public:
    Stack() {
        size = 0;
    }
    bool empty() {
        return size==0;
    }
    void top() {
        if (empty()) {
            cout << "-1\n";
        } else {
            cout << arr[size-1] << "\n";
        }
    }
    void push(int x) {
        if (size==t) {
            cout << "FULL\n";
        } else {
            arr[size] = x;
            size++;
        }
    }
    void pop() {
        if (empty()) {
            cout << "-1\n";
        } else {
            top();
            size--;
        }
    }
};

int main() {
    cin >> t >> n;
    Stack st = Stack();
    
    for (int i=0; i<n; i++) {
        string cmd;
        cin >> cmd;
        int x;
        
        if (cmd=="empty") {
            if(st.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (cmd=="top") {
            st.top();
        } else if (cmd=="push") {
            cin >> x;
            st.push(x);
        } else if (cmd=="pop") {
            st.pop();
        }
    }
    return 0;
}
