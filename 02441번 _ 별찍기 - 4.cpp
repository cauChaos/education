#include <stdio.h>

int main()
{
	int number;
	scanf("%d", &number);
	int temp = number;
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < temp; k++)
		{
			printf("*");
		}
		temp--;
		printf("\n");
	}
	return 0;
}
