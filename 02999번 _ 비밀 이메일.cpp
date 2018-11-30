#include <stdio.h>
#include <string.h>

int main()
{
	int r, c, len;
	char arr[101];

	scanf("%s", arr, 101);

	len = strlen(arr);

	for (int i = 10; i >= 1; i--)
	{
		if (len % i == 0 && i <= len / i)
		{
			r = i;
			c = len / r;
			break;
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < len; j += r)
		{
			printf("%c", arr[i + j]);
		}
	}
}
