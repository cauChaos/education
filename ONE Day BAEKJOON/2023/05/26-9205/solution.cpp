// code by wapas
#include <bits/stdc++.h>

using namespace std;

void solution(int t) {
    // 입력 받기
    int N; cin >> N;
    vector<pair<int, int>> pointArray; // 집, 편의점, 페스티벌 좌표를 담는 배열
    for (int i = 0; i < N + 2; i++) {
        int y, x; cin >> y >> x;
        pointArray.push_back({ y, x });
    }

    // 그래프 모델링
    vector<vector<int>> adjList(N + 2); // 인접리스트
    for (int i = 0; i < N + 1; i++) {
        for (int j = i + 1; j < N + 2; j++) {
            auto [y1, x1] = pointArray[i];
            auto [y2, x2] = pointArray[j];
            int weight = abs(y1 - y2) + abs(x1 - x2);
            if (weight > 1000) continue; // 두 점의 맨해튼 거리가 1000m(맥주 20개 x 50m) 초과면 두 정점은 서로 이동할 수 없음.
            adjList[i].push_back(j);
            adjList[j].push_back(i);
        }
    }

    // BFS 코드 (DFS도 가능)
    queue<int> q; q.push(0);
    vector<bool> checkArray(N + 2, false); checkArray[0] = true;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == N + 1) {
            cout << "happy\n";
            return;
        }
        for (auto next : adjList[curr]) {
            if (checkArray[next]) continue;
            checkArray[next] = true;
            q.push({ next });
        }
    }
    cout << "sad\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) solution(t);
}
