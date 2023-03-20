//
//  22_w4_p1_2.cpp
//  LandVibeQueue
//
//  Created by 임주민 on 2023/03/20.
//

/*
 22년도 4주차 문제 1-2번
 배열을 통한 큐 구현
 */

#include <iostream>
using namespace std;

int n; // 입력받을 큐 Q의 크기를 전역변수로 선언(클래스 내에서도 사용해줄 거라서)

class Queue {
public:
    int arr[10000]; // 최대 크기 만큼 배열 선언
    int frontIdx = 0; // 데이터가 들어올 인덱스 0으로 초기화
    int rearIdx = -1; // 데이터가 나갈 인덱스 -1로 초기화(아무것도 없을 떄)
    int size = 0; // 사이즈 0으로 초기화

    void printSize() { cout << size << "\n"; }
    bool isEmpty() { return size == 0; }
    void updateIdx() { // *배열을 통한 큐 구현의 중요한 부분
        frontIdx %= n;
        rearIdx %= n;
    }
    void front() {
        if (isEmpty()) cout << "Empty\n";
        else {
            cout << arr[frontIdx] << "\n"; // 해당 인덱스 내의 데이터 그대로 출력
        }
    }
    void rear() {
        if (isEmpty()) cout << "Empty\n";
        else {
            cout << arr[rearIdx] << "\n"; // 해당 인덱스 내의 데이터 그대로 출력
        }
    }
    void enqueue(int value) { // 삽입
        if (size >= n) {
            cout << "Full\n";
        } else {
            rearIdx++; // rear을 나타내는 인덱스 증감 후 업데이트함수 실행(배열 최대 인덱스 넘어가면 안되니까)
            updateIdx();
            arr[rearIdx] = value; // 업데이트 된 rearIdx에 데이터 할당
            size++; // 사이즈 증가
        }
    }
    void dequeue() { // 삭제
        if (isEmpty()) {
            cout << "Empty\n";
        } else {
            cout << arr[frontIdx] << "\n"; // 삭제될 인덱스의 데이터 출력
            frontIdx++; // frontIdx 증감 후 업데이트 함수 실행(배열 최대 인덱스 넘어가면 안되니까)
            updateIdx();
            size--; // 사이즈 감소
        }
    }

};

int main() {
    int t;
    cin >> n >> t;
    Queue q;
    while(t--) {
        string cmd; cin >> cmd;
        if (cmd == "enqueue") {
            int value; cin >> value;
            q.enqueue(value);
        } else if (cmd=="dequeue") {
            q.dequeue();
        } else if (cmd=="isEmpty") {
            cout << q.isEmpty() << "\n";
        } else if (cmd=="size") {
            q.printSize();
        } else if (cmd=="front") {
            q.front();
        } else if (cmd=="rear") {
            q.rear();
        }
    }
}
