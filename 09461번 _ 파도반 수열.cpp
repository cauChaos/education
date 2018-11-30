#include <cstdio>

int main()
{
    long long int a[101]={0,};
    int t;
    scanf("%d",&t);
    
    a[1]=1,a[2]=1;
    a[3]=1,a[4]=2;
    for(int i=5;i<=100;i++)
    {
        a[i]=a[i-1]+a[i-5];
    }
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
