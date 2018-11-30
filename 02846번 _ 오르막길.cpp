#include <stdio.h>

int n, array[1001], answer, nowi;

int main()
{
    scanf("%d", &n);
    
    scanf("%d", &array[0]);
    
    for (int i = 1; i < n; i++)
	{
        scanf("%d", &array[i]);

        if (array[i] <= array[i - 1]) nowi = i;
        else answer = answer > array[i] - array[nowi] ? answer : array[i] - array[nowi];
    }

    printf("%d", answer);
}
