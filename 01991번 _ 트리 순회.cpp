#include <iostream>
#include <algorithm>
using namespace std;

struct tree
{
	char left;
	char right;
};

tree trii[27];

int n;

void torder(char par, int num)
{
	if(num == 0) cout << par;
	if(trii[par - 'A'].left != '.') torder(trii[par - 'A'].left, num);
	
    if (num == 1) cout << par;
	if (trii[par - 'A'].right != '.') torder(trii[par - 'A'].right, num);
	
    if (num == 2) cout << par;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;

	char p, l, r;
    
	for (int i = 0; i < n; i++)
    {
		cin >> p >> l >> r;
		trii[p - 'A'].left = l;
		trii[p - 'A'].right = r;
	}

	for (int i = 0; i < 3; i++)
    {
		torder('A', i);
		cout << '\n';
	}

	return 0;
}
