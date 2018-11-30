#include<stdio.h>

void Hanoi_tower_print(int n, char from, char temp, char to)
{
    if (n == 1)
        printf("%c %c\n", from, to);
    else
    {
        Hanoi_tower_print(n-1, from, to, temp);
        printf("%c %c\n", from, to);
        Hanoi_tower_print(n-1, temp, from, to);
    }
}

int main()
{
    int n, times = 1;
    
    scanf("%d", &n);
    
    for(int i=0 ; i<n ; i++)
        times *= 2;
    
    printf("%d\n", times - 1);
    Hanoi_tower_print(n, '1', '2', '3');
}

by Junsuk Oh
