#include <iostream>
#include <queue>
typedef std::pair<int, int> pair_int;
std::queue<pair_int> q;
bool visit[200001];

int main()
{
	int s, e;
	std::cin >> s >> e;
	if (s < e) {
		q.push(pair_int(s, 0));
		while (q.front().first != e) {
			pair_int tq = q.front();
			if (tq.first < e && !visit[tq.first * 2])
				q.push(pair_int(tq.first * 2, tq.second + 1)), visit[tq.first * 2] = true;
			if (tq.first < e && !visit[tq.first + 1])
				q.push(pair_int(tq.first + 1, tq.second + 1)), visit[tq.first + 1] = true;
			if (tq.first > 0 && !visit[tq.first - 1])
				q.push(pair_int(tq.first - 1, tq.second + 1)), visit[tq.first - 1] = true;
			q.pop();
		}

		std::cout << q.front().second;
	}
	else std::cout << s - e;
	return 0;
}
