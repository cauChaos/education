#include <stdio.h>

int main(void)
{
    int n;
    
    scanf("%d", &n);

    int temp;
 
    int in[1001];
 
    for (int i = 0; i < n; i++) 
        scanf("%d", &in[i]);
        
    for(int i=0;i<n-1;i++)
	  { 
        for (int j = i+1; j < n; j++)
		    {
            if (in[i] > in[j])
			      {
                temp = in[i];
                in[i] = in[j];
                in[j] = temp;
            }
        }
    }
 
    for (int i = 0; i < n; i++)
        printf("%d\n", in[i]); 
}

by Junsuk Oh
