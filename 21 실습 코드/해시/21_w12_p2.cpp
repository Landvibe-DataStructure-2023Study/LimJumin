//
//  21_w12_p2.cpp
//  week12Hash
//
//  Created by 임주민 on 2023/05/15.
//

#include <iostream>

#define NOITEM 0
#define ISITEM 1

using namespace std;

struct Entry {
    int key;
    bool value;
    int valid;
    
    Entry() {
        key = 0;
        value = false;
        valid = NOITEM;
    }
    
    Entry(int _key, bool _value) {
        key = _key;
        value = _value;
        valid = ISITEM;
    }
};

class HashTable {
public:
    Entry* hashTable;
    int x;
    int y;
    int indexA;
    int indexB;
    
    HashTable(int _x, int _y) {
        x = _x;
        y = _y;
        hashTable = new Entry[x];
        indexA = 0;
        indexB = 0;
    }
    
    int rotate(int key, int offset, bool isClock, int divisor) {
        int returnValue;
        if(isClock) { // 시계방향회전 (역방향)
            if(offset - (key % divisor) < 0) {
                returnValue = divisor + (offset - (key % divisor));
            } else {
                returnValue = offset - (key % divisor);
            }
        } else { // 반시계방향회전 (순방향)
            returnValue = (offset + (key % divisor)) % divisor;
        }
        return returnValue;
    }
    
    int hashFuncA(int key, int offset, bool isClock) {
        return rotate(key, offset, isClock, x);
    }
    
    int hashFuncB(int key, int offset, bool isClock) {
        return rotate(key, offset, isClock, y);
    }
    
    void put(int key, int idxA, int idxB) {
        // 1 step
        indexA = hashFuncA(key, idxA, false);
        indexB = hashFuncB(key, idxB, true);
        int probing = 1;
        
        // 2 step
        if (hashTable[indexA].valid == ISITEM && probing <= x) {
            indexA = hashFuncA(indexB + 1, indexA, false);
            indexB = hashFuncB(indexB + 1, indexB, true);
            probing++;
        }
        
        // 3 step
        while (hashTable[indexA].valid == ISITEM && probing <= x) {
            indexA = hashFuncA(1, indexA, true);
            indexB = hashFuncB(1, indexB, false);
            probing++;
        }
        
        if (probing > x) {
            return;
        }
        
        hashTable[indexA] = Entry(key, true);
        cout << indexA+1 << " ";
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int numOfTest;
    cin >> numOfTest;
    
    while (numOfTest--) {
        int numOfGearA, numOfGearB, numOfCheck;
        cin >> numOfGearA >> numOfGearB >> numOfCheck;
        HashTable *hashTable = new HashTable(numOfGearA, numOfGearB);
        
        while (numOfCheck--) {
            int numOfRotation;
            cin >> numOfRotation;
            
            hashTable->put(numOfRotation, hashTable->indexA, hashTable->indexB);
        }
        cout << "\n";
    }
}
