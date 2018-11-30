#include <cstdio>
#include <algorithm>
int dp[40001], a[40001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int cnt = 1;
	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		if (dp[cnt - 1] < a[i]) {
			dp[cnt] = a[i];
			cnt++;
		}
		else {
			int k = std::lower_bound(dp, dp + cnt, a[i]) - dp;
			dp[k] = a[i];
		}
	}
	printf("%d", cnt);
	return 0;
}
