#include<stdio.h>

int card[105], n, m, answer;

int main()
{
	scanf("%d %d", &n, &m);
    
	for (int i = 0; i < n; i++) scanf("%d", &card[i]);
    
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
		        if (i != j  && j!=k && i != k)
                {
			        int t = card[i] + card[j] + card[k];
			        if (t <= m && t > answer) answer = t;
                }
            }
        }
	}
	printf("%d", answer);
}
