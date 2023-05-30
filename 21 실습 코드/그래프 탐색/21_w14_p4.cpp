//
//  21_w14_p4.cpp
//  week14GraphSearch
//
//  Created by 임주민 on 2023/05/28.
//

/*
 무향그래프 생성, 한 정점이 속하는 연결요소의 크기를 출력
 (연결요소의 크기 : 해당 연결요소에 속한 정점의 개수)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numOfTestCase, numOfVertex, numOfEdge, numOfQuestion, a, b;
vector<int> graph[101]; // 그래프(벡터 이용)
bool visited[101]; // bfs를 위한 방문 여부 표시

int bfs(int start) {
    queue<int> q;
    q.push(start); // 큐에 해당 정점 삽입
    int connected = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (visited[front]) continue;
        visited[front] = true;
        ++connected;
        for (auto i : graph[front]) {
            if (!visited[i]) q.push(i);
        }
    }
    return connected;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> numOfTestCase;
    while (numOfTestCase--) {
        // 1) 그래프 입력 과정
        cin >> numOfVertex >> numOfEdge >> numOfQuestion;
        
        while (numOfEdge--) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // 2) 해당 정점이 속하는 연결요소의 크기를 출력
        while (numOfQuestion--) {
            cin >> a;
            cout << bfs(a) << "\n"; // 입력받고 bfs 수행
            
            // 다음 질문을 위한 방문여부 배열(전역변수) 초기화 과정
            for (int i = 0; i <= 100; i++) {
                visited[i] = false;
            }
        }
        
        // 3) 다음 테스트 케이스에서 입력받을 새로운 그래프를 위해 그래프 전역변수 초기화
        for (int i = 0; i <= 100; i++) {
            graph[i].clear();
        }
    }
}
