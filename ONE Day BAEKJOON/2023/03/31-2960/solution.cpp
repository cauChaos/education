// code by wapas
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    bool sieve[1001];
    fill(&sieve[0], &sieve[1001], true); // sieve 배열을 true로 채운다.
    for (int i = 2; i <= N; i++) { // i는 2부터 N까지 1씩 증가한다.
        for (int j = i; j <= N; j += i) { // j는 i부터 N까지 i씩 증가한다.
            if (sieve[j]) { // j가 지우지 않은 수라면
                K--; // K를 1 감소시키고
                sieve[j] = false; // j를 지운다.
                if (!K) { // K가 0이라면
                    cout << j; // j를 출력하고
                    return 0; // 프로그램을 종료한다.
                }
            }
        }
    }
}