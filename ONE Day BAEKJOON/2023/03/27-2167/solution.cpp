// code by wapas
#include <bits/stdc++.h>
#define MAX 303

using namespace std;

int arr[MAX][MAX];

void solution()
{
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    int res = 0;
    for (int y = y1; y <= y2; y++)
        for (int x = x1; x <= x2; x++)
            res += arr[y][x]; // 2중 for문으로 y1 <= y <= y2와 x1 <= x <= x2를 만족하는 arr[y][x]를 모두 더합니다.
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= M; x++)
            cin >> arr[y][x]; // 2차원 배열 값을 저장합니다.
    int K;
    cin >> K;
    while (K--)
        solution();
}