// code by wapas
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    string ab = to_string(a * b); // a * b 값을 문자열로 변환
    string ans; // 답을 저장하는 변수
    ll temp = 0; // 세로식 나눗셈에서 임시 값을 저장하는 변수
    for (int i = 0; i < ab.size(); i++) { // 정수부 계산
        ll e = ab[i] - '0';
        temp = (temp * 10) + e; // 임시값의 가장 오른쪽에다 e를 붙임
        if (temp < c && !ans.size())
            continue; // leading zero 방지
        ans += to_string(temp / c); // 답에다가 항상 temp를 c로 나눈 몫을 붙여주고
        temp %= c; // temp에다 temp를 c로 나눈 나머지를 저장
    }
    if (!ans.size())
        ans += "0"; // 만약 정수부가 결과가 없을 경우 ans에 '0' 추가
    ans += "."; // 소숫점
    for (int i = 0; i < 18; i++) { // 소수부 계산
        temp *= 10; // 임시값의 가장 오른쪽에다 0을 붙임
        ans += to_string(temp / c); // 답에다가 항상 temp를 c로 나눈 몫을 붙여주고
        temp %= c; // temp에다 temp를 c로 나눈 나머지를 저장
    }
    cout << ans;
}