#include <cstdio>
#include <vector>
using namespace std;
std::vector<int> adj[100][2];
int n;
bool visit[100];

int dfs(int start, int idx)
{
	int ret = 1;
	visit[start] = true;
	for(int i=0;i<adj[start][idx].size();i++)
	{
	    int temp = adj[start][idx][i];
		if(!visit[temp]) ret += dfs(temp, idx);
	}
	return ret;
}

bool solve(int start)
{
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<100;j++) visit[j]=0;
		if(dfs(start,i)>n/2+1) return true;
	}
	return false;
}

int main()
{
	int m;
	scanf("%d %d",&n,&m);
	while(m--){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a][0].push_back(b);
		adj[b][1].push_back(a);
	}
	int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		if( solve(i) ) ans++;
	}
	printf("%d",ans);
	return 0;
}
