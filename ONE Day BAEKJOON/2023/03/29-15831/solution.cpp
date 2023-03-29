// code by wapas
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, B, W;
    cin >> N >> B >> W;
    string S;
    cin >> S;

    if (B >= count(S.begin(), S.end(), 'B')) { // 검은 조약돌 개수가 B보다 작거나 같을 때
        if (W <= count(S.begin(), S.end(), 'W'))
            cout << N; // 하얀 조약돌 개수가 W보다 크거나 같으면 1~N 전체 구간이 가능하므로 N 출력
        else
            cout << 0; // 작으면 만족하는 구간이 존재하지 않으므로 0 출력
        return 0;
    }

    vector<int> linkedList; // 검은 조약돌의 위치(Index)를 담는 배열 = 연결 리스트
    linkedList.push_back(-1); // 가장 왼쪽은 -1로 둠
    for (int i = 0; i < N; i++)
        if (S[i] == 'B')
            linkedList.push_back(i);
    linkedList.push_back(N); // 가장 오른쪽은 1로 둠

    vector<int> prefixSum(N + 1, 0); // 특정 구간의 하얀 조약돌 개수를 구하기 위해 누적합 배열 생성
    for (int i = 1; i <= N; i++)
        if (S[i - 1] == 'W')
            prefixSum[i] = 1;
    for (int i = 0; i < N; i++)
        prefixSum[i + 1] += prefixSum[i];

    int ans = 0;
    int l = 1, r = B; // 연결리스트에서 슬라이딩 윈도우를 진행
    while (r < linkedList.size() - 1) { // 슬라이딩 윈도우의 오른쪽이 연결리스트의 끝까지 도달할 때까지 반복문 진행
        int leftCount = linkedList[l] - linkedList[l - 1] - 1; // 슬라이딩 윈도우의 왼쪽 구간부터 처음으로 나오는 검은 조약돌 직후 구간의 하얀 조약돌 개수
        int middleCount = prefixSum[linkedList[r] + 1] - prefixSum[linkedList[l]]; // 슬라이딩 윈도우 내부의 하얀 조약돌 개수
        int rightCount = linkedList[r + 1] - linkedList[r] - 1; // 슬라이딩 윈도우의 오른쪽 구간부터 처음으로 나오는 검은 조약돌 직전 구간의 하얀 조약돌 개수
        int total = leftCount + middleCount + rightCount; // 총 하얀 조약돌의 개수
        if (total >= W)
            ans = max(linkedList[r + 1] - linkedList[l - 1] - 1, ans); // 현재 보고 있는 구간에서 하얀 조약돌의 개수가 W 이상이면 답의 최댓값을 갱신
        l++;
        r++; // 슬라이딩 윈도우 이동
    }
    cout << ans;
}