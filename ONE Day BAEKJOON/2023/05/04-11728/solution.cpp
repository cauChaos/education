// code by wapas
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> arr;
    for (int i = 0; i < N + M; i++) { // N + M개의 원소를 하나의 배열에 삽입
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end()); // 배열을 정렬
    for (auto e : arr)
        cout << e << " "; // 정렬한 배열을 순차적으로 출력
}