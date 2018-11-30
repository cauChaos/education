#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int t, n, m, order;
	scanf("%d", &t);
	while (t--)
	{	
		priority_queue<int> pq;
		queue<pair<int,int>> q;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
		{
            		scanf("%d", &order);
			pq.push({ order });
			q.push({ order, i });
		}
		n = 0;
		while(1)
        	{
			if (q.front().first == pq.top())
			{				
				n++;
				if (q.front().second == m)
				{
					printf("%d\n", n);
					break;
				}
				pq.pop();
				q.pop();
			}
			else
            		{
				q.push(q.front());
				q.pop();
			}
		}
	}
}

by Junsuk Oh
