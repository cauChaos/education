// code by wapas
#include <bits/stdc++.h>

using namespace std;

map<char, int> encode = {
    { '(', -2 },
    { '[', -3 }
}; // '('는 -2로 '['는 -3으로 변환
// 계산 과정에서 음수가 절대로 나올 수 없음을 이용한 트릭.
map<char, char> opposite = {
    { ')', '(' },
    { ']', '[' }
}; // '('는 ')'로, '['는 ']'로 변환

int solution(string S)
{
    vector<int> stk;
    for (auto e : S) {
        if (e == '(' || e == '[') { // 열린 괄호면
            stk.push_back(encode[e]); // 음수로 변환해서 스택에 넣는다.
            continue;
        }
        if (e == ')' || e == ']') { // 닫힌 괄호면
            int temp = 0;
            while (!stk.empty() && stk.back() > 0) { // 음수(열린 괄호)가 나올 때까지 스택을 pop한다.
                temp += stk.back(); // 그 과정에서 양수는 temp에다 더해준다.
                stk.pop_back();
            }
            if (stk.empty())
                return 0; // 스택이 비었다면 유효하지 않은 괄호 문자열이므로 0 리턴.
            if (encode[opposite[e]] != stk.back())
                return 0; // 괄호 모양이 다르다면 유효하지 않은 괄호 문자열이므로 0 리턴.
            if (!temp)
                temp = 1; // temp가 0 이라면 1로 변경
            temp *= stk.back() * -1; // 열린 괄호는 음수로 변환했으므로 절댓값을 temp에다 곱해준다.
            stk.pop_back(); // 열린 괄호는 pop하고
            stk.push_back(temp); // temp값은 다시 넣는다.
        }
    }
    if (count_if(stk.begin(), stk.end(), [](int x) { return x < 0; }) > 0)
        return 0; // 만약 열린 괄호(음수)가 남아 있다면 유효하지 않은 괄호 문자열이다.
    else
        return reduce(stk.begin(), stk.end(), 0); // 열린 괄호가 없다면 stk의 원소들의 합이 정답
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string S;
    cin >> S;
    cout << solution(S);
}