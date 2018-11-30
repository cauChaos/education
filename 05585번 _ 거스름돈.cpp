#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <list>
using namespace std;

#define MAX 1000

int dp[MAX + 1];
int species[7] = {1, 5, 10, 50, 100, 500};

int main(void)
{
    int price, change;
    cin>>price;
    change = 1000 - price;
    
    dp[0] = 0;
    for(int i=1; i<=change; i++)
    {
        dp[i] = MAX;
        for(int j=0; j<6; j++)
        {
            if(species[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - species[j]]) + 1;
            }
        }
    }
    cout<<dp[change]<<endl;
    
    return 0;
}
