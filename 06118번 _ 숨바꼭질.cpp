#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m, from, to, vis[20001], ans_n, ans_dis, ans_cnt;

vector<int> v[20001];

priority_queue<pii> q;

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &from, &to);

		v[from].push_back(to);
		v[to].push_back(from);
	}

	q.push(pii(0, 1));
	vis[1] = 1;

	while (!q.empty())
	{
		int curr = q.top().second;
		int cdis = -q.top().first;

		if (cdis > ans_dis)
		{
			ans_n = curr;
			ans_dis = cdis;
			ans_cnt = 1;
		}
		else if (cdis == ans_dis)
		{
			if (curr < ans_n) ans_n = curr;
			ans_cnt++;
		}
		q.pop();

		for (auto next : v[curr])
		{
			int ndis = cdis + 1;

			if (vis[next]) continue;
			vis[next] = 1;
			q.push(pii(-ndis, next));
		}
	}

	printf("%d %d %d", ans_n, ans_dis, ans_cnt);
}
