// code by wapas
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll l, r;
    cin >> l >> r;

    // 에라토스테네스의 체
    const ll MAX = 1000000;
    vector<ll> primeArray;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= MAX; i++) { // 2 이상 1000000 이하의 소수 primeArray에 담습니다.
        if (!isPrime[i])
            continue;
        primeArray.push_back(i);
        for (int j = i * 2; j <= MAX; j += i)
            isPrime[j] = false;
    }

    vector<bool> isNoNoSquare(r - l + 1, true); // l 이상 r 이하가 제곱 ㄴㄴ 수인지 판별하는 배열입니다.
    for (auto p : primeArray) { // p 에는 소수가 들어갑니다.
        ll i = p * p; // i는 소수의 제곱입니다. (모든 수의 제곱수가 아닌 소수의 제곱수만 판별해도 된다는 것을 이용합니다.)
        if (i > r)
            break; // i가 r 보다 크다면 break 합니다.
        for (ll j = (l / i) * i; j <= r; j += i) { // 에라토스테네스의 체 처럼 제곱 ㄴㄴ 수가 아닌 수를 false로 바꿉니다.
            if (j < l)
                continue; // j가 l 이하인 경우가 있을 수 있으니, continue를 합니다.
            isNoNoSquare[j - l] = false;
        }
    }

    cout << count(isNoNoSquare.begin(), isNoNoSquare.end(), true); // true의 개수를 출력합니다.
}