//
//  21_w13_p2.cpp
//  week13Graph
//
//  Created by 임주민 on 2023/05/24.
//

/*
 소셜 네트워크 서비스 개발 - 그룹 기능 추천
 (친구, 친구의 친구, 그룹)
 
 주의) 변수가 많으므로 변수명 헷갈리지 않게 주의하면서 코드 짜기
 */

#include <iostream>
#include <vector>

using namespace std;

int graph[501][501];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int numOfSubscribers, numOfCmd, sizeOfGroup, numberOfUser;
    cin >> numOfSubscribers >> numOfCmd;

    /*
     (가입자수)*(가입자수)만큼의 이중배열(그래프)를 만들고 친구관계를 입력받는다.
     */
    for (int i=1; i<=numOfSubscribers; i++) {
        for (int j=1; j<=numOfSubscribers; j++) {
            cin >> graph[i][j];
        }
    }

    /*
     그룹을 형성하기 적절한 관계이면 1, 아니면 0을 출력
     */
    for (int i=0; i<numOfCmd; i++) {
        cin >> sizeOfGroup; // 그룹 구성원의 수를 입력받는다.

        vector<int> group;
        for (int j=0; j<sizeOfGroup; j++) {
            cin >> numberOfUser; // 서로 다른 사용자의 번호들을 입력받고 벡터에 삽입
            group.push_back(numberOfUser);
        }

        int result = 0; // 결과를 저장할 변수
        for (int j=0; j<group.size(); j++) {
            for (int l=0; l<group.size(); l++) {
                if (j == l) continue; // 자신인 경우 넘어감

                result = 0;

                if (graph[group[j]][group[l]] == 1) {
                    // 친구인 경우
                    result = 1;
                } else {
                    // 친구의 친구인 경우
                    for (int o=1; o<=numOfSubscribers; o++) {
                        if (graph[group[j]][o] == 1 && graph[o][group[l]] == 1) {
                            result = 1;
                            break;
                        }
                    }
                }
                if (result == 0) break; // 친구도, 친구의 친구도 아닌 경우 그룹 형성 불가 -> 결과 0
            }
            if (result == 0) break; // 친구도, 친구의 친구도 아닌 경우 그룹 형성 불가 -> 결과 0
        }
        cout << result << "\n"; // 결과 출력
    }
}
