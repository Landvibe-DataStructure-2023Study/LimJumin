//
//  w2_p1.cpp
//  2023StudyLandVibe
//
//  Created by 임주민 on 2023/02/09.
//  배열

#include <iostream>
using namespace std;
#define MAX 10000

int arr[MAX];
int length;

void at(int idx) {
    cout << arr[idx] << "\n";
}

void set(int idx, int X) {
    if (idx > length-1) {
        cout << 0 << "\n";
    }
    else { arr[idx] = X; }
}

void add(int idx, int X) {
    if (idx > length-1) {
        arr[length] = X;
    }
    else {
        for(int i=length-1; i>=idx; i--) {
            arr[i+1] = arr[i];
        }
        arr[idx] = X;
    }
    length++;
}

int main() {
    int M; cin >> M;
    while(M--) {
        string s; cin >> s;
        if (s=="at") {
            int i;
            cin >> i;
            at(i);
        } else if (s=="set") {
            int i, X;
            cin >> i >> X;
            set(i,X);
        } else if (s=="add") {
            int i, X;
            cin >> i >> X;
            add(i,X);
        } else {}
    }
}
