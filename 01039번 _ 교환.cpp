#include <cstdio>
int num[11][1010101];

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    num[0][n]=1;
    
    for(int ki=1;ki<=k;ki++)
    {
        for(int ni=1;ni<=1000000;ni++)
        {
            if(num[ki-1][ni]==0) continue;
            for(int i=1;i<=ni;i*=10)
            {
                for(int j=1;j<=ni && j<i;j*=10)
                {
                    int imod = (ni/i)%10;
                    int jmod = (ni/j)%10;
                    int nmod = ni-(imod*i+jmod*j)+(imod*j+jmod*i);
                    if(nmod<i) continue;
                    num[ki][nmod] = 1;
                }
            }
        }
    }
    for(int ni=1000000;ni>=1;ni--)
    {
        if(num[k][ni]==1)
        {
            printf("%d",ni);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
