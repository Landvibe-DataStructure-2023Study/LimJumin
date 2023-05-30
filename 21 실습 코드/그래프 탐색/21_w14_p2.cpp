//
//  21_w14_p2.cpp
//  week14GraphSearch
//
//  Created by 임주민 on 2023/05/28.
//

/*
 무향그래프 생성, 두 정점 사이의 거리를 출력
 (두 정점 사이의 거리 : 두 정점을 연결하는 경로의 간선의 개수)
 (입력으로 주어지는 그래프에 싸이클 없음 -> 두 정점 사이의 경로는 유일하다)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numOfTestCase, numOfVertex, numOfEdge, numOfQuestion, a, b;
vector<int> graph[101]; // 그래프(벡터 이용)
bool visited[101]; // bfs를 위한 방문 여부 표시

int bfs(int start,int end) {
    queue<pair<int,int>> q;
    q.push({ start,0 });
    while (!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();
        if (front == end) return count;
        if (visited[front]) continue;
        visited[front] = true;
        for (auto i : graph[front]) {
            if (!visited[i]) q.push({ i,count + 1 });
        }
    }
    return 0;
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
        
        // 2) 두 정점의 거리를 구함
        while (numOfQuestion--) {
            cin >> a >> b;
            cout << bfs(a, b) << "\n"; // 입력받고 bfs 수행
            
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
