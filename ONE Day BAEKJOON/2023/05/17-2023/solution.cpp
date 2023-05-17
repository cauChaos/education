// code by wapas
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> db = {
    {},
    { 2, 3, 5, 7 },
    { 23, 29, 31, 37, 53, 59, 71, 73, 79 },
    { 233, 239, 293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797 },
    { 2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793, 3797, 5939, 7193, 7331, 7333, 7393 },
    { 23333, 23339, 23399, 23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393, 59399, 71933, 73331, 73939 },
    { 233993, 239933, 293999, 373379, 373393, 593933, 593993, 719333, 739391, 739393, 739397, 739399 },
    { 2339933, 2399333, 2939999, 3733799, 5939333, 7393913, 7393931, 7393933 },
    { 23399339, 29399999, 37337999, 59393339, 73939133 }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* 런타임 전의 전처리
    // 에라토스테네스의 체
    const ll MAX = 1e9;
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= MAX; i++) {
        if (!isPrime[i]) continue;
        for (ll j = i * 2; j <= MAX; j += i) isPrime[j] = false;
    }

    auto isValid = [&](ll n) { // 신기한 소수인지 확인
        ll x = 0; // 현재 확인하는 수
        for (auto e : to_string(n)) {
            x = x * 10 + (e - '0'); // 기존 수는 ×10를 하고, 일의 자리에 새 숫자를 추가
            if (!isPrime[x]) return false; // 소수가 아니면 신기한 소수가 아님
        }
        return true;
    };

    for (int i = 0; i <= MAX; i++) if (isValid(i)) cout << i << ", ";
    */

    int N;
    cin >> N;
    for (auto e : db[N])
        cout << e << "\n";
}