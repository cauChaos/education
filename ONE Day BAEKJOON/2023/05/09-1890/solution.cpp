// code by wapas
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;
    ll map[100][100], cache[100][100];
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> map[y][x];
    memset(cache, 0, sizeof(cache)); // cache 원소들을 0으로 초기화
    cache[0][0] = 1; // (0, 0)은 기저값으로 1로 초기화
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            ll d = map[y][x];
            if (d == 0)
                continue; // 0이면 아무곳으로 이동하지 못한다.
            if (y + d < N)
                cache[y + d][x] += cache[y][x]; // (y + d, x)가 유효한 좌표면 (y, x)에 도달한 경로 수를 더한다.
            if (x + d < N)
                cache[y][x + d] += cache[y][x]; // (y, x + x)가 유효한 좌표면 (y, x)에 도달한 경로 수를 더한다.
        }
    }
    cout << cache[N - 1][N - 1];
}