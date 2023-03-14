//
//  w3_p2_1.cpp
//  2023StudyLandVibe
//
//  Created by 임주민 on 2023/02/14.
//  후위 표기 변환 - 스택(배열, 연결리스트로 구현) 사용

#include <iostream>
using namespace std;

int t, n;

class Stack {
private:
    int arr[10]{};
    int size;
public:
    Stack() {
        size = 0;
    }
    bool empty() {
        return size == 0;
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
            this->top();
            size--;
        }
    }
};

int main() {
    
}

/*
 중위 표기법 -> 후위 표기법
 
 */
