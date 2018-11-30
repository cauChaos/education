#include <stdio.h>

int main()
{
	int month, day;
	scanf("%d %d", &month, &day);
	int result = day;
	month--;
	for (; 0 < month; month--)
	{
		if (month == 2)
		{
			result += 28;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			result += 30;
		}
		else
		{
			result += 31;
		}
	}
	result = result % 7;
	switch (result)
	{
	case 0: printf("SUN"); break;
	case 1: printf("MON"); break;
	case 2: printf("TUE"); break;
	case 3: printf("WED"); break;
	case 4: printf("THU"); break;
	case 5: printf("FRI"); break;
	default: printf("SAT");
	}
	return 0;
}
