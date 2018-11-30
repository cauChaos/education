#include <stdio.h>

int main(void)
{
	char N[8];
	char nums[11] = { "0123456789" };
	int res[10] = { 0, };
    
	scanf("%s", &N);
    
	for (int i = 0; i < sizeof(N); i++) if (N[i] == '6') N[i] = '9';
    
	for (int i = 0; i < sizeof(N); i++)
	{
		for (int j = 0; j < 10; j++) if (N[i] == nums[j]) res[j] = res[j] + 1;
	}
    
	if (res[9] % 2 == 0) res[9] = res[9] / 2;
	else res[9] = res[9] / 2 + 1;
	
    int max = 0;
	
    for (int i = 0; i < 10; i++) if (max < res[i]) max = res[i];
	
    printf("%d\n", max);
	
    return 0;
}
