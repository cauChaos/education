// code by wapas
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> firstTruth(K); // 처음부터 진실을 아는 사람 번호가 담긴 배열
    for (int i = 0; i < K; i++)
        cin >> firstTruth[i]; // 처음부터 진실을 아는 사람을 입력받습니다.
    vector<bool> visit(N + 1, false); // visit[i] := i번 사람이 진실을 아는가? 안다면 false, 모른다면 true. | i번 정점을 방문했는가? 방문했다면 true, 방문하지 않았다면 false.
    vector<vector<bool>> adjArray(N + 1, vector<bool>(N + 1, false)); // 인접행렬
    vector<vector<int>> partyArray; // 파티 배열
    for (int i = 0; i < M; i++) { // 파티를 입력 받습니다.
        int n;
        cin >> n;
        vector<int> party(n);
        for (int i = 0; i < n; i++)
            cin >> party[i];
        partyArray.push_back(party);
        for (auto a : party)
            for (auto b : party)
                adjArray[a][b] = true; // 같은 파티원끼리 간선을 잇습니다.
    }
    for (int i = 1; i <= N; i++)
        adjArray[i][i] = false; // self-loop 간선 제거
    function<void(int)> dfs = [&](int curr) { // 일반적인 dfs 함수
        visit[curr] = true;
        for (int next = 1; next <= N; next++)
            if (adjArray[curr][next] && !visit[next])
                dfs(next);
    };
    for (auto e : firstTruth)
        dfs(e); // 처음부터 진실을 아는 사람 정점으로 dfs를 시작합니다.
    int ans = 0;
    for (auto party : partyArray) {
        int cnt = 0; // 진실을 아는 사람 수
        for (auto e : party)
            if (visit[e])
                cnt++; // 방문한 정점 = 진실을 아는 사람
        if (!cnt)
            ans++; // 현재 파티내에서 진실을 아는 사람이 0명일 때 ans += 1을 합니다.
    }
    cout << ans;
}