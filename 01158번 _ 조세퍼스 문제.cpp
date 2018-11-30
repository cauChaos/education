#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n = 0, m = 0, i = 0, j = 0;
	
	queue<int> q;
	
	cin >> n >> m;
	
	for ( i = 1 ; i <= n ; i++ )
	{
		q.push(i);
	}
	
	printf("<");
	
	for ( i = 0 ; i < n-1 ; i++ )
	{
		for ( j = 0 ; j < m-1 ; j++ )
		{
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>", q.front());
}

by Junsuk Oh
