// code by wapas
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, N;
    cin >> x >> N;
    while (N--) // N번 반복 (매초마다 계산)
        if (x & 1)
            x = (2 * x) ^ 6; // 홀수일 때
        else
            x = (x / 2) ^ 6; // 짝수 일 때
    cout << x;
}