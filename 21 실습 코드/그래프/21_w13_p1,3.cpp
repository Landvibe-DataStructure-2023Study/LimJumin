////
////  21_w13_p1,3.cpp
////  week13Graph
////
////  Created by 임주민 on 2023/05/24.
////
//
///*
// 인접 행렬 기반의 무향그래프를 생성하는 프포그램 작성
// (insertEdge, eraseEdge, isAdjacentTo, incidentEdges)
// */
//
//#include <iostream>
//
//using namespace std;
//
//int vertex, s, d;
//string cmd;
//
//bool graph[2000][2000];
//
//int main() {
//    int numOfCmd, numOfVertex;
//    cin >> numOfCmd >> numOfVertex;
//
//    for (int i = 0; i < numOfVertex; i++) {
//        cin >> vertex; // 굳이 쓰이지는 않는 코드. 입력만 받음
//    }
//
//    for (int i = 0; i < numOfCmd; i++) {
//        cin >> cmd >> s;
//
//        if (cmd == "insertEdge") {
//            cin >> d;
//            if(graph[s][d]) { // 간선 이미 존재
//                cout<<"Exist\n";
//            } else { // 간선 추가
//                graph[s][d] = true;
//                graph[d][s] = true;
//            }
//        } else if(cmd == "eraseEdge") {
//            cin >> d;
//            if(!graph[s][d]) { // 간선 존재하지 않는 경우 (false인 경우)
//                cout<<"None\n";
//            } else { // 간선 삭제
//                graph[s][d] = false;
//                graph[d][s] = false;
//            }
//        } else if(cmd == "isAdjacentTo") {
//            cin >> d;
//            if(graph[s][d]) { // 간선 존재하면 true (graph[d][s]라고 써도 됨)
//                cout<<"True\n";
//            } else {
//                cout<<"False\n";
//            }
//        } else if(cmd == "incidentEdges") {
//            int cnt = 0;
//            for(int i=0; i<2000; i++) { // 인접한 간선 개수 춫력
//                if(graph[s][i]) cnt++;
//            }
//            cout << cnt << "\n";
//        }
//    }
//}
