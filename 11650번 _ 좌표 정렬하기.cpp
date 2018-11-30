#include <iostream>
#include <vector>
#include <algorithm>
using pair_int = std::pair<int, int>;
std::vector<pair_int> a;

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i<n; i++) {
		pair_int t;
		std::cin >> t.first >> t.second;
		a.push_back(t);
	}
	std::sort(a.begin(), a.end(), [](pair_int x, pair_int y)->bool {
		return (x.first == y.first ? x.second < y.second : x.first < y.first); });
	for (int i = 0; i<n; i++)
		std::cout << a[i].first << ' ' << a[i].second << '\n';
	return 0;
}
