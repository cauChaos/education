#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n, a[26];
string k, answer = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	while (n--)
	{
		cin >> k;
		a[k[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) if (a[i] >= 5) answer += (i + 'a');
	
	cout << (answer == "" ? "PREDAJA" : answer);
}
