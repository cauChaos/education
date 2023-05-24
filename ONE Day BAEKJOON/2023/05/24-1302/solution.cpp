// code by wapas
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<string> arr;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), [&](string a, string b) {
        int cnt_a = count(arr.begin(), arr.end(), a);
        int cnt_b = count(arr.begin(), arr.end(), b);
        if (cnt_a == cnt_b) return a < b;
        else return cnt_a > cnt_b;
    });
    cout << arr[0];
}
