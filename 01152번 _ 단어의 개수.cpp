#include <stdio.h>
#include <string.h>
 
int main()
{
    char str[1000001];
 
    gets(str);

    int len = strlen(str);
 
    int res = 0;
    
    for (int i = 0; i < len; i++)
    {
        while (i < len && str[i] == 32) i++;
 
        if (i < len && str[i] != 32)
        {
            res++;
            while (i < len && str[i] != 32) i++;
        }
    }
    printf("%d", res);
    
	return 0;
}

by Junsuk Oh
