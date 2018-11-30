#include <iostream>

int fi[50];

int fibo(int N)
{
	if (fi[N] > 0)
    {
		return fi[N];
	}
	if (N == 0)
    {
		return fi[0] = 0;
	}
	if (N == 1)
    {
		return fi[1] = 1;
	} 
	return fi[N] = fibo(N-1) + fibo(N-2);
}

int main()
{
	int N;
	scanf("%d", &N);
	fibo(N);
	printf("%d", fi[N]);
	return 0;
}
