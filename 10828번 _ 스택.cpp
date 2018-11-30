#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

typedef struct
{
    int stack[MAX_STACK_SIZE];
    int top;
}Stacks;

void initialization(Stacks *s)
{
    s->top = -1;
}

int empty(Stacks *s)
{
    if (s->top == -1) return 1;
    else return 0;
}

int size(Stacks *s)
{
    if (empty(s)) return 0;
    return ((s->top) + 1);
}

void push(Stacks *s, int element)
{
    if ((s->top) == MAX_STACK_SIZE-1) return;
    else s->stack[++(s->top)] = element;
}

int pop(Stacks *s)
{
    if (empty(s)) return -1;
    else return s->stack[(s->top)--];
}

int top(Stacks *s)
{
    if (empty(s)) return -1;
    else return s->stack[s->top];
}

int main()
{
    int times, i, element;
    char c[6];
    Stacks stack;
    initialization(&stack);
    
    scanf("%d", &times);
    
    if( times >= 1 && times <= 10000 )
    {
        for ( i = 0 ; i < times ; i++ )
        {
            scanf("%s", &c);
            
            if (strcmp(c, "push") == 0)
            {
                scanf("%d", &element);
                push(&stack, element);
            }
            if (strcmp(c, "pop") == 0)
            {
                printf("%d\n", pop(&stack));
            }
            if (strcmp(c, "top") == 0)
            {
                printf("%d\n", top(&stack));
            }
            if (strcmp(c, "size") == 0)
            {
                printf("%d\n", size(&stack));
            }
            if (strcmp(c, "empty") == 0)
            {
                printf("%d\n", empty(&stack));
            }
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
	int st[10100], size=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c[6];
		scanf("%s", c);
		if (!strcmp(c, "push")) {
			int d;
			scanf("%d", &d);
			st[size++] = d;
		}
		if (!strcmp(c, "pop")) {
			if (size == 0) printf("-1\n");
			else printf("%d\n", st[--size]);
		}
		if (!strcmp(c, "size")) {
			printf("%d\n", size);
		}
		if (!strcmp(c, "empty")) {
			if (size == 0) printf("1\n");
			else printf("0\n");
		}
		if (!strcmp(c, "top")) {
			if (size == 0) printf("-1\n");
			else printf("%d\n", st[size - 1]);
		}
	}
	return 0;
}

by Inseo Park
