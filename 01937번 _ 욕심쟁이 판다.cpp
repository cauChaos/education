#include <iostream>
#include <vector>
#include <algorithm>
typedef struct abc { int x, y, bam; }point;
std::vector<point> m;
std::vector<int> map[502];
int dp[502][502];

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i <= n + 1; i++)
		map[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		map[i].push_back(0);
		for (int j = 1; j <= n; j++) {
			point t = { i,j,0 };
			std::cin >> t.bam;
			m.push_back(t);
			map[i].push_back(t.bam);
		}
		map[i].push_back(0);
	}
	for (int i = 0; i <= n + 1; i++)
		map[n + 1].push_back(0);
	std::sort(m.begin(), m.end(), [](point t1, point t2) {return (t1.bam < t2.bam); });

	int res = 0;
	dp[m[0].x][m[0].y] = 1;
	for (int i = 1; i < m.size(); i++) {
		int x = m[i].x, y = m[i].y;
		int max = 1;
		if (max <= dp[x + 1][y] && map[x][y] > map[x + 1][y]) max = dp[x + 1][y] + 1;
		if (max <= dp[x - 1][y] && map[x][y] > map[x - 1][y]) max = dp[x - 1][y] + 1;
		if (max <= dp[x][y + 1] && map[x][y] > map[x][y + 1]) max = dp[x][y + 1] + 1;
		if (max <= dp[x][y - 1] && map[x][y] > map[x][y - 1]) max = dp[x][y - 1] + 1;
		dp[x][y] = max;
		if (res < max) res = max;
	}

	std::cout << res;
	return 0;
}
