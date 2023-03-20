//
//  21_w4_p4.cpp
//  LandVibeQueue
//
//  Created by 임주민 on 2023/03/19.
//

/*
 21년도 4주차 문제 4번
 카드 덱 문제 2 (배열을 통한 큐 구현 코드)
 */

#include <iostream>
using namespace std;

class Queue { // 필요한 함수만 구현, 큐의 사이즈가 0인 경우 고려할
public:
    int arr[100]; // 최대 카드 수 만큼 배열 크기 설정
    int frontIdx = 0; // 데이터가 들어올(head) 인덱스 0으로 초기화
    int rearIdx = -1; // 데이터가 나갈(tail) 인덱스 -1로 초기화(아무것도 없을 떄 -1)

    void enqueue(int value) { arr[++rearIdx] = value; }
    int dequeue() { return arr[frontIdx++]; }
};

int main() {
    int numOfTest, numOfCard, card; // 테스트케이스 수, 카드 수, 각 카드에 입력받을 체력
    cin >> numOfTest;

    while(numOfTest--) {
        Queue q1, q2; // 각 플레이어마다 큐 하나씩 생성
        int pointOfP1 = 0, pointOfP2 = 0; // 변수 초기화 중요 (잊지말기)
        int surplusHp1 = 0, surplusHp2 = 0;

        // MARK: - 입력
        cin >> numOfCard; // 카드 수 입력
        for(int i=0; i<numOfCard; i++) { // P1 체력 카드 입력받고 큐(q1)에 넣기
            cin >> card;
            q1.enqueue(card);
        }
        for(int i=0; i<numOfCard; i++) { // P2 체력 카드 입력받음 큐(q2)에 넣기
            cin >> card;
            q2.enqueue(card);
        }

        // MARK: - 문제 풀이
        for(int i=0; i<numOfCard; i++) { // 카드 개수인 n 만큼 게임 반복 실행
            int cardOfP1 = q1.dequeue() + surplusHp1; // 잔여체력 있으면 더해주기
            int cardOfP2 = q2.dequeue() + surplusHp2; // 잔여체력 있으면 더해주기

            if (cardOfP1 > cardOfP2) { // 플레이어 1가 win한 경우
                surplusHp2 = cardOfP1 - cardOfP2; // 플레이어 2(패자)에게 더해줄 잔여체력 할당
                surplusHp1 = 0; // 플레이어 1에게는 더해줄 잔여체력 없음
                pointOfP1++; // 플레이어 1 승점 추가
            } else if (cardOfP2 > cardOfP1) { // 플레이어 2가 win한 경우
                surplusHp1 = cardOfP2 - cardOfP1; // 플레이어 1(패자)에게 더해줄 잔여체력 할당
                surplusHp2 = 0; // 플레이어 2에게는 더해줄 잔여체력 없음
                pointOfP2++; // 플레이어 2 승점 추가
            } else { // 비긴 경우
                surplusHp1 = surplusHp2 = 0; // 둘 다 넘겨줄 잔여체력 없음
            }
        }

        // MARK: - 출력
        cout << ((pointOfP1 > pointOfP2) ? pointOfP1 : pointOfP2) << "\n"; // 이긴 플레이어의 승점 출력
    }
}
