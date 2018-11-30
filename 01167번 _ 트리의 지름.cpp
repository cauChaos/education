#include <stdio.h>
#include <algorithm>
#include <vector>
#define X first
#define Y second

using namespace std;

typedef pair<int, int> PAIR;
int V;
int d = 0;
vector<PAIR> edge[100003];
bool isVisited[100003];

int longest_child(int root)
{
	int mx1 = 0;
	int mx2 = 0;
	for (auto child : edge[root])
    {
		if (isVisited[child.X])
			continue;
		isVisited[child.X] = true;
		int dist = longest_child(child.X) + child.Y;
		if (dist > mx1)
        {
			mx2 = mx1;
			mx1 = dist;
		}
		else if (dist > mx2)
        {
			mx2 = dist;
		}
	}
	d = max(d, mx1 + mx2);
	return mx1;
}
int main(void)
{
	scanf("%d", &V);
	for (int i = 0; i < V; i++)
    {
		int v;
		scanf("%d", &v);
		while (true)
        {
			int a;
			scanf("%d", &a);
			if (a == -1)
				break;
			else
            {
				int b;
				scanf("%d", &b);
				edge[v].push_back({ a,b });
			}
		}
	}
	isVisited[1] = true;
	longest_child(1);
	printf("%d", d);
}
