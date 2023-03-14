//
//  21_w3_p2.cpp
//  2023StudyLandVibe
//
//  Created by 임주민 on 2023/03/14.
//

#include <iostream>
#define MAX 99 // 문제에서 지정한 최대 사이즈
using namespace std;

class Stack {
private:
    int arr[MAX];
    int size;
public:
    Stack() {
        size = 0;
    }
    bool empty() {
        return size==0;
    }
    int top() {
        if (empty()) {
            return -1;
        } else {
            return arr[size-1];
        }
    }
    void push(int x) {
        if (size == MAX) {
            cout << "FULL\n";
        } else {
            arr[size] = x;
            size++;
        }
    }
    int pop() {
        if (empty()) {
            return -1;
        } else {
            size--;
            return arr[size];
        }
    }
};

int main() {
    string input;
    int numTestCase;
    cin >> numTestCase;
    
    while(numTestCase) {
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
        
        // 문제 조건대로 일의 자리 수만 출력
        cout << st.pop() % 10 << "\n";
    }
}
