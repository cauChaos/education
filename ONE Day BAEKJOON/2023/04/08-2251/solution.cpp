// code by wapas
#include <bits/stdc++.h>
#define F for (int i = 0; i < 1; i++)

using namespace std;

int encode(tuple<int, int, int> status)
{ // A, B, C에 담긴 물통 상태를 비트마스킹으로 상태값 저장
    auto [a, b, c] = status;
    return a << 16 | b << 8 | c;
}

tuple<int, int, int> decode(int bit)
{ // 비트마스킹한 값을 물통 상태로 복원
    int c = bit % (1 << 8);
    bit >>= 8;
    int b = bit % (1 << 8);
    bit >>= 8;
    int a = bit % (1 << 8);
    bit >>= 8;
    return { a, b, c };
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    set<int> ans, checkSet;
    queue<int> q;

    q.push(encode({ 0, 0, C }));
    checkSet.insert(encode({ 0, 0, C }));
    while (!q.empty()) { // BFS 코드
        int curr = q.front();
        q.pop();
        auto [a, b, c] = decode(curr);
        if (!a)
            ans.insert(c); // A에 든 물의 양이 0일 때 C에 든 물의 양을 정답에 넣음

        // 아래 코드는 물을 이동시키는 6가지 행동을 모두 시행하는 코드
        // a -> b
        F
        {
            int na = 0;
            int nb = b + a;
            if (nb > B) {
                na = nb - B;
                nb = B;
            }
            auto next = encode({ na, nb, c });
            if (checkSet.count(next))
                continue;
            checkSet.insert(next);
            q.push(next);
        }

        // b -> a
        F
        {
            int nb = 0;
            int na = a + b;
            if (na > A) {
                nb = na - A;
                na = A;
            }
            auto next = encode({ na, nb, c });
            if (checkSet.count(next))
                continue;
            checkSet.insert(next);
            q.push(next);
        }

        // a -> c
        F
        {
            int na = 0;
            int nc = c + a;
            if (nc > C) {
                na = nc - C;
                nc = C;
            }
            auto next = encode({ na, b, nc });
            if (checkSet.count(next))
                continue;
            checkSet.insert(next);
            q.push(next);
        }

        // c -> a
        F
        {
            int nc = 0;
            int na = a + c;
            if (na > A) {
                nc = na - A;
                na = A;
            }
            auto next = encode({ na, b, nc });
            if (checkSet.count(next))
                continue;
            checkSet.insert(next);
            q.push(next);
        }

        // b -> c
        F
        {
            int nb = 0;
            int nc = c + b;
            if (nc > C) {
                nb = nc - C;
                nc = C;
            }
            auto next = encode({ a, nb, nc });
            if (checkSet.count(next))
                continue;
            checkSet.insert(next);
            q.push(next);
        }

        // c -> b
        F
        {
            int nc = 0;
            int nb = b + c;
            if (nb > B) {
                nc = nb - B;
                nb = B;
            }
            auto next = encode({ a, nb, nc });
            if (checkSet.count(next))
                continue;
            checkSet.insert(next);
            q.push(next);
        }
    }

    for (auto e : ans)
        cout << e << " ";
}