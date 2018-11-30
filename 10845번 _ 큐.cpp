#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100000

int main()
{
    int imperative = 0, front = 0, back = 0, number = 0, times = 0;
    int queue[MAX_QUEUE_SIZE];
    char Order[10];
    
    scanf("%d", &imperative);
    
    for( times = 0 ; times < imperative ; times++ )
    {
        scanf("%s", Order);

        if(strcmp(Order, "push") == 0)
        {
            scanf("%d", &number);
            queue[back] = number;
            back++;
        }
        else if(strcmp(Order, "pop") == 0)
        {
            if(back == front) printf("-1\n");
            else printf("%d\n", queue[front++]);
        }
        else if(strcmp(Order, "size") == 0)
        {
            printf("%d\n", back-front);
        }
        else if(strcmp(Order, "empty") == 0)
        {
            if(back == front) printf("1\n");
            else printf("0\n");
        }
        else if(strcmp(Order, "front") == 0)
        {
            if(back == front) printf("-1\n");
            else printf("%d\n", queue[front]);
        }
        else if(strcmp(Order, "back") == 0)
        {
            if(back == front) printf("-1\n");
            else printf("%d\n", queue[back-1]);
        }
    }
}

by Junsuk Oh

----------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	int st[10100], front = 0, back = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c[6];
		scanf("%s", c);
		if (!strcmp(c, "push")) {
			int d;
			scanf("%d", &d);
			st[back++] = d;
		}
		if (!strcmp(c, "pop")) {
			if (front == back) printf("-1\n");
			else printf("%d\n", st[front++]);
		}
		if (!strcmp(c, "size")) {
			printf("%d\n", back - front);
		}
		if (!strcmp(c, "empty")) {
			if (front == back) printf("1\n");
			else printf("0\n");
		}
		if (!strcmp(c, "front")) {
			if (front == back) printf("-1\n");
			else printf("%d\n", st[front]);
		}
		if (!strcmp(c, "back")) {
			if (front == back) printf("-1\n");
			else printf("%d\n", st[back - 1]);
		}
	}
	return 0;
}

by Inseo Park
