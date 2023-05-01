// code by wapas
#include <bits/stdc++.h>
#define MAX 101010
using namespace std;

int N, M, K;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    int stk = 0;
    for (int i = 1; i <= M; i++) { // 1층은 항상 비가 쌓입니다.
        int t, r;
        cin >> t >> r;
        stk += r;
        if (stk > K) { // 1층에 쌓이는 빗물만 확인합니다.
            cout << i << " " << 1 << "\n"; // 1층이 무너지면 1층을 출력합니다.
            return 0;
        }
    }
    cout << -1;
}
