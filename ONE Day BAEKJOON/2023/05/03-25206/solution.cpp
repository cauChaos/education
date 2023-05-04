// code by smmaker118
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, double> mp = { // 성적 맵핑
        { "A+", 4.5 },
        { "A0", 4.0 },
        { "B+", 3.5 },
        { "B0", 3.0 },
        { "C+", 2.5 },
        { "C0", 2.0 },
        { "D+", 1.5 },
        { "D0", 1.0 },
        { "F", 0.0 }
    };
    double sa, sb;
    sa = sb = 0.0;
    for (int i = 20; i--;) { // 20번 반복하며 성적 확인
        string a, b, c;
        cin >> a >> b >> c;
        if (c == "P") // P면 패스
            continue;
        sa += stod(b);
        sb += stod(b) * mp[c];
    }
    cout << sb / sa;
}