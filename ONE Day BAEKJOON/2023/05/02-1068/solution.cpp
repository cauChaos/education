// code by wapas
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> adjList(N + 1, vector<int>()); // 인접 리스트
    vector<int> parent(N); // 정점의 부모를 저장
    for (int a = 0; a < N; a++) {
        int b;
        cin >> b; // a = 자식, b = 부모
        if (b == -1)
            b = N; // a가 루트면 N을 부모로 한다.
        parent[a] = b; // a의 부모 저장
        adjList[b].push_back(a); // b에서 자식으로 잇는 간선 저장
    }
    int cut;
    cin >> cut; // 삭제할 정점
    remove(adjList[parent[cut]].begin(), adjList[parent[cut]].end(), cut);
    adjList[parent[cut]].pop_back(); // 삭제할 정점의 부모 인접 리스트에서 자신으로 향하는 간선 제거
    int ans = 0;
    function<void(int, int)> dfs = [&](int curr, int last) {
        if (curr != N && adjList[curr].empty()) {
            ans++;
            return;
        } // 자식이 없으면 ans += 1을 하되 정점 번호가 N이라면 카운트 하지 않는다.
        for (auto next : adjList[curr])
            if (next != last)
                dfs(next, curr);
    };
    dfs(N, -1); // 루트는 항상 N번 정점
    cout << ans;
}