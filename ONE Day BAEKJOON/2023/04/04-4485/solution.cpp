// code by wapas
#include <bits/stdc++.h>
#define MAX_N 125
#define INF 1'000'000'000

using namespace std;
typedef tuple<int, int, int> tup;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool solution(int t)
{ // 하나의 테스트 케이스에 대해서 처리
    int N;
    cin >> N;
    if (!N)
        return false; // N이 0이면 종료

    int board[MAX_N][MAX_N]; // 동굴에 있는 각 도둑 루피의 크기들
    int cache[MAX_N][MAX_N] = {
        0,
    }; // 데이크스트라를 하기 위해 값을 저장하는 캐시 변수
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];

    fill(&cache[0][0], &cache[MAX_N][0], INF); // 캐시의 초기값을 INF로 초기화
    priority_queue<tup> pq;
    auto isValidCoord = [&](int y, int x) { // y, x가 유효한 좌표인지 확인하는 함수
        return 0 <= y && y < N && 0 <= x && x < N;
    };

    // 데이크스트라 코드
    cache[0][0] = board[0][0];
    pq.push({ 0, 0, cache[0][0] });
    while (pq.size()) {
        auto [y, x, d] = pq.top();
        pq.pop();
        if (cache[y][x] < d)
            continue;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (!isValidCoord(ny, nx))
                continue;
            int nd = cache[y][x] + board[ny][nx];
            if (cache[ny][nx] <= nd)
                continue;
            cache[ny][nx] = nd;
            pq.push({ ny, nx, nd });
        }
    }

    printf("Problem %d: %d\n", t, cache[N - 1][N - 1]);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (solution(T++)) { } // 각 테스트케이스 당 solution() 함수 실행
}