#include <cstdio>
#include <algorithm>
int plum[1010], dp[32][1010];

int main()
{
	int t, w, tree = 1;
	scanf("%d %d", &t, &w);
	for (int i = 1; i <= t; i++)
		scanf("%d", &plum[i]);
	for (int i = 1; i <= w+1; i++) {
		for (int j = 1; j <= t; j++) {
			int count = 0;
			if (plum[j] == tree) count++;
			dp[i][j] = std::max(dp[i][j - 1] + count, dp[i - 1][j]);
		}
		if (i % 2) tree = 2;
		else tree = 1;
	}
	printf("%d", dp[w + 1][t]);
	return 0;
}
