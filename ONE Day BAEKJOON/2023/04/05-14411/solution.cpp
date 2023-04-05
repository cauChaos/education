// code by wapas
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll arr[5050505];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        x /= 2;
        y /= 2; // 제 1사분면에 있는 점 좌표만 저장
        arr[x] = max(arr[x], y); // arr[i] : x좌표가 i인 점들 중 높이가 가장 높은 점의 y좌표
    }
    ll ans = 0, maxSide = 0; // 정답이 int 변수형 범위를 벗어나므로 long long 자료형으로 계산
    for (int x = 5000000; x > 0; x--) { // x가 감소하는 방향으로 5 * 10^6부터 1까지 스위핑 : (x, y)가 0 ~ x까지 y만큼 넓이를 차지하는 특성을 이용
        maxSide = max(maxSide, arr[x]); // y좌표가 더 큰 점을 만나면 변의 길이 갱신 : for문으로 x좌표가 감소하는 방향으로 적분
        ans += maxSide; // 현재 x좌표에서의 변의 길이를 더해줌
    }
    cout << ans * 4; // 제 1사분면의 넓이만 구했으므로 4를 곱해준다.
}