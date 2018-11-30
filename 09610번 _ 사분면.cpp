#include<stdio.h>

int n, q1, q2, q3, q4, ax;

int main()
{
	scanf("%d", &n);
	
    while (n--)
    {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!a || !b) ax++;
		else if (a > 0 && b > 0) q1++;
		else if (a < 0 && b>0) q2++;
		else if (a < 0 && b < 0) q3++;
		else if (a > 0 && b < 0) q4++;
	}
	printf("Q1: %d\n", q1);
	printf("Q2: %d\n", q2);
	printf("Q3: %d\n", q3);
	printf("Q4: %d\n", q4);
	printf("AXIS: %d\n", ax);
}
