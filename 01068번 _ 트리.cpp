#include <iostream>
#include <algorithm>

using namespace std;

int n, p, er, res;
int graph[51][51];
int parent[51];
int root;

void dfs(int val)
{
	bool leaf = true;
	for (int i = 0; i < n; i++)
    {
		if (graph[val][i])
        {
			dfs(i);
			leaf = false;
		}
	}
	if (leaf) res++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
    
	for (int i = 0; i < n; i++)
    {
		cin >> p;
		if (p == -1)
        {
			root = i;
			continue;
		}
		graph[p][i] = 1;
		parent[i] = p;
	}

	cin >> er;
    
	if (root == er) res = 0;
	else
    {
		graph[parent[er]][er] = 0;
		dfs(root);
	}

	cout << res << '\n';

	return 0;
}
