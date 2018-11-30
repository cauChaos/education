#include <stdio.h>
#include <string.h>

char data[1000001];
int front = 0;
int end = -1;

void push(char temp)
{
	end++;
	data[end] = temp;
}
char pop()
{
	end--;
	return data[end + 1];
}

int isempty()
{
	if (end==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int len1, len2;
	char input[1000001];
	char bomb[37];
	int flag = 0;

	scanf("%s", &input);
	scanf("%s", &bomb);

	len1 = strlen(input);
	len2 = strlen(bomb);

	for (int i = 0; i < len1; i++)
	{
		push(input[i]);
		if (input[i] == bomb[len2 - 1])
		{
			flag = -1;
			for (int j = 1; j <len2; j++)
			{
				if (data[end-j] != bomb[len2-j-1])
				{
					flag = 1;
					break;
				}
			}
			if (flag == -1)
			{
				end = end - len2;
			}
		}	
	}
	if (isempty()==0)
	{
		for (int i = 0; i <= end; i++)
		{
			printf("%c", data[i]);
		}
	}
	else
	{
		printf("FRULA");
	}
}
