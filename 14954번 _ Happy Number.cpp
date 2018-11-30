#include<stdio.h>

int f(int n);

int main()
{
	int s;
	
	scanf("%d",&s);
	
	for(int i=0;i<6;i++)
	{
		s=f(s);
	}
	if(s==1) printf("HAPPY");
	else printf("UNHAPPY");
}

int f(int n)
{
	int res=0;
	
	while(n!=0)
	{
		int p=n%10;
		n/=10;
		res+=p*p;
	}
	return res+n;
}
