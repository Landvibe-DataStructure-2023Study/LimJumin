////
////  21_w10_p1.cpp
////  Week10Heap
////
////  Created by 임주민 on 2023/05/01.
////
//
///*
// 힙을 기반으로 우선순위 큐 구현 - 최대 힙
// */
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Heap {
//private:
//    vector<int> v;
//    int sizeOfHeap = 0;
//    int indexOfRoot = 1;
//public:
//    Heap() {
//        v.push_back(-1);
//    }
//    void swap(int a, int b) {
//        v[0] = v[a];
//        v[a] = v[b];
//        v[b] = v[0];
//    }
//    void upHeap(int idx) { // 올라가면서 힙을 재구성 (보통 삽입한 후 수행)
//        if(idx == indexOfRoot) return; // 새로운 노드가 루트 노드면 리턴
//        else { // 새로운 노드가 루트 노드가 아닐 때
//            int parent = idx/2;
//            if(v[idx] > v[parent]) { // 부모 노드보다 우선순위가 높다면 위치 바꿈
//                swap(parent, idx);
//                upHeap(parent); // 재귀적으로 upHeap 호출하면서 계속해서 힙 올바르게 재구성
//            }
//        }
//    }
//    void downHeap(int idx) { // 내려가면서 힙을 재구성 (보통 삭제한 후 수행)
//        int left = idx*2; // 왼쪽 자식
//        int right = idx*2+1; // 오른쪽 자식
//        int maxIndex = idx; // 가장 우선순위가 높은(최대값) 노드의 위치를 저장할 변수
//
//        if (left <= sizeOfHeap && v[left] > v[maxIndex]) { // 1)왼쪽 자식 노드와 비교 후 업뎃
//            maxIndex = left;
//        }
//        if (right <= sizeOfHeap && v[right] > v[maxIndex]) { // 2)오른쪽 자식 노드와 비교 후 업뎃
//            maxIndex = right;
//        }
//
//        // 최대값이 부모 노드가 아니라면 위치 바꿈
//        if (maxIndex != idx) {
//            swap(idx, maxIndex);
//            downHeap(maxIndex);
//        }
//    }
//
//    /*
//     문제에 주어진 함수 구현
//     */
//    void insert(int i) {
//        v.push_back(i);
//        sizeOfHeap++;
//        upHeap(sizeOfHeap);
//    }
//    int size() {
//        return sizeOfHeap;
//    }
//    bool isEmpty() {
//        return sizeOfHeap == 0;
//    }
//    int pop() {
//        if(isEmpty()) return -1;
//        else {
//            int top = v[indexOfRoot];
//            v[indexOfRoot] = v[sizeOfHeap];
//            sizeOfHeap--;
//            v.pop_back();
//            downHeap(indexOfRoot);
//            return top;
//        }
//    }
//    int top() {
//        if(isEmpty()) return -1;
//        else {
//            return v[indexOfRoot];
//        }
//    }
//    void print() {
//        if(isEmpty()) cout << "-1\n";
//        else {
//            for(int i=indexOfRoot; i<=sizeOfHeap; i++) {
//                cout << v[i] << " ";
//            }
//            cout << "\n";
//        }
//    }
//};
//
//int main() {
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    int numOfTestCase;
//    cin >> numOfTestCase;
//
//    Heap heap;
//
//    while(numOfTestCase--) {
//        string cmd;
//        cin >> cmd;
//        if (cmd == "insert") {
//            int i;
//            cin >> i;
//            heap.insert(i);
//        } else if (cmd == "size") {
//            cout << heap.size() << "\n";
//        } else if (cmd == "isEmpty") {
//            cout << heap.isEmpty() << "\n";
//        } else if (cmd == "pop") {
//            cout << heap.pop() << "\n";
//        } else if (cmd == "top") {
//            cout << heap.top() << "\n";
//        } else if (cmd == "print") {
//            heap.print();
//        }
//    }
//}
