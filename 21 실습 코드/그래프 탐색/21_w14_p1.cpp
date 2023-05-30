//
//  21_w14_p1.cpp
//  week14GraphSearch
//
//  Created by 임주민 on 2023/05/28.
//

/*
 무향그래프 생성, 깊이 우선 탐색(DFS)한 결과 출력
 (정점의 번호는 1~N, 모든 정점 연결되어 있음, 1번부터 탐색 시작, 여러 개인 경우 먼저 연결된 정점부터 우선 탐색)
 */

#include <iostream>
#include <vector>

using namespace std;

int numOfTestCase, numOfVertex, numOfEdge, a, b;
vector<int> graph[101]; // 그래프(벡터 이용)
bool visited[101]; // dfs를 위한 방문 여부 표시

/*
 재귀 함수 dfs
 */
void dfs(int x) {
    cout << x << " "; // 선출력
    visited[x] = true; // 방문했다고 표시(중복 방문 방지)
    for (auto i : graph[x]) {
        if (!visited[i]) dfs(i); // 아직 방문하지 않은 연결된 정점에 dfs 수행
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> numOfTestCase;
    while (numOfTestCase--) {
        // 1) 입력과정
        cin >> numOfVertex >> numOfEdge;
        while (numOfEdge--) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // 2) dfs 수행
        dfs(1);
        cout << "\n";
        
        // 다음 테스트케이스를 위한 전역 변수 초기화 과정
        for (int i = 0; i <= 100; i++) {
            graph[i].clear();
            visited[i] = false;
        }
    }
}
