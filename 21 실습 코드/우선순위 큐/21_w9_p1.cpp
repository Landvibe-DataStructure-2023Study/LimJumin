//
//  21_w9_p1.cpp
//  PriorityQueue
//
//  Created by 임주민 on 2023/04/24.
//

/*
 우선순위 큐를 이용한 삽입정렬 구현(오름차순으로 정렬)
 */

#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
public:
    vector<int> v;

    bool empty() {
        return v.size() == 0;
    }

    void push(int data) { // 삽입 연산 : 삽입정렬에서는 삽입하면서 정렬하므로 자기가 들어갈 위치를 찾아야 함 O(n)
        if (empty()) { // 비어있으면 비교할 거 없이 그냥 넣기
            v.push_back(data);
        } else {
            vector<int>::iterator iter; // 벡터의 반복자 이용
            for (iter = v.begin(); iter != v.end(); iter++) { // 반복자로 순회하며
                if (data < *iter) { // 오름차순 정렬에 맞는 위치 찾으면
                    v.insert(iter, data); // 삽입 후 리턴
                    return;
                }
            }
            v.insert(v.end(), data); // 순회 해도 if문 안걸린 경우 -> 현재 제일 큰 수일 경우 -> 제일 끝에 삽입
        }
    }

    int pop() { // 삭제 연산 : 삽입정렬에서는 이미 정렬된 PQ의 맨 앞의 수를 삭제하기만 하면 되므로 O(1)
        if (!empty()) {
            int data = v.front(); // 맨 앞의 수
            v.erase(v.begin()); // PQ에서 삭제
            return data;
        } else { // 비어있으면 0 리턴
            return 0;
        }
    }
};

int main() {
    int T, N, num;
    cin >> T;
    while(T--) {
        cin >> N;

        vector<int> v; // 수열 입력받기 위한 벡터
        PriorityQueue pq; // 정렬에 사용할 우선순위 큐

        for (int i = 0; i < N; i++) { // 입력 : 수열 입력받아서 벡터에 저장
            cin >> num;
            v.push_back(num);
        }

        for (int i = 0; i < N; i++) { // 1단계 : 벡터 빌 때까지 요소를 PQ에 삽입(삽입하면서 정렬)
            pq.push(v.front());
            v.erase(v.begin());
        }

        for (int i = 0; i < N; i++) { // 2단계 : PQ빌 때까지 요소를 다시 벡터에 삽입
            v.push_back(pq.pop());
        }

        for (int i = 0; i < N; i++) { // 출력 : 오름차순으로 출력
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}
