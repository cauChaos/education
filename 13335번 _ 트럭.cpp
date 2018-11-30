#include <iostream>
#include <queue>

using namespace std;
 
int N, W, L;
 
int main()
{
    scanf("%d %d %d", &N, &W, &L);

    int cnt = 0, sum = 0, ans = 0;
    
	queue <int> que;
    
	for (int i = 1; i <= N; i++)
	{
        int w;
		
		scanf("%d", &w);
        
		while (1)
		{
            ans++;

            if (cnt == W) cnt--, sum -= que.front(), que.pop();
            
			if (sum + w > L) cnt++, que.push(0);
            else
			{
                cnt++, sum += w, que.push(w);
            
				break;
            }
        }
    }
    printf("%d\n", ans + W);
}
