#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAX 1005
#define INF 987654321
#define MOD 1000000
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
 
int y,x,box[MAX][MAX];
bool tf[MAX][MAX];
 
int main()
{
    scanf("%d%d",&y,&x);
    
    for(int i=1;i<=y;i++)
        for(int j=1;j<=x;j++)
            scanf("%d",&box[i][j]);
    
    for(int i=1;i<=y;i++)
    {
        int mx=-1;
        pi p;
    
        for(int j=1;j<=x;j++)
            if(mx<box[i][j])
            {
                mx=box[i][j];
                p={i,j};
            }
        
        tf[p.first][p.second]=true;
    }
    
    for(int i=1;i<=x;i++)
    {
        int mx=-1;
        pi p;
        
        for(int j=1;j<=y;j++)
            if(mx<box[j][i])
            {
                mx=box[j][i];
                p={j,i};
            }
        
        tf[p.first][p.second]=true;
    }
    
    ll sum=0;
    
    for(int i=1;i<=y;i++)
        for(int j=1;j<=x;j++)
            if(!tf[i][j])
                sum+=(ll)box[i][j];
    
    printf("%lld",sum);
    
    return 0;
}
