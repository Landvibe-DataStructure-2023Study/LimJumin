//
//  21_w12_p3.cpp
//  week12Hash
//
//  Created by 임주민 on 2023/05/15.
//

#include <iostream>

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

struct Entry { // 키-값 쌍을 해시테이블의 각 인덱스에 저장하기 위한 구조체
    int key; // 키
    string value; // 값
    int valid; // 상태

    Entry() {
        key = 0;
        value = "";
        valid = NOITEM;
    }

    Entry(int _key, string _value) {
        key = _key;
        value = _value;
        valid = ISITEM;
    }
};

class HashTable {
private:
    Entry* hashTable; // 해시테이블(배열)
    int capacity; // 입력으로 주어지는 해시테이블의 크기
    int divisor; // 입력으로 주어지는 해시함수2에서 사용될 divisor
public:
    HashTable(int _capacity, int _divisor) {
        capacity = _capacity;
        divisor = _divisor;
        hashTable = new Entry[capacity]; // 주어진 용량만큼 Entry형 요소를 담을 수 있는 배열 생성
    }
    
    int hashFunc(int key) { // 해시 함수1
        return key % capacity;
    }
    
    int hashFunc2(int key) { // 해시 함수2
        return divisor - (key % divisor);
    }
    
    /*
     put K S
     문자열 S를 키 K를 이용해 해시테이블에 추가 후, probing 횟수를 출력 (키 K는 유일한 값이며 중복으로 주어지는 경우 X)
     */
    void put(int key, string value) {
        int idx = hashFunc(key); // key값을 해시 값으로 변환 -> 배열의 인덱스로 사용
        int probing = 1; // 탐사 횟수
        
        while(hashTable[idx].valid == ISITEM && probing <= capacity) {
            // 이미 찬 자리면 모든 해시테이블을 돌기 전까지 계속 탐사
            
            idx = hashFunc(idx + hashFunc2(key)); // 다음으로 이동 (이중 해싱)
            probing++; // 탐사 횟수 증가
        }
        cout << probing << "\n"; // 탐사횟수 출력
        
        if(probing > capacity) return; // 모든 자리 돌았는데 빈 자리 없었으면 리턴(종료)
        
        hashTable[idx] = Entry(key, value); // 괜찮으면 해시 테이블에 키-값 쌍 추가
    }
    
    /*
     erase K
     키 K에 해당하는 원소를 해시테이블에서 삭제, 존재하지 않으면 None 출력
     */
    void erase(int key) {
        int idx = hashFunc(key); // key를 해시 값으로 변환
        int probing = 1; // 탐사 횟수
        
        while(hashTable[idx].valid != NOITEM && probing <= capacity) {
            // while문 탈출 : 해당 인덱스에 엔트리가 없는 상태이거나 모든 해시테이블을 탐색하면 반복문 탈출
            
            if(hashTable[idx].valid == ISITEM && hashTable[idx].key == key) {
                hashTable[idx].valid = AVAILABLE; // 키를 찾으면 해시테이블에서 삭제 후 리턴
                return;
            }
            
            idx = hashFunc(idx+1); // 다음으로 이동 (선형 조사법)
            probing++; // 탐사횟수 증가
        }
        cout << "None\n"; // 존재하지 않은 경우 None 반환
    }
    
    /*
     find K
     키 K에 해당하는 원소를 탐색 후 저장된 문자열을 출력, 존재하지 않으면 None 출력
     */
    string find(int key) {
        int idx = hashFunc(key); // key를 해시 값으로 변환
        int probing = 1; // 탐사 횟수
        
        while(hashTable[idx].valid != NOITEM && probing <= capacity) {
            // while문 탈출 : 해당 인덱스에 엔트리가 없는 상태이거나 모든 해시테이블을 탐색하면 반복문 탈출
            
            if(hashTable[idx].valid == ISITEM && hashTable[idx].key == key) {
                return hashTable[idx].value; // 키를 찾으면 해당 값 반환
            }
            
            idx = hashFunc(idx + hashFunc2(key)); // 다음으로 이동 (이중해싱)
            probing++; // 탐사횟수 증가
        }
        return "None"; // 존재하지 않은 경우 None 반환
    }
    
    // 해시 테이블에 남아있는 빈공간 개수 출력
    void vacant() {
        int idx = 0;
        int cnt = 0;
        while (idx < capacity) {
            if(hashTable[idx].valid != ISITEM) cnt++;
            idx++;
        }
        cout << cnt << "\n";
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int numOfTest, sizeOfHashTable, divisor;
    cin >> numOfTest >> sizeOfHashTable >> divisor;
    
    HashTable *hashTable = new HashTable(sizeOfHashTable, divisor);
    
    while (numOfTest--) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "put") {
            int key;
            string value;
            cin >> key >> value;
            
            hashTable->put(key, value);
        } else if (cmd == "erase") {
            int key;
            cin >> key;
            
            hashTable->erase(key);
        } else if (cmd == "find") {
            int key;
            cin >> key;
            
            cout << hashTable->find(key) << "\n";
        }
    }
}

