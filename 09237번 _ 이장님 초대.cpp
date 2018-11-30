#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> pq;

int n,mx;

int main()
{
	scanf("%d", &n);
    
	for(int i=0; i<n; i++)
    {
		int a;
		scanf("%d", &a);
		pq.push(a);
	}
    
	for(int i=1; i<=n; i++)
    {
		if(pq.top()+i > mx) mx = pq.top() + i;
		pq.pop();
	}
	printf("%d\n", mx+1);
}
