// code by wapas
#include <bits/stdc++.h>

using namespace std;

const string vowel = "aeiou";
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L, C;
    cin >> L >> C;
    vector<char> arr(C); // 암호로 사용될 법한 문자의 종류는 C가지
    for (int i = 0; i < C; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end()); // 알파벳이 증가하는 순서로 배열

    vector<char> selected; // 현재 선택한 알파벳들
    auto print = [&]() { // 현재 선택한 알파벳들을 출력하는 함수
        for (auto e : selected)
            cout << e;
        cout << "\n";
    };
    auto isValidPassword = [&]() { // 선택한 알파벳 중에서 최소 한 개의 모음과 최소 두 개의 자음이 존재하는지 확인하는 함수
        int arr[2] = { 0, 0 };
        for (auto e : selected)
            arr[vowel.find(e) == string::npos]++;
        return arr[0] >= 1 && arr[1] >= 2;
    };
    function<void(int)> backtracking = [&](int prev) { // 백트래킹 함수
        if (selected.size() == L) { // 선택한 알파벳 개수가 L개라면 모음, 자음 조건에 따라 출력을 할지말지 결정하고 return
            if (isValidPassword())
                print();
            return;
        }
        for (int i = prev + 1; i < C; i++) { // 이전에 선택한 알파벳을 선택하면 안되므로 prev + 1부터 인덱스를 살펴봄
            selected.push_back(arr[i]); // arr[i]를 선택
            backtracking(i); // 인자로는 현재 선택한 알파벳 인덱스를 넣음
            selected.pop_back(); // arr[i]를 빼냄
        }
    };
    backtracking(-1); // 처음에 0번째 인덱스를 무조건 선택하게끔 -1로 인자로 넘김
}