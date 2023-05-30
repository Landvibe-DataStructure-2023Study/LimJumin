//
//  21_w14_p3.cpp
//  week14GraphSearch
//
//  Created by 임주민 on 2023/05/28.
//

/*
 무향그래프 생성, 너비 우선 탐색(BFS)한 결과 출력
 (정점의 번호는 1~N, 모든 정점 연결되어 있음, 1번부터 탐색 시작, 여러 개인 경우 먼저 연결된 정점부터 우선 탐색)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numOfTestCase, numOfVertex, numOfEdge, numOfQuestion, a, b;
vector<int> graph[101]; // 그래프(벡터 이용)
bool visited[101]; // bfs를 위한 방문 여부 표시

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (visited[top]) continue;
        visited[top] = true;
        cout << top << " ";
        for (auto i : graph[top]) {
            if (!visited[i]) q.push(i);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> numOfTestCase;
    while (numOfTestCase--) {
        // 1) 그래프 입력 과정
        cin >> numOfVertex >> numOfEdge;
        while (numOfEdge--) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // 2) bfs 수행
        bfs();
        cout << "\n";
        
        // 3) 다음 테스트케이스를 위한 전역 변수 초기화 과정
        for (int i = 0; i <= 100; i++) {
            graph[i].clear();
            visited[i] = false;
        }
    }
}
