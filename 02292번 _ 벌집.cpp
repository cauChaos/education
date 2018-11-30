#include <stdio.h> 

int main()
{
	int number, i = 0, start = 1, end = 1;
	scanf("%d", &number);

	while (1)
	{
		start += 6 * i;
		end += 6 * (i + 1);
		if (number == 1)
		{
			printf("%d", i + 1);
			break;
		}
		else if (start < number && number <= end)
		{
			printf("%d", i + 2);
			break;
		}
		i++;
	}
	return 0;
}
