#include <stdio.h>
#include <string.h>
char pika[5050];

int main()
{
    int i=0;
    scanf("%s",pika);
    
    for(i=0;i<strlen(pika);)
    {
        if(pika[i]=='p' && pika[i+1]=='i') i+=2;
        else if(pika[i]=='k' && pika[i+1]=='a') i+=2;
        else if(pika[i]=='c' && pika[i+1]=='h' && pika[i+2]=='u') i+=3;
        else break;
    }
    
    if(i == strlen(pika)) printf("YES");
    else printf("NO");
    return 0;
}
