#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000001

int i, j;
int M, N;
int P[MAXN];
long answer;

int main()
{
	for (i = 1; i < MAXN; i++) P[i] = i;

	for (i = 2; i < MAXN; i++)
	{
		if (P[i] == i)
		{
			for (j = i; j < MAXN; j += i)
			{
				P[j] = P[j] - (P[j] / i);
			}
		}
	}

	scanf("%d %d", &M, &N);

	answer = 0;

	for (i = M; i <= N; i++)
	{
		if (P[i] == i - 1) printf("%ld\n", P[i] + 1);
	}
}
