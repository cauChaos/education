// code by smmaker118
#include <bits/stdc++.h>
#define mid ((l + r) >> 1)

using namespace std;

int seg[400000];

int init(int l, int r, int node)
{ // seg initializer
    int a;
    if (l == r) {
        cin >> a;
        return seg[node] = a;
    }
    a = init(l, (l + r) / 2, node * 2);
    return seg[node] = min(a, init(mid + 1, r, node * 2 + 1));
}

int query(int l, int r, int node, int i, int j) // minimum query
{
    if (r < i || j < l)
        return 2e9; // out of range return INF
    if (i <= l && r <= j)
        return seg[node]; // in range
    return min(query(l, mid, node * 2, i, j), query(mid + 1, r, node * 2 + 1, i, j));
}

int update(int l, int r, int node, int i, int v) // seg update
{
    if (i < l || r < i)
        return seg[node]; // out of range
    if (l == r)
        return seg[node] = v; // leaf node
    return seg[node] = min(update(l, mid, node * 2, i, v), update(mid + 1, r, node * 2 + 1, i, v));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    init(1, n, 1); // seg initialize
    cin >> m;
    while (m--) {
        int op, b, c;
        cin >> op >> b >> c;
        if (op == 1)
            update(1, n, 1, b, c); // if op is 1 run update
        else
            cout << query(1, n, 1, b, c) << "\n"; // if op is 2 run query
    }
}
