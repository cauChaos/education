#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
 
using namespace std;
typedef long long ll;
 
deque<pair<int, int> > dq;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int val; cin >> val;
        dq.push_back(make_pair(i, val));
    }
 
    while (!dq.empty())
    {
        if (dq.size() == 1)
        {
            cout << dq.front().first;
            return 0;
        }
        int value = dq.front().second;
        cout << dq.front().first<<" ";
        dq.pop_front();
        if (value > 0)
        {
            for (int count = 0; count < value - 1 ; ++count)
            {
                int tidx, tval;
                tidx = dq.front().first;
                tval = dq.front().second;
                dq.pop_front();
                dq.push_back(make_pair(tidx, tval));
            }
        }
        else
        {
            value *= -1;
            for (int count = 0; count < value ; ++count)
            {
                int tidx, tval;
                tidx = dq.back().first;
                tval = dq.back().second;
                dq.pop_back();
                dq.push_front(make_pair(tidx, tval));
            }
        }
 
    }
}
