#include <cstdio>
#include <algorithm>
using namespace std;
long long order[2][2] = { {2,3},{1,4} }, r, c;

void turn_right()
{
	long long tmp[2][2];
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) tmp[i][j] = order[i][j];
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) tmp[i][j] = order[1 - j][i];
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) order[i][j] = tmp[1 - i][j];
}

void turn_left()
{
	long long tmp[2][2];
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) tmp[i][j] = order[i][j];
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) tmp[i][j] = order[j][1 - i];
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) order[i][j] = tmp[1 - i][j];
}

void go(long long n, long long m)
{
	if (n == 1) return;
	
    pair<long long, long long> add[5];
	
    for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++) 
			add[order[i][j]] = { (1 - i) * n / 2, j * n / 2 };
	
    if (m <= n*n / 4)
    {
		r += add[1].first, c += add[1].second;
		turn_right();
		go(n / 2, m);
	}
	else if (m <= n*n / 2)
    {
		r += add[2].first, c += add[2].second;
		go(n / 2, m - (n*n / 4));
	}
	else if (m <= n*n*3 / 4)
    {
		r += add[3].first, c += add[3].second;
		go(n / 2, m - (n*n / 2));
	}
	else
    {
		r += add[4].first, c += add[4].second;
		turn_left();
		go(n / 2, m - (n*n*3 / 4));
	}
}

int main()
{
	long long n, m; scanf("%lld%lld", &n, &m);
	go(n, m);
	printf("%lld %lld\n", c + 1, r + 1);
	return 0;
}
