#include <stdio.h> 

int main()
{
	int number1;
	scanf("%d", &number1);
	int temp = number1;

	int times = 0;
	do
	{
		times++;
		int ten = number1 / 10;
		int one = number1 - ((number1 / 10) * 10);
		int number2 = ten + one;
		number1 = (one * 10) + number2 - ((number2 / 10) * 10);
	} while (number1 != temp);

	printf("%d", times);
}
