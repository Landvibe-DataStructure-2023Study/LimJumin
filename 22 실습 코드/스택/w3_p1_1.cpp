////
////  w2_p3.cpp
////  2023StudyLandVibe
////
////  Created by 임주민 on 2023/02/12.
////  스택 구현 - 배열 사용
//
//#include <iostream>
//using namespace std;
//
//int t, n;
//
//class Stack {
//private: // 비공개멤버로 클래스 내(예를 들면 멤버함수 method)에서만 접근 가능
//    int arr[10]{}; // t의 범위는 1부터 10이라 최대로 선언
//    int size;
//public: // 공개멤버로 클래스 외부(예를 들면 메인함수)에서도 접근 가능
//    Stack() {
//        size = 0;
//    }
//    bool empty() {
//        return size == 0;
//    }
//    void top() {
//        if (empty()) {
//            cout << "-1\n";
//        } else {
//            cout << arr[size-1] << "\n";
//        }
//    }
//    void push(int x) {
//        if (size==t) {
//            cout << "FULL\n";
//        } else {
//            arr[size] = x;
//            size++;
//        }
//    }
//    void pop() {
//        if (empty()) {
//            cout << "-1\n";
//        } else {
//            this->top();
//            size--;
//        }
//    }
//};
//
//int main() {
//    cin >> t >> n;
//    Stack st = Stack();
//    
//    for (int i=0; i<n; i++) {
//        string cmd;
//        cin >> cmd;
//        int x;
//        
//        if (cmd=="empty") {
//            if(st.empty()) {
//                cout << "1\n";
//            } else {
//                cout << "0\n";
//            }
//        } else if (cmd=="top") {
//            st.top();
//        } else if (cmd=="push") {
//            cin >> x;
//            st.push(x);
//        } else if (cmd=="pop") {
//            st.pop();
//        }
//    }
//    return 0;
//}
