#include <cstdio>
#include <algorithm>
#include <cmath>

int k;
char arr[11];
bool visit[11];
long long minnum = 987654321987654321L;
long long maxnum = 0;

void dfs(int d, int now, long long num)
{
    if(d==k)
    {
        maxnum = std::max(maxnum,num);
        minnum = std::min(minnum,num);
        return;
    }
    
    if(arr[d]=='>')
    {
        for(int i=0;i<now;i++)
        {
            if(visit[i]) continue;
            visit[i]=true;
            dfs(d+1,i,num*10+i);
            visit[i]=false;
        }
    }
    else
    {
        for(int i=9;i>now;i--)
        {
            if(visit[i]) continue;
            visit[i]=true;
            dfs(d+1,i,num*10+i);
            visit[i]=false;
        }
    }
}

int main()
{
    scanf("%d",&k);
    for(int i=0;i<11;i++) visit[i]=false;
    for(int i=0;i<k;)
    {
        char ch;
        scanf("%c",&ch);
        if(ch=='<' || ch=='>')
        {
            arr[i]=ch;
            i++;
        }
    }
    
    for(int i=0;i<=9;i++)
    {
        visit[i]=true;
        dfs(0,i,i);
        visit[i]=false;
    }
    
    printf("%lld\n",maxnum);
    if(pow(10,k)>minnum) printf("0%lld\n",minnum);
    else printf("%lld\n",minnum);
    return 0;
}
