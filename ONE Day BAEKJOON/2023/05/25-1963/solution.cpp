// code by wapas
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // isPrime := 에라토스테네스의 체
    vector<bool> isPrime(10000, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 10000; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * 2; j < 10000; j += i) isPrime[j] = false;
    }

    // 그래프 모델링
    vector<vector<int>> adjList(10000);
    for (int i = 1000; i < 10000; i++) { // i := 시작 정점
        if (!isPrime[i]) continue; // i가 소수가 아니라면 반려
        for (int j = 0; j < 4; j++) { // j := 바꿀 자리수
            int unit = (int) pow(10, j); // (j + 1)번째 자리수에 1씩 더하기 위해 unit을 선언
            int n = i; // n := 도착 정점
            for (int k = 0; k < 10; k++, n += unit) { // unit을 10번 더한다
                if ((n / unit) % 10 == 0 && k) n -= unit * 10; // k > 0이고, (j + 1)번째 자리 수가 0이라면 (j + 2)번째 자리수가 영향을 받으므로 unit * 10을 빼준다.
                if (n < 1000) continue; // n이 1000 미만이면 반려
                if (!isPrime[n]) continue; // n이 소수가 아니라면 반려
                adjList[i].push_back(n); // i -> n 간선을 이어준다
            }
        }
    }

    // BFS 코드
    auto bfs = [&](int start, int end) {
        queue<pair<int, int>> q;
        bool checkArray[10000] = { false, };
        checkArray[start] = true;
        q.push({ start, 0 });
        while (!q.empty()) {
            auto [curr, d] = q.front(); q.pop();
            if (curr == end) return d;
            for (int next : adjList[curr]) {
                if (checkArray[next]) continue;
                checkArray[next] = curr;
                q.push({ next, d + 1 });
            }
        }
        return -1;
    };

    // 테스트 케이스를 처리하는 코드
    int T; cin >> T;
    while (T--) {
        int s, e; cin >> s >> e;
        auto res = bfs(s, e);
        if (res == -1) cout << "Impossible";
        else cout << res;
        cout << "\n";
    }
}
