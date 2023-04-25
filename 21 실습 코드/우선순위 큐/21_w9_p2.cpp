//
//  21_w9_p2.cpp
//  PriorityQueue
//
//  Created by 임주민 on 2023/04/24.
//

/*
 우선순위 큐를 이용한 선택정렬 구현(내림차순으로 정렬)
 */

#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
public:
    vector<int> v;

    void push(int data) { // 선택 정렬에서 삽입 연산은 정렬 없이 정말 그냥 넣는 거라서 O(1)
        v.push_back(data);
    }

    int pop() { // PQ에서 가장 큰 수를 찾아 선택해서 벡터에 다시 넣으며 PQ에서 삭제 -> n번 반복
        vector<int>::iterator p = v.begin();
        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
            if(*p < *iter) {
                p = iter;
            }
        }
        int maxValue = *p;
        v.erase(p);
        return maxValue;
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

        for (int i = 0; i < N; i++) { // 1단계 : 벡터 빌 때까지 요소를 PQ에 그냥 넣기(정렬 안함)
            pq.push(v.front());
            v.erase(v.begin());
        }

        for (int i = 0; i < N; i++) { // 2단계 : PQ빌 때까지 가장 큰 요소를 선택(내림차순 정렬)해서 벡터에 다시 삽입
            v.push_back(pq.pop());
        }

        for (int i = 0; i < N; i++) { // 출력 : 내림차순으로 출력
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}
