// code by wapas
#include <bits/stdc++.h>

using namespace std;

void solution()
{
    int N;
    cin >> N;
    // 변수 초기화
    /*
        three = 3의 개수
        five = 5의 개수
        eight = 8의 개수
        minValue = 3, 5, 8를 사용한 개수 중 최솟값
    */
    int three = -1, five = -1, eight = -1;
    int minValue = 2e9;
    /*
        출력해야하는 수들의 각 자리수 합은 N이므로
        3x + 5y + 8z = N 을 만족해야 합니다.
        
        [Greedy]
        [1] 최대한 z가 많아야 자리수가 적습니다.
        [2] z 다음으로 최대한 y가 많아야 자리수가 적습니다.
        [3] x, y, z 값을 안다면 3, 5, 8 순서로 출력하면 수가 가장 작습니다. (ex. 3333355555588888)
        
        [Bruteforce + Greedy]
        3 + 5 = 8 이므로 3과 5의 개수만 알고 있어도 8의 개수를 min(x, y)로 결정 할 수 있습니다.
        따라서 3x + 5y = N 에 대해서만 브루트포싱을 합니다.
    */
    for (int y = 0; y * 5 <= N; y++) { // 5의 개수 y 입니다.
        int x3 = N - y * 5; // x * 3 입니다.
        if (x3 % 3 != 0)
            continue; // x * 3 가 3의 배수인지 확인합니다.
        int x = x3 / 3;
        int z = min(y, x);
        int sum = y + x - z; // 3, 5, 8을 사용한 개수를 구합니다.
        if (sum >= minValue)
            continue; // 만약 지금까지 구한 최솟값보다 크거나 같으면 보지 않습니다.
        minValue = sum;
        five = y - z;
        three = x - z;
        eight = z;
    }
    if (three == -1) { // three가 -1이라는 뜻은 초기값이므로 for문에서 갱신된 적이 없다는 뜻입니다. 따라서 생일수가 존재하지 않는 경우입니다.
        cout << -1 << "\n";
        return;
    }
    // 3, 5, 8 순서로 출력합니다.
    while (three--)
        cout << "3";
    while (five--)
        cout << "5";
    while (eight--)
        cout << "8";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
        solution();
}