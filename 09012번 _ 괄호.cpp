#include <stdio.h> 
#define MAX_SIZE 50

int main()
{
    int i, j, count, number;
    char array[MAX_SIZE];

    scanf("%d", &number);

    for ( i = 0 ; i < number ; i++ )
	{
        count = 0;
        scanf("%s", array);

        for ( j = 0 ; j < MAX_SIZE ; j++ )
		{
            if ( array[j] == '\0') break;

            if ( array[j] == '(') count++;

            else if ( array[j] == ')' && count > 0) count--;

            else if ( array[j] == ')' && count <= 0)
			{
                count--;
                break;
            }
        }
        if ( count == 0 ) printf("YES\n");
        else printf("NO\n");
    }
}

by Junsuk Oh

-------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		char c[60];
		int cnt = 0;
		int flag = 0;
		scanf("%s", c);
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] == '(') {
				cnt++;
			}
			if (c[i] == ')') {
				if (cnt == 0) flag = 1;
				else cnt--;
			}
			if (flag) break;
		}
		if (flag || cnt>0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

by Inseo Park
