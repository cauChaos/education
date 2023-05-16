// code by wapas
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        sum += x; // 뒷면으로 보이는 동전의 개수를 센다
    }
    cout << min(sum, N - sum); // 앞면의 동전을 뒤집는게 적은지, 뒷면의 동전을 뒤집는게 적은지 출력한다.
}