#include <stdio.h>
 
int main(void)
{ 
    int m, n;
    scanf("%d %d", &m, &n);
 
    int sum = 0;
    int min = 0;
    
    for (int i = m; i <= n; i++)
    {
        for (int j = 1; j <= i ; j++)
        {
            if (i == j*j)
            {
                sum += i;
                if (min == 0) min = i;
                else if (min > i) min = i;
            }
        }
    }
 
    if (sum == 0) printf("%d", -1);
    else printf("%d\n%d", sum, min);
}
