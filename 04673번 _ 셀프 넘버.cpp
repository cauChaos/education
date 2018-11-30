#include <stdio.h>
#define N 10000

void Constructor(int n)
{
  int su = n;

	while (n != 0)
  {
		su += n % 10;
		n /= 10;
	}
	con[su] = 1;
}

int con[N] = { 0 };

int main(void)
{
	int n;

	for (int i = 0; i < N; i++) Constructor(i+1);
	for (int j = 1; j < N; j++)
  {
		if (con[j] == 0) printf("%d\n", j);
	}
}

by Junsuk Oh
