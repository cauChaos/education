// code by wapas
#include <bits/stdc++.h>

using namespace std;

map<string, double> table = { // 등급에 따른 과목평점 표
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double sumGR = 0, sumG = 0;
    for (int i = 0; i < 20; i++) {
        string subject, grade, rank;
        cin >> subject >> grade >> rank;
        if (rank == "P")
            continue; // 등급이 P인 과목은 계산에서 제외
        sumG += stod(grade); // 학점
        sumGR += stod(grade) * table[rank]; // 학점 × 과목평
    }
    if (!sumG)
        sumG = 1; // sumG가 0이면 divide by zero 에러를 피하기 위해 1로 강제로 변경
    cout << sumGR / sumG;
}